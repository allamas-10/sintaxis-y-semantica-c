# Sintaxis y Semántica de los Lenguajes (SSL) — UTN FRBA

Repositorio de trabajos prácticos desarrollados en **C** para la cátedra de *Sintaxis y Semántica de los Lenguajes* (Ingeniería en Sistemas de Información, UTN FRBA). 

El proyecto abarca desde la implementación de librerías y utilidades de bajo nivel sin dependencias estándar hasta el diseño y construcción de analizadores léxicos y sintácticos con **Flex** y **Bison**.

## Tecnologías y herramientas
* **Lenguaje:** C (estándar C11/GNU11)
* **Generadores de analizadores:** Flex (Lex) y Bison (Yacc)
* **Compilación y automatización:** GCC, Make (`Makefile`)
* **Testing:** Pruebas unitarias con `assert.h`

## Estructura del repositorio

### 1. `01-Strings` — Librería de cadenas y utilidades CLI
Implementación desde cero de una biblioteca para manipulación de strings en C **sin utilizar `<string.h>`**, acompañada de análisis teórico (C vs. C#) y programas de línea de comandos.
* **Librería (`Strings.h` / `Strings.c`):** funciones de longitud recursiva, comparación, validación numérica, búsqueda de subcadenas, conversión a entero (`ToInteger`), concatenación y potencia.
* **Testing (`StringsTest.c`):** batería de pruebas unitarias automatizadas vía `make test`.
* **Herramientas CLI:** programas independientes (`enlineas`, `longitudes`, `mayorlongitud`, `todosiguales`, `suma`) operando sobre entrada estándar.

### 2. `TP2` — Analizador léxico basado en máquina de estados
Diseño e implementación manual de un escáner léxico en C mediante tabla de transiciones y arquitectura de estados para el reconocimiento de tokens.

### 3. `TP3` — Calculadora e intérprete con Flex y Bison (`calc`)
Desarrollo de una calculadora por línea de comandos capaz de evaluar expresiones aritméticas y gestionar variables mediante gramáticas independientes del contexto.
* **Escáner (`scanner.l`):** tokenización de literales, identificadores y operadores con Flex.
* **Parser (`parser.y`):** definición de gramática, precedencia de operadores y acciones semánticas con Bison.
* **Estructuras propias:** manejo manual de memoria y lista enlazada implementada desde cero para la tabla de símbolos/variables.

## Compilación y ejecución

Cada carpeta cuenta con su propio `Makefile`. Por ejemplo, para compilar y correr las pruebas de un módulo:

```bash
cd TP3
make
./calc
