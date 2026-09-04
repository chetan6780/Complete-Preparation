#!/usr/bin/env python3
"""Fill gaps in SUMMARY.md so every tracked .md file appears in the GitBook nav.

GitBook only imports pages listed in SUMMARY.md; a relative link to an unlisted
file gets rewritten to point at GitHub instead. This walks the tracked markdown
files and inserts any that are missing, in place, without reordering entries
that are already there (the ordering in several sections is hand-curated).

Idempotent: re-run after adding files, commit the diff.

    python3 update_summary.py [--check]

--check exits 1 if SUMMARY.md would change, for use as a pre-commit guard.
"""

import re
from difflib import get_close_matches
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).parent
SUMMARY = ROOT / "SUMMARY.md"
INDENT = "    "
# Emission has to match what format-on-save produces, or every save fights this
# script: Prettier 3 at tabWidth 4 (`prettier.tabWidth` in the user settings).
# Prettier 2 wrote `-   `, so entries in either style are still read.
BULLET = "- "
SKIP_TOPLEVEL = {"README.md", "SUMMARY.md", "CONTRIBUTING.md", "CLAUDE.md"}

ENTRY = re.compile(r"^( *)-\s+(.*)$")
LINK = re.compile(r"\[(.*)\]\((\./[^)]+)\)\s*(.*)$")
HEADING = re.compile(r"^#{1,6}\s+(.+)")
# Titles carry difficulty as trailing stars; the existing file keeps them
# outside the link, so they are split off and re-appended as a suffix.
STARS = re.compile(r"[\U0001F31F\s]+$")


def tracked_md():
    out = subprocess.run(
        ["git", "ls-files", "*.md"], cwd=ROOT, capture_output=True, text=True, check=True
    ).stdout.split()
    return [p for p in out if "/" in p or p not in SKIP_TOPLEVEL]


def natural(name):
    """Sort 1_x before 10_x before 100_x, and Day_2 before Day_10."""
    return [int(t) if t.isdigit() else t.lower() for t in re.split(r"(\d+)", name)]


def title_of(relpath):
    """First heading of the file, stripped of link syntax; stars split off."""
    path = ROOT / relpath
    text = ""
    try:
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            m = HEADING.match(line.strip())
            if m:
                text = m.group(1).strip()
                break
    except OSError:
        pass
    if not text:
        text = path.stem.replace("_", " ").replace("-", " ").strip()
    # `# [1535. Title](https://leetcode.com/...) 🌟🌟` -> `1535. Title` + ` 🌟🌟`
    inner = re.match(r"^\[(.+?)\]\([^)]*\)\s*(.*)$", text)
    trailing = ""
    if inner:
        text, trailing = inner.group(1).strip(), inner.group(2).strip()
    stars = STARS.search(text)
    if stars and "\U0001f31f" in stars.group():
        trailing = (stars.group().strip() + " " + trailing).strip()
        text = text[: stars.start()].strip()
    text = text.replace("[", "").replace("]", "")
    return text, (" " + trailing if trailing else "")


def parse(lines):
    """-> list of (line_index, indent_level, linked_path or None)."""
    entries = []
    for i, line in enumerate(lines):
        m = ENTRY.match(line)
        if not m:
            continue
        level = len(m.group(1)) // len(INDENT)
        link = LINK.match(m.group(2).strip())
        entries.append((i, level, link.group(2)[2:] if link else None))
    return entries


def scopes(entries):
    """pos -> directory the entry groups, or None if it is a leaf page.

    A head either links to `dir/README.md`, links to a bare `dir/`, or is an
    unlinked label (the `Day - 1 (Array-I)` style) whose scope has to come from
    its direct children. Resolved bottom-up, because a label's children may be
    group heads themselves -- `6 Companies 30 Days` scopes to `6Companies30Days`
    even though its only child is the `6Companies30Days/Microsoft` group.
    """
    out = {}
    for pos in range(len(entries) - 1, -1, -1):
        _, level, path = entries[pos]
        if path:
            if path.endswith("/README.md"):
                out[pos] = path[: -len("/README.md")]
            elif (ROOT / path).is_dir():
                out[pos] = path.rstrip("/")
            else:
                out[pos] = None
            continue
        dirs = set()
        for j in range(pos + 1, len(entries)):
            if entries[j][1] <= level:
                break
            if entries[j][1] != level + 1:
                continue  # direct children only
            child = out.get(j) or entries[j][2]
            if child:
                dirs.add(str(Path(child).parent))
        out[pos] = dirs.pop() if len(dirs) == 1 else None
    return out


def repair_links(lines):
    """Retarget links whose file does not exist; return the ones left broken.

    These render as GitHub redirects too, and they hide real files from the
    walk below by making them look already-listed.
    """
    by_name = {}
    for p in tracked_md():
        by_name.setdefault(Path(p).name, []).append(p)
    broken = []
    for i, line in enumerate(lines):
        m = ENTRY.match(line)
        if not m:
            continue
        link = LINK.match(m.group(2).strip())
        if not link or (ROOT / link.group(2)[2:]).exists():
            continue
        target = Path(link.group(2)[2:])
        found = by_name.get(target.name, [])
        if len(found) != 1:
            # not a move, so try a typo: a near-identical name in the same folder
            siblings = [p for p in tracked_md() if str(Path(p).parent) == str(target.parent)]
            near = get_close_matches(target.name, [Path(p).name for p in siblings], 1, 0.85)
            found = [f"{target.parent}/{near[0]}"] if near else []
        if len(found) == 1:
            lines[i] = line.replace(link.group(2), f"./{found[0]}")
        else:
            broken.append(link.group(2))
    return broken


def end_of_group(entries, pos):
    """Line index just past the last child of entries[pos]."""
    _, level, _ = entries[pos]
    last = entries[pos][0]
    for idx, lvl, _ in entries[pos + 1 :]:
        if lvl <= level:
            break
        last = idx
    return last + 1


def child_lines(files, level, skip=None):
    out = []
    for p in sorted(files, key=natural):
        if p == skip:
            continue
        title, suffix = title_of(p)
        out.append(f"{INDENT * level}{BULLET}[{title}](./{p}){suffix}")
    return out


def splice(lines, at, block):
    """Insert block at `at`, keeping the blank line the format puts between groups."""
    if at < len(lines) and lines[at].strip():
        block = block + [""]
    lines[at:at] = block


def insert_files(lines, entries, heads, directory, by_dir):
    """Append a directory's unlisted files to the group that already covers it."""
    files = by_dir[directory]
    if directory == ".":
        block = child_lines(files, 0)
        lines.extend([""] + block)
        return
    head = heads[directory]
    level = entries[head][1]
    at = end_of_group(entries, head)
    block = child_lines(files, level + 1, skip=f"{directory}/README.md")
    if not block:
        return
    if at == entries[head][0] + 1:  # head has no children yet
        block.insert(0, "")
    splice(lines, at, block)


def create_group(lines, entries, heads, directory, by_dir):
    """Add a head (and its files) for a directory nothing links to yet."""
    parent = str(Path(directory).parent)
    if parent in heads:
        level = entries[heads[parent]][1] + 1
        at = end_of_group(entries, heads[parent])
    else:
        level, at = 0, len(lines)

    readme = f"{directory}/README.md"
    has_readme = (ROOT / readme).is_file()
    label, _ = title_of(readme if has_readme else directory)
    prefix = INDENT * level + BULLET
    head = f"{prefix}[{label}](./{readme})" if has_readme else f"{prefix}{label}"

    block = ["", head, ""] + child_lines(by_dir[directory], level + 1, skip=readme)
    splice(lines, at, block)


def selftest():
    assert natural("Day_2") < natural("Day_10") < natural("Day_100")
    assert natural("1_a.md") < natural("11_a.md") < natural("100_a.md")

    # a label whose only child is itself a group head scopes to the parent dir
    entries = [(0, 0, None), (1, 1, "6Companies30Days/Microsoft/README.md")]
    assert scopes(entries) == {0: "6Companies30Days", 1: "6Companies30Days/Microsoft"}

    # a label whose children are leaf pages scopes to the directory holding them
    entries = [(0, 1, None), (1, 2, "75-days-dsa-challenge/Day_1/1_twoSum.md")]
    assert scopes(entries)[0] == "75-days-dsa-challenge/Day_1"

    # children in two different directories are ambiguous, so no scope
    entries = [(0, 0, None), (1, 1, "a/x.md"), (2, 1, "b/y.md")]
    assert scopes(entries)[0] is None

    # a leaf page is not a group
    assert scopes([(0, 0, "Leetcode/1_twoSum.md")]) == {0: None}

    # stars belong outside the link, and the heading's own link is unwrapped
    title, suffix = title_of("Leetcode/1535_findTheWinnerOfAnArrayGame.md")
    assert title == "1535. Find the Winner of an Array Game", title
    assert suffix == " \U0001f31f\U0001f31f", repr(suffix)

    print("selftest ok")
    return 0


def main():
    if "--selftest" in sys.argv:
        return selftest()
    lines = SUMMARY.read_text(encoding="utf-8").splitlines()

    # Pass 0: fix links that point at files which no longer exist.
    broken = repair_links(lines)

    entries = parse(lines)
    scope_by_pos = scopes(entries)

    # Pass 1: point directory links and unlinked labels at their README, so the
    # group head is a real GitBook page instead of a dead link or plain text.
    for pos, (i, level, path) in enumerate(entries):
        scope = scope_by_pos[pos]
        if not scope or not (ROOT / scope / "README.md").is_file():
            continue
        target = f"./{scope}/README.md"
        m = ENTRY.match(lines[i])
        body = m.group(2).strip()
        link = LINK.match(body)
        if link and link.group(2) == target:
            continue
        label = link.group(1) if link else body
        suffix = f" {link.group(3)}".rstrip() if link and link.group(3) else ""
        lines[i] = f"{m.group(1)}{BULLET}[{label}]({target}){suffix}"

    # Pass 2: place every unlisted file. Directories that have no group yet get
    # one created first, shallowest first, so a new group lands inside its
    # parent's group rather than at the end of the file.
    for _ in range(2000):  # bounded: each round places at least one directory
        entries = parse(lines)
        by_pos = scopes(entries)
        heads = {}
        for pos in sorted(by_pos):  # first entry in document order wins
            if by_pos[pos] is not None:
                heads.setdefault(by_pos[pos], pos)

        listed = {p for _, _, p in entries if p}
        by_dir = {}
        for p in tracked_md():
            if p not in listed:
                by_dir.setdefault(str(Path(p).parent), []).append(p)
        if not by_dir:
            break

        ready = [d for d in by_dir if d in heads or d == "."]
        if ready:
            insert_files(lines, entries, heads, max(ready, key=natural), by_dir)
            continue

        creatable = [d for d in by_dir if str(Path(d).parent) in heads or "/" not in d]
        if not creatable:
            break  # nothing left that can be attached anywhere
        deepest_first = min(creatable, key=lambda d: (d.count("/"), natural(d)))
        create_group(lines, entries, heads, deepest_first, by_dir)

    out = "\n".join(lines).rstrip() + "\n"
    if "--check" in sys.argv:
        if out != SUMMARY.read_text(encoding="utf-8"):
            print("SUMMARY.md is out of date; run: python3 update_summary.py")
            return 1
        return 0
    SUMMARY.write_text(out, encoding="utf-8")
    print(f"SUMMARY.md: {len(parse(lines))} entries")
    for target in broken:
        print(f"  still broken (no unique match): {target}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
