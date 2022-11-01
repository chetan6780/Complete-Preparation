```json
[
    {
        "key": "alt+w",
        "command": "extension.liveServer.goOnline",
        "when": "editorTextFocus"
    },
    {
        "key": "alt+l alt+o",
        "command": "-extension.liveServer.goOnline",
        "when": "editorTextFocus"
    },
    {
        "key": "ctrl+d",
        "command": "editor.action.copyLinesDownAction",
        "when": "editorTextFocus && !editorReadonly"
    },
    {
        "key": "shift+alt+down",
        "command": "-editor.action.copyLinesDownAction",
        "when": "editorTextFocus && !editorReadonly"
    },
    {
        "key": "ctrl+t",
        "command": "workbench.action.terminal.new"
    },
    {
        "key": "ctrl+shift+oem_3",
        "command": "-workbench.action.terminal.new"
    },
    {
        "key": "ctrl+shift+a",
        "command": "code-runner.run"
    },
    {
        "key": "ctrl+alt+n",
        "command": "-code-runner.run"
    },
    {
        "key": "alt+x",
        "command": "extension.liveServer.goOffline",
        "when": "editorTextFocus"
    },
    {
        "key": "alt+l alt+c",
        "command": "-extension.liveServer.goOffline",
        "when": "editorTextFocus"
    },
    {
        "key": "ctrl+k ctrl+z",
        "command": "workbench.action.toggleZenMode"
    },
    {
        "key": "ctrl+k z",
        "command": "-workbench.action.toggleZenMode"
    },
    {
        "key": "ctrl+k",
        "command": "markdown-preview-enhanced.openPreviewToTheSide",
        "when": "editorLangId == 'markdown'"
    },
    {
        "key": "ctrl+k v",
        "command": "-markdown-preview-enhanced.openPreviewToTheSide",
        "when": "editorLangId == 'markdown'"
    },
    {
        "key": "ctrl+alt+n",
        "command": "workbench.action.files.newUntitledFile"
    },
    {
        "key": "ctrl+n",
        "command": "-workbench.action.files.newUntitledFile"
    },
    {
        "key": "ctrl+n",
        "command": "welcome.showNewFileEntries"
    },
    {
        "key": "ctrl+alt+win+n",
        "command": "-welcome.showNewFileEntries"
    },
    {
        "key": "ctrl+l ctrl+0",
        "command": "editor.foldAll",
        "when": "editorTextFocus && foldingEnabled"
    },
    {
        "key": "ctrl+k ctrl+0",
        "command": "-editor.foldAll",
        "when": "editorTextFocus && foldingEnabled"
    },
    {
        "key": "ctrl+l ctrl+j",
        "command": "editor.unfoldAll",
        "when": "editorTextFocus && foldingEnabled"
    },
    {
        "key": "ctrl+k ctrl+j",
        "command": "-editor.unfoldAll",
        "when": "editorTextFocus && foldingEnabled"
    }
]
```
