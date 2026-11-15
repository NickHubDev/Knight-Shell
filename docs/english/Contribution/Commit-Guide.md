# Commit Guidelines — Knight Shell

## Introduction

The commit history of Knight Shell must remain organized, readable, and easy to understand.

Every modification made to the repository must have a clear identification, a brief context, and a responsible developer.

The purpose of these guidelines is to prevent disorganized histories, modifications that are difficult to track, and problems during the review and integration of contributions.

**A contribution does not end when the code works: it must also be understandable, identifiable, and properly reviewable.**

## 1. Commit Structure

All commits made to Knight Shell must follow a common structure:

```text
Commit Tracking Number: Brief Context \ Developer Responsible for the Commit
```

Each element has a specific purpose:

- **Commit Tracking Number:** an identifier used to distinguish and locate the commit within the contribution tracking system.
- **Brief Context:** a short description of the change being made. It must contain fewer than 25 characters.
- **Developer Responsible:** the name or identifier of the developer responsible for making the commit.

### Example

```text
001: Fix memory leak \ NIZ00LAX
002: Add prompt config \ NIZ00LAX
003: Update docs index \ NIZ00LAX
004: Improve parser \ NIZ00LAX
```

The examples above are illustrative. The tracking number must follow the identification system established by the team. **(ASK ON DISCORD)**

### Commit Responsibility

Every developer must take responsibility for the commits they make.

This means that:

- Commits must be associated with the Git identity of the developer who makes them.
- Other people's identities must not be used to register your own modifications.
- Developers must understand and be able to explain the changes they introduce.
- Third-party modifications must not be incorporated while incorrectly attributing them to someone else.

Responsibility for a commit means understanding its contents and accepting responsibility for the consequences of the changes made.

### Git Identity

Before starting to contribute, make sure Git has your identity correctly configured:

```bash
git config --global user.name "Your Name"
git config --global user.email "your-email@example.com"
```

Use an email address associated with your GitHub account to make it easier to attribute your contributions correctly.

## 2. Pull Request Structure

Pull Requests allow contributors to present a set of modifications so they can be reviewed before being incorporated into the project.

For this reason, they must include a brief, clear, and sufficient explanation so that any team member can understand what has been done.

Every Pull Request must contain:

1. A descriptive title.
2. The hashtag corresponding to the type of contribution.
3. A brief explanation of the purpose of the contribution.
4. The main changes made.
5. The context necessary to understand its incorporation.

### Description Length

Descriptions should remain concise and avoid unnecessarily extensive explanations.

- **Brief description:** up to 100 words.
- **Extended description:** up to 200 words when further explanation of the implementation or context is necessary.

The goal is not to reach a specific word count, but to provide the necessary information without making the review more difficult.

## 3. Pull Request Hashtags

All Pull Requests must include at least one of the following hashtags to identify their nature.

Each label makes it possible to quickly recognize the purpose of the contribution.

### `#Developer`

**Code contributions.**

Used when a Pull Request introduces features, implementations, or general modifications to the Knight Shell source code.

Example:

```text
#Developer
```

### `#Docs`

**Documentation contributions.**

Used when a Pull Request modifies, expands, corrects, or introduces documentation related to the project.

Example:

```text
#Docs
```

### `#VNew`

**Contributions intended for a new release.**

Used when changes are intended to become part of a future Knight Shell release.

This label makes it possible to identify contributions that may be relevant to the development of a specific release.

Example:

```text
#VNew
```

### `#Fix`

**Contributions intended to resolve an Issue.**

Used when a Pull Request fixes a problem that has previously been identified and registered in the Issues system.

Whenever possible, the corresponding Issue reference must be included.

Example:

```text
#Fix
```

### `#Legible`

**Contributions intended to improve code readability.**

Used when modifications are made to improve the readability, understanding, and maintainability of an existing implementation.

This may include block reorganization, naming improvements, structure simplification, or formatting adjustments, provided that the program's behavior is not unnecessarily altered.

Example:

```text
#Legible
```

## 4. Pull Request Example

The following is an example of how a Pull Request should be structured:

```text
Title:
Improve command execution handling

Hashtag:
#Developer

Description:
This contribution improves the way Knight Shell
handles command execution.

The changes reorganize the execution logic
and improve error handling to make the
implementation easier to maintain.
```

Another example, this time for a fix:

```text
Title:
Fix memory allocation error

Hashtag:
#Fix

Description:
This contribution fixes a memory allocation
issue that could cause unexpected behavior
during command execution.

Issue: #12
```

These examples represent the expected organization, not a mandatory text template.

**The quality of a contribution is also demonstrated by the way it is presented.**