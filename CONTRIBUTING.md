# Contributing to Complete-Preparation

👍🎉 First off, thanks for taking the time to contribute! 🎉👍

## 🚀 Let's get started!

Follow the steps to contribute to Complete-Preparation.

**1.** Fork [Complete-Preparation](https://github.com/chetan6780/Complete-Preparation) repository.

**2.** Clone your forked copy of the project.

```
$ git clone https://github.com/<your_gihub_username>/Complete-Preparation.git
```

**3.** Checkout into a new branch

```
$ git checkout -b <branch_name>
```

**4.** Make your changes to it

**5.** Add and commit your changes

```
$ git add . && git commit -m "<your_message>"
```

**6.** Push Code to Github under your branch

```
$ git push origin <branch_name>
```

### 📌 Update Your Github Forked Repository

**1.** Lists the remote connections

```
$ git remote -v
```

**2.** Adding the remote repository (only first time)

```
$ git remote add upstream https://github.com/chetan6780/Complete-Preparation
```

**3.** Fetching The Upstream Repository

```
$ git fetch upstream
```

**4.** Finally Merging with Upstream Repository

```
$ git merge upstream/master
```

## Style Guides

### Git Commit Messages

-   Use the present tense ("Add feature" not "Added feature")
-   Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
-   Limit the first line to 72 characters or less
-   Consider starting the commit message with an applicable emoji:
    -   🎨 `:art:` when **creating** new file/folder
    -   🚀 `:rocket:` when **updating** existing file/folder
    -   📘 `:blue_book:` when **writing docs**
    -   🔥 `:fire:` when **deleting** code or files
    -   💯 `:100:` when completed adding full youtube playlist code
-   Example: `🎨 Create contributing.md`

### C++ Style Guide

-   All C++ code is linted/formatted with [Prettier](https://prettier.io/).
-   write cpp code only in below format (ignore |):
    ````coffee
    | ```cpp
    |   // Write your code here...
    | ```
    ````

### Java Style Guide

-   All Java code is linted/formatted with [Prettier](https://prettier.io/).
-   write java code only in below format (ignore |):
    ````coffee
    | ```java
    |   // Write your code here...
    | ```
    ````

### Documentation Style Guide

-   write proper explanation for your code.
-   write as many approaches as you can from brute force to highly optimized.
-   Include credit links.

## 🚫 Don'ts

-   Don't rearrange existing folders/files.
