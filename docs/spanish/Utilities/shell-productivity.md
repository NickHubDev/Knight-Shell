# Productividad en la Shell

## ¿Qué es la productividad en una Shell?

La productividad en una Shell es la capacidad de trabajar de una manera rápida, eficaz y eficiente. Nos permite realizar acciones y automatizar tareas que, de otro modo, consumirían tiempo innecesariamente. Esta es una de las principales razones por las que existen las shells: proporcionar a los usuarios un mayor control sobre sus sistemas y agilizar sus flujos de trabajo.

Con esto en mente, presentamos esta guía sobre el sistema de prompts personalizados de Knight Shell. Aprenderás a crear y personalizar tu propio prompt para conseguir que tu experiencia en la Shell sea lo más eficiente y productiva posible.

## Creando nuestro primer Prompt personalizado con Bash Scripting

Para crear nuestro primer prompt personalizado, debemos dirigirnos al siguiente directorio:

`~/.config/ksh/`

Este directorio permite a Knight Shell localizar tu configuración personal en sistemas Linux y Darwin (macOS).

Si no existe, tendrás que crearlo manualmente para que Knight Shell pueda detectar correctamente tu configuración.

### Analizando la configuración predeterminada

Si no deseas crear un prompt desde cero, Knight Shell ofrece una configuración predeterminada diseñada para nuevos usuarios. Está preparada para utilizarse directamente y proporciona un punto de partida sencillo para personalizar tu experiencia.

Crea un archivo llamado `config.sh` dentro de `~/.config/ksh/` y pega el siguiente código en su interior:

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

### Entendiendo la configuración

Antes de personalizar el prompt, vamos a revisar sus componentes principales:

- **`uname -s`:** Identifica el kernel del sistema operativo. Lo utilizamos para decidir qué configuración del prompt debemos mostrar.
- **`split_str()`:** Simplifica la ruta del directorio actual, mostrando únicamente sus dos últimos componentes o `~` cuando el usuario se encuentra en su directorio personal.
- **`git branch --show-current`:** Obtiene el nombre de la rama Git actual. Si el directorio no pertenece a un repositorio Git, el comando no produce ninguna salida.
- **`linux_prompt()` y `darwin_prompt()`:** Definen la apariencia del prompt para sistemas Linux y macOS.
- **`printf '%s' "$PROMPT"`:** Imprime el prompt sin interpretar su contenido como una cadena de formato.

### Cargando tu configuración

Knight Shell ejecuta `config.sh` como un script de Bash y utiliza su salida para mostrar el prompt personalizado.

Si ocurre algún error al mostrar tu prompt, empieza revisando el archivo `config.sh`. Comprueba que su sintaxis sea correcta y que los comandos utilizados estén disponibles en tu sistema.

Recuerda que esta configuración está escrita específicamente para Bash. No es un formato de configuración universal para todas las shells.