# Commit Guidelines — Knight Shell

## Introducción

El historial de commits de Knight Shell debe mantenerse organizado, legible y fácil de interpretar.

Cada modificación realizada en el repositorio debe contar con una identificación clara, un contexto breve y un desarrollador responsable.

El propósito de estas directrices es evitar historiales desorganizados, modificaciones difíciles de rastrear y problemas durante la revisión e integración de contribuciones.

**Una contribución no termina cuando el código funciona: también debe poder entenderse, identificarse y revisarse correctamente.**

## 1. Commit Structure

Todos los commits realizados en Knight Shell deben seguir una estructura común:

```text
Nº de seguimiento del commit: Breve Contexto \ Desarrollador encargado del commit
```

Cada elemento tiene una finalidad concreta:

- **Nº de seguimiento:** identificador que permite distinguir y localizar el commit dentro del seguimiento de contribuciones.
- **Breve Contexto:** descripción corta del cambio realizado. Debe tener menos de 25 caracteres.
- **Desarrollador encargado:** nombre o identificador del desarrollador responsable de realizar el commit.

### Example

```text
001: Fix memory leak \ NIZ00LAX
002: Add prompt config \ NIZ00LAX
003: Update docs index \ NIZ00LAX
004: Improve parser \ NIZ00LAX
```

Los ejemplos anteriores son ilustrativos. El número de seguimiento debe respetar el sistema de identificación que utilice el equipo. **(PREGUNTAR EN DISCORD)**

### Commit Responsibility

Cada desarrollador debe responsabilizarse de los commits que realiza.

Esto significa que:

- Los commits deben estar asociados a la identidad Git del desarrollador que los realiza.
- No se deben utilizar identidades ajenas para registrar modificaciones propias.
- El desarrollador debe conocer y poder explicar los cambios que introduce.
- No se deben incorporar modificaciones de terceros atribuyéndolas incorrectamente a otra persona.

La responsabilidad sobre un commit implica conocer su contenido y hacerse cargo de las consecuencias de los cambios realizados.

### Git Identity

Antes de comenzar a contribuir, asegúrate de que Git tiene configurada correctamente tu identidad:

```bash
git config --global user.name "Your Name"
git config --global user.email "your-email@example.com"
```

Utiliza una dirección de correo asociada a tu cuenta de GitHub para facilitar la atribución de tus contribuciones.

## 2. Pull Request Structure

Las Pull Requests permiten presentar un conjunto de modificaciones para que puedan ser revisadas antes de incorporarse al proyecto.

Por ello, deben incluir una explicación breve, clara y suficiente para que cualquier miembro del equipo pueda comprender qué se ha realizado.

Cada Pull Request debe contener:

1. Un título descriptivo.
2. El hashtag correspondiente al tipo de contribución.
3. Una breve explicación del propósito de la contribución.
4. Los cambios principales realizados.
5. El contexto necesario para comprender su incorporación.

### Description Length

Las descripciones deben mantenerse concisas y evitar explicaciones innecesariamente extensas.

- **Descripción breve:** hasta 100 palabras.
- **Descripción ampliada:** hasta 200 palabras cuando sea necesario explicar mejor la implementación o el contexto.

No se trata de alcanzar un número determinado de palabras, sino de proporcionar la información necesaria sin dificultar la revisión.

## 3. Pull Request Hashtags

Todas las Pull Requests deben incluir al menos uno de los siguientes hashtags para identificar su naturaleza.

Cada etiqueta permite reconocer rápidamente el propósito de la contribución.

### `#Developer`

**Contribuciones de código.**

Se utiliza cuando la Pull Request introduce funcionalidades, implementaciones o modificaciones generales en el código fuente de Knight Shell.

Example:

```text
#Developer
```

### `#Docs`

**Contribuciones de documentación.**

Se utiliza cuando la Pull Request modifica, amplía, corrige o incorpora documentación relacionada con el proyecto.

Example:

```text
#Docs
```

### `#VNew`

**Contribuciones con intención de nueva versión.**

Se utiliza cuando los cambios están destinados a formar parte de una futura versión de Knight Shell.

Esta etiqueta permite identificar contribuciones que pueden tener relevancia dentro del desarrollo de una versión concreta.

Example:

```text
#VNew
```

### `#Fix`

**Contribuciones destinadas a solucionar una Issue.**

Se utiliza cuando la Pull Request corrige un problema previamente identificado y registrado en el sistema de Issues.

Siempre que sea posible, debe incluirse la referencia a la Issue correspondiente.

Example:

```text
#Fix
```

### `#Legible`

**Contribuciones destinadas a mejorar la legibilidad del código.**

Se utiliza cuando se realizan modificaciones para facilitar la lectura, comprensión y mantenimiento de una implementación existente.

Puede incluir reorganización de bloques, mejoras de nombres, simplificación de estructuras o