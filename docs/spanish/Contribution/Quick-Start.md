# Quick Start

## ¿Cómo contribuir a Knight Shell?

Knight Shell es un proyecto que busca y valora la seriedad y la dedicación por encima de todo. Por ello, pedimos que te tomes el tiempo necesario para realizar una contribución en condiciones.

No tiene que ser perfecta, pero sí debe estar cuidada. Cada contribución debe hacerse con la atención y el respeto que merece un proyecto de desarrollo, y no desde la prisa por añadir un cambio más.

### Antes de empezar

No es ningún secreto que Knight Shell está escrito en C. Sin embargo, es importante que conozcas qué conocimientos mínimos necesitas para poder realizar contribuciones de cierta complejidad.

No tienes que ser un experto, simplemente necesitas desenvolverte con cierta soltura en las herramientas y tecnologías que utilizamos.

**Requisitos y conocimientos recomendados:**

- Conocimientos intermedios de C.

- Conocimientos y experiencia desarrollando scripts en Bash.

- Saber utilizar Git y GitHub.

- Tener capacidad para documentar correctamente el código y los cambios realizados.

- Compilador GCC (recomendado).

- Shell de tu preferencia.

- Hasta la versión 0.9.0, Knight Shell está orientado a distribuciones Linux. Actualmente estamos trabajando en su adaptación a Windows.



## Entendiendo la estructura de carpetas

Antes de empezar a modificar código, es importante que comprendas cómo está organizado Knight Shell. Conocer la distribución de sus archivos te permitirá encontrar aquello que necesitas sin modificar partes del proyecto que no corresponden a tu contribución.

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

Para comprender esta estructura, explicaremos el propósito de cada carpeta y de los archivos más importantes.

### 1. `docs/`

Empecemos por la primera carpeta: `docs/`.

Aquí encontramos la documentación del proyecto, organizada en dos subcarpetas correspondientes a los dos idiomas principales de Knight Shell:

- `english/`: documentación en inglés.
- `spanish/`: documentación en español.

También encontramos un archivo `README.md`, que funciona como punto de entrada a la documentación y contiene enlaces para facilitar la navegación entre sus diferentes apartados.

Si deseas contribuir mejorando la documentación, añadiendo explicaciones o corrigiendo información, este será el lugar en el que deberás trabajar.

### 2. `headers/`

Seguidamente encontramos la carpeta `headers/`, donde se almacenan las cabeceras utilizadas por el proyecto.

Dentro de ella encontramos dos subcarpetas importantes:

- `mf/`: contiene cabeceras con declaraciones y funcionalidades que necesitamos reutilizar en diferentes partes del proyecto.

- `sf/`: contiene cabeceras destinadas a funcionalidades cuyo uso está limitado a un contexto concreto, como `Kloop()`, utilizada únicamente desde `main.c`.

Por otro lado, tenemos `library.h`, una cabecera principal que reúne estas cabeceras e incorpora bibliotecas estándar de C que utilizamos habitualmente.

De esta manera, podemos centralizar buena parte de las dependencias del proyecto y evitar tener que repetir constantemente los mismos `#include` en diferentes archivos.

**Importante:** antes de crear una nueva cabecera, comprueba si la funcionalidad que necesitas ya está declarada en alguna de las existentes. Evita duplicar declaraciones o introducir dependencias innecesarias.

### 3. `release/`

Como su nombre indica, esta carpeta está destinada a almacenar información relacionada con las versiones publicadas de Knight Shell.

Aquí podemos encontrar información sobre las nuevas versiones, los errores corregidos respecto a versiones anteriores y las expectativas o cambios previstos para futuros lanzamientos.

Su propósito es mantener un registro organizado de la evolución del proyecto.

Si realizas una contribución relacionada con una versión concreta, consulta primero la documentación de `release/` para conocer los cambios que ya se han realizado.

### 4. `shell/`

Aunque pueda parecer una carpeta secundaria, `shell/` también cumple una función importante.

Aquí almacenamos utilidades desarrolladas mediante Bash Scripting que necesita el instalador `install.sh`.

Por ejemplo, `colors.sh` contiene utilidades relacionadas con la presentación visual de los mensajes del instalador.

Su objetivo es mantener separadas las funciones auxiliares del instalador y evitar que todo su código termine concentrado en un único archivo.

### 5. `src/`

Llegamos a la carpeta principal del código fuente: `src/`.

Aquí se encuentra buena parte de la implementación de Knight Shell. Su organización permite separar las distintas responsabilidades del programa y evitar concentrar toda la lógica en un único archivo.

Dentro de ella encontramos `util/`, que contiene dos subcarpetas especialmente importantes:

**`actions/`**

Esta carpeta almacena implementaciones de acciones que Knight Shell necesita ejecutar.

Por ejemplo, `exec.c` contiene la función `exec_sh()`, encargada de ejecutar comandos del sistema y gestionar la respuesta correspondiente.

**`items/`**

En esta carpeta encontramos otras utilidades que intervienen en el funcionamiento de la shell.

Un ejemplo son las funciones `enableRawm()` y `disableRawm()`, relacionadas con la modificación del modo de entrada de la terminal.

Además de estas subcarpetas, encontramos varios archivos fundamentales:

**`builtins.c`**

Contiene los comandos internos (*builtins*) de Knight Shell.

Los builtins son comandos cuya implementación pertenece a la propia shell, en lugar de depender de la ejecución de un programa externo.

Un ejemplo especialmente importante es `cd`, ya que modificar el directorio de trabajo debe afectar al propio proceso de la shell. Por eso no podemos tratarlo simplemente como cualquier otro comando externo.

**`command.c`**

Se encarga de la lógica relacionada con el tratamiento y la ejecución de los comandos introducidos por el usuario.

Es una parte importante del funcionamiento de Knight Shell, puesto que conecta la entrada del usuario con las acciones que debe realizar el programa.

Si necesitas trabajar con el comportamiento de los comandos, su tratamiento o su ejecución, deberás familiarizarte con este archivo.

**`loop.c`**

Contiene la lógica del ciclo principal de la shell.

Este ciclo permite que Knight Shell continúe funcionando, recibiendo nuevas entradas y procesándolas hasta que se produzca una condición de salida.

Es una de las partes fundamentales para comprender cómo se mantiene activa la shell durante su ejecución.

### 6. Archivos principales del repositorio

Finalmente, encontramos varios archivos situados directamente en la raíz del proyecto.

**`main.c`**

Es el punto de entrada del programa. Desde aquí comienza la ejecución de Knight Shell y se inicializan las partes necesarias para poner en marcha su funcionamiento.

**`Makefile`**

Contiene las instrucciones que utiliza Make para automatizar el proceso de compilación.

Antes de modificarlo, asegúrate de comprender cómo se relacionan los archivos fuente, las cabeceras y las opciones de compilación.

**`install.sh`**

Es el script encargado de gestionar el proceso de instalación de Knight Shell.

Está desarrollado en Bash y utiliza las utilidades disponibles en `shell/` para realizar determinadas tareas.

**`README`**

Es el documento principal de presentación del repositorio. Contiene información general sobre Knight Shell y sirve como punto de entrada para quienes visitan el proyecto.

**`LICENSE`**

Contiene la licencia bajo la que se distribuye Knight Shell. Cualquier contribución debe respetar sus condiciones.

**`.gitignore` y `.gitattributes`**

Son archivos de configuración relacionados con Git.

- `.gitignore` establece qué archivos y directorios deben excluirse del seguimiento de Git.
- `.gitattributes` permite definir cómo Git debe tratar determinados archivos dentro del repositorio.

---

## Entendiendo las ramas del proyecto

Antes de empezar a desarrollar, debes conocer la diferencia entre las dos ramas principales de Knight Shell.

**`dev` — Development**

Es la rama destinada al desarrollo activo del proyecto.

Aquí encontrarás todo lo necesario para colaborar: código, documentación, modificaciones, recursos y demás elementos utilizados durante el desarrollo.

Si deseas realizar una contribución, esta es la rama que debes utilizar como referencia.

**`main` — Production**

Esta rama está reservada para las versiones destinadas a producción.

No debe utilizarse como referencia principal para desarrollar nuevas funcionalidades, ya que su contenido está orientado a mantener una versión estable del proyecto.

**Toda contribución de desarrollo deberá dirigirse a `dev`, salvo que el equipo indique lo contrario.**

## Una última recomendación

No tengas prisa por empezar a modificar código.

Dedica un tiempo a explorar el repositorio, comprender cómo se relacionan sus diferentes componentes y familiarizarte con las funciones que ya existen.

Una contribución bien realizada no consiste únicamente en conseguir que algo funcione. También consiste en comprender por qué funciona, cómo afecta al resto del proyecto y qué consecuencias puede tener su incorporación.

Si tienes dudas sobre una implementación o una modificación que deseas realizar, puedes consultar al equipo antes de comenzar.

Recuerda que estamos construyendo Knight Shell entre todos, y que mantener una buena organización es responsabilidad de cada colaborador.

#### Siguiente Página:

[**Como Crear un Buen Commit**](./Commit-Guide.md)