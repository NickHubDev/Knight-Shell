# Quick Start

## How to Contribute to Knight Shell?

Knight Shell is a project that values seriousness and dedication above all else. For this reason, we ask you to take the necessary time to make a proper contribution.

It does not have to be perfect, but it must be carefully prepared. Every contribution should be made with the attention and respect that a development project deserves, rather than rushing to add just another change.

### Before You Start

It is no secret that Knight Shell is written in C. However, it is important to understand the minimum knowledge required to make contributions of a certain level of complexity.

You do not have to be an expert; you simply need to be reasonably comfortable with the tools and technologies we use.

**Recommended requirements and knowledge:**

- Intermediate knowledge of C.
- Knowledge and experience developing Bash scripts.
- Ability to use Git and GitHub.
- Ability to properly document code and the changes made.
- GCC compiler (recommended).
- Shell of your choice.
- Up to version 0.9.0, Knight Shell is designed for Linux distributions. We are currently working on porting it to Windows.

---

## Understanding the Directory Structure

Before modifying any code, it is important to understand how Knight Shell is organized. Knowing how its files are distributed will help you find what you need without modifying parts of the project unrelated to your contribution.

```text
|
|- docs/
|   |
|   |- english/
|   |
|   |- spanish/
|   |
|   |- README.md
|
|- headers/
|   |
|   |- mf/
|   |
|   |- sf/
|   |
|   |- library.h
|
|- release/
|
|- shell/
|   |
|   |- colors.sh
|
|- src/
|   |
|   |- util/
|   |   |
|   |   |- actions/
|   |   |
|   |   |- items/
|   |
|   |- builtins.c
|   |
|   |- command.c
|   |
|   |- loop.c
|
|- .gitattributes
|
|- .gitignore
|
|- CONTRIBUTING
|
|- install.sh
|
|- LICENSE
|
|- main.c
|
|- Makefile
|
|- README
```

To understand this structure, we will explain the purpose of each directory and the most important files.

### 1. `docs/`

Let's start with the first directory: `docs/`.

Here we find the project's documentation, organized into two subdirectories corresponding to the two main languages used by Knight Shell:

- `english/`: documentation in English.
- `spanish/`: documentation in Spanish.

We also find a file named `README.md`, which serves as the documentation entry point and contains links to make navigating its different sections easier.

If you wish to contribute by improving the documentation, adding explanations, or correcting information, this is where you should work.

### 2. `headers/`

Next, we find the `headers/` directory, where the header files used by the project are stored.

Inside it, we find two important subdirectories:

- `mf/`: contains headers with declarations and functionalities that we need to reuse in different parts of the project.
- `sf/`: contains headers intended for functionalities whose use is limited to a specific context, such as `Kloop()`, which is only used in `main.c`.

We also have `library.h`, a main header that brings these headers together and includes standard C libraries that we frequently use.

This allows us to centralize a significant part of the project's dependencies and avoid repeatedly including the same `#include` directives in different files.

**Important:** before creating a new header, check whether the functionality you need has already been declared in an existing one. Avoid duplicating declarations or introducing unnecessary dependencies.

### 3. `release/`

As its name suggests, this directory is intended to store information related to Knight Shell releases.

Here we can find information about new versions, bugs fixed from previous versions, and expectations or changes planned for future releases.

Its purpose is to maintain an organized record of the project's evolution.

If you make a contribution related to a specific version, check the documentation in `release/` first to understand which changes have already been made.

### 4. `shell/`

Although it may seem like a secondary directory, `shell/` also serves an important purpose.

Here we store utilities developed using Bash scripting that are required by the `install.sh` installer.

For example, `colors.sh` contains utilities related to the visual presentation of the installer's messages.

Its purpose is to keep the installer's auxiliary functions separate and prevent all its code from being concentrated in a single file.

### 5. `src/`

We now reach the main source code directory: `src/`.

This is where much of Knight Shell's implementation is located. Its organization allows us to separate the different responsibilities of the program and avoid concentrating all the logic in a single file.

Inside it, we find `util/`, which contains two particularly important subdirectories:

**`actions/`**

This directory stores implementations of actions that Knight Shell needs to execute.

For example, `exec.c` contains the `exec_sh()` function, which is responsible for executing system commands and managing the corresponding response.

**`items/`**

In this directory, we find other utilities involved in the shell's operation.

Examples include the `enableRawm()` and `disableRawm()` functions, which are related to modifying the terminal's input mode.

In addition to these subdirectories, we find several essential files:

**`builtins.c`**

Contains Knight Shell's built-in commands (*builtins*).

Builtins are commands whose implementation belongs to the shell itself, rather than relying on the execution of an external program.

A particularly important example is `cd`, since changing the working directory must affect the shell's own process. For this reason, we cannot treat it simply like any other external command.

**`command.c`**

Handles the logic related to processing and executing commands entered by the user.

It is an important part of Knight Shell's operation, as it connects user input with the actions the program must perform.

If you need to work on command behavior, processing, or execution, you should become familiar with this file.

**`loop.c`**

Contains the logic for the shell's main loop.

This loop allows Knight Shell to keep running, receiving new input and processing it until an exit condition is reached.

It is one of the fundamental parts for understanding how the shell remains active during execution.

### 6. Main Repository Files

Finally, we find several files located directly in the project's root directory.

**`main.c`**

This is the program's entry point. Execution of Knight Shell begins here, and the necessary components are initialized to start its operation.

**`Makefile`**

Contains the instructions used by Make to automate the compilation process.

Before modifying it, make sure you understand how source files, headers, and compilation options relate to one another.

**`install.sh`**

This is the script responsible for managing the Knight Shell installation process.

It is written in Bash and uses the utilities available in `shell/` to perform certain tasks.

**`README`**

This is the repository's main introductory document. It contains general information about Knight Shell and serves as the entry point for people visiting the project.

**`LICENSE`**

Contains the license under which Knight Shell is distributed. Every contribution must comply with its terms.

**`.gitignore` and `.gitattributes`**

These are configuration files related to Git.

- `.gitignore` specifies which files and directories should be excluded from Git tracking.
- `.gitattributes` allows you to define how Git should handle specific files within the repository.

---

## Understanding the Project Branches

Before starting development, you should understand the difference between Knight Shell's two main branches.

**`dev` — Development**

This is the branch intended for active project development.

Here you will find everything needed to contribute: code, documentation, modifications, resources, and other elements used throughout development.

If you wish to make a contribution, this is the branch you should use as your reference.

**`main` — Production**

This branch is reserved for versions intended for production.

It should not be used as the main reference for developing new features, since its contents are intended to maintain a stable version of the project.

**All development contributions must target `dev`, unless instructed otherwise by the team.**

## One Last Recommendation

Do not rush into modifying code.

Take some time to explore the repository, understand how its different components interact, and become familiar with the functions that already exist.

A properly developed contribution is not simply about making something work. It is also about understanding why it works, how it affects the rest of the project, and what consequences its incorporation may have.

If you have questions about an implementation or a modification you wish to make, you can consult the team before getting started.

Remember that we are building Knight Shell together, and maintaining good organization is everyone's responsibility.

#### Next Page:

[**How to Create a Good Commit**](./Commit-Guide.md)