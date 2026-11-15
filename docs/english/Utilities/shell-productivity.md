# Shell Productivity

## What Is Productivity in a Shell?

Productivity in a shell is the ability to work quickly, efficiently, and effectively. It allows us to perform actions and automate tasks that would otherwise consume unnecessary time. This is one of the main reasons shells exist: to give users greater control over their systems while making their workflows faster.

With that in mind, this guide introduces Knight Shell's custom prompt system. You will learn how to create and customize your own prompt to make your shell experience as efficient and productive as possible.

## Creating Our First Custom Prompt with Bash Scripting

To create our first custom prompt, we need to navigate to the following directory:

`~/.config/ksh/`

This directory is used by Knight Shell to locate your personal configuration on Linux and Darwin (macOS).

If it does not exist, create it manually so Knight Shell can detect your configuration correctly.

### Analyzing the Default Configuration

If you do not want to create a prompt from scratch, Knight Shell provides a default configuration designed for new users. It is ready to use and offers a simple starting point for customization.

Create a file named `config.sh` inside `~/.config/ksh/` and paste the following code into it:

```bash
#!/usr/bin/env bash

kernel=$(uname -s)

split_str() {
    if [[ -z "$1" ]]; then
        return 1
    fi

    local path="${1%/}"

    # If the current directory is HOME, display "~"
    if [[ "$path" == "$HOME" ]]; then
        printf '~'
        return 0
    fi

    # Extract the last two directory components
    local base="${path##*/}"
    local parent="${path%/*}"
    parent="${parent##*/}"

    if [[ -n "$parent" ]]; then
        printf '%s/%s' "$parent" "$base"
    else
        printf '/%s' "$base"
    fi
}

linux_prompt() {
    currentDir=$(pwd)
    printDir=$(split_str "$currentDir")
    gitBranch=$(git branch --show-current 2>/dev/null)
    logo=""
    user=$(whoami)

    PROMPT="[$logo] $printDir ($user) {$gitBranch}"
    printf '%s' "$PROMPT"
}

darwin_prompt() {
    currentDir=$(pwd)
    printDir=$(split_str "$currentDir")
    gitBranch=$(git branch --show-current 2>/dev/null)
    logo=""
    user=$(whoami)

    PROMPT="[$logo] $printDir ($user) {$gitBranch}"
    printf '%s' "$PROMPT"
}

# dos_prompt() {
#     Future implementation
# }

if [[ "$kernel" == "Linux" ]]; then
    linux_prompt
elif [[ "$kernel" == "Darwin" ]]; then
    darwin_prompt
else
    printf 'error'
fi
```

### Understanding the Configuration

Before customizing the prompt, let's take a look at its main components:

- **`uname -s`:** Identifies the operating system kernel. We use it to decide which prompt configuration should be displayed.
- **`split_str()`:** Simplifies the current directory path, displaying only its last two components or `~` when the user is inside their home directory.
- **`git branch --show-current`:** Retrieves the name of the current Git branch. If the directory is not a Git repository, the command produces no output.
- **`linux_prompt()` and `darwin_prompt()`:** Define the appearance of the prompt for Linux and macOS systems.
- **`printf '%s' "$PROMPT"`:** Prints the prompt without interpreting its contents as a format string.

### Loading Your Configuration

Knight Shell executes `config.sh` as a Bash script and uses its output to display the custom prompt.

If an error occurs while displaying your prompt, start by checking your `config.sh` file. Make sure its syntax is valid and that the commands used inside it are available on your system.

Remember that this configuration is written specifically for Bash. It is not a universal configuration format for every shell.