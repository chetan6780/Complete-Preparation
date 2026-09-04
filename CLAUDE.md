# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A documentation repo, not an application. It contains DSA / interview-prep notes — problem write-ups with explanations and C++ solutions embedded in markdown. There is no build, no test suite, and no package manager. The C++ inside the `.md` files is never compiled by any tooling; it is read by humans.

## Publishing

The repo is published as a GitBook at https://chetan6780.gitbook.io/complete-preparation via GitHub sync on `master`. [.gitbook.yml](.gitbook.yml) sets the repo root as the content root, [README.md](README.md) as the landing page, and [SUMMARY.md](SUMMARY.md) as the entire navigation tree.

**A page that is not listed in SUMMARY.md does not appear on the site.** This is the single most important invariant in the repo. A relative link to an unlisted file does not 404 — GitBook silently rewrites it to point at the source file on GitHub, so the link looks fine in the repo and dumps readers out of the book.

[\_config.yml](_config.yml) (`theme: jekyll-theme-modernist`) is a leftover GitHub Pages config and is unrelated to the GitBook deploy.

## The index chain — update all levels when adding a page

Every new solution file must be linked from:

1. The section index (e.g. [Leetcode/1500-1599.md](Leetcode/1500-1599.md), [Topic-Wise/README.md](Topic-Wise/README.md)) — the range/topic file, which repeats a condensed version of each approach. Hand-written.
2. [SUMMARY.md](SUMMARY.md) — root nav. Generated; see below.

All links are relative paths (`./Leetcode/...`), because GitBook resolves them from the repo root.

### SUMMARY.md is maintained by a script

Run [update_summary.py](update_summary.py) after adding or renaming files, and commit the result:

```bash
python3 update_summary.py            # fill in what is missing
python3 update_summary.py --check    # exit 1 if out of date
python3 update_summary.py --selftest # assert-based check of the parsing logic
```

It appends missing entries in place rather than regenerating the file, because the ordering in several sections (OOPs, CS-fundamentals, the `Day - N` groups) is hand-curated and a tree walk would destroy it. It also repairs links whose target moved or was misspelled, and prints anything it cannot resolve.

Its output matches format-on-save exactly (Prettier 3 at `tabWidth: 4` — bullet `- `, 4 spaces per level), so running the script and saving the file are both no-ops. Prettier 2 wrote `-   ` instead and will churn the whole file if a contributor uses it; the script still reads both styles but only emits the Prettier 3 one.

Entries it cannot resolve are links to pages that were never written — currently five under [SDE-Sheet/](SDE-Sheet/) (DAY_6, DAY_7, DAY_10). Those are placeholders, not bugs in the script.

Titles come from the target file's first heading, so a page with no heading, or a wrong one, produces a wrong nav label.

## Leetcode folder layout is mid-migration

Ranges are flat files (`Leetcode/1500-1599.md`) with solution files as siblings (`Leetcode/1535_....md`), **except** [Leetcode/2200-2299/](Leetcode/2200-2299/), which was an experiment in using a directory with an inner `README.md` as a GitBook nav group. Follow whichever pattern the surrounding range already uses; do not convert existing ranges without being asked.

## Solution file format

See [Leetcode/1535_findTheWinnerOfAnArrayGame.md](Leetcode/1535_findTheWinnerOfAnArrayGame.md) as the canonical example:

- `# [<number>. <Title>](<leetcode url>) 🌟` — difficulty as star count (🌟 easy, 🌟🌟 medium, 🌟🌟🌟 hard).
- Problem statement as plain prose.
- One `### <Approach name>` section per approach, brute force first, then optimizations. Bullet points, ending in `**TC:**` and `**SC:**` lines.
- `### Code` with a single ` ```cpp ` block containing the LeetCode `class Solution` verbatim.
- `---` between problems in the range index files.
- Include credit links when an approach comes from elsewhere.

File naming: `<number>_<camelCaseProblemName>.md`.

## Local C++ scratchpad

[arena/](arena/) and [test.cpp](test.cpp) are throwaway workspaces for trying a solution before writing it up. `arena/` is gitignored; `test.cpp` is tracked but its contents are meaningless churn.

Solutions use `#include <bits/stdc++.h>`, which Apple's clang does not ship. macOS `g++` is aliased to clang, so it will not work. Use Homebrew GCC:

```bash
g++-16 -std=c++20 test.cpp -o /tmp/a && /tmp/a
```

[.vscode/c_cpp_properties.json](.vscode/c_cpp_properties.json) points IntelliSense at the same `/opt/homebrew/bin/g++-16`.

## Conventions from CONTRIBUTING.md

- Don't rearrange existing folders or files; add new ones.
- Markdown and code are Prettier-formatted (4-space indent, `-   ` list markers).
- Commit messages: present tense, imperative, ≤72 chars, optionally prefixed with an emoji (🎨 new file, ✨/🚀 update, 📘 docs, 🔥 delete, ✅ complete).
