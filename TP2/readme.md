**Trabajo Práctico N.º 2: Analizador Léxico (Escáner) para Calculadora**

**Datos del Grupo**
* Grupo: 26-003-13
* Materia: Sintaxis y Semántica de los Lenguajes
* Facultad Regional Buenos Aires - UTN

**Descripción del Trabajo**


El objetivo de este TP es desarrollar el analizador léxico (escáner) en lenguaje C para el intérprete de una calculadora definido por la cátedra. 

El escáner funciona como la primera etapa del proceso de compilación: toma el flujo de caracteres de entrada por consola y lo analiza secuencialmente mediante un autómata finito determinista (AFD). Basado en la tabla de transición, el programa agrupa los caracteres para:
1. Reconocer Tokens Válidos: Identificadores (letra seguida de letras o dígitos), constantes numéricas (enteras o de punto flotante, permitiendo formatos como .5 o 12.), operadores aritméticos simples (+, -, *, /, ^), el operador de asignación simple (=) y operadores compuestos (ej. +=).
2. Gestionar Errores Léxicos: Detectar y reportar anomalías en la entrada, como puntos decimales aislados o símbolos no reconocidos.
3. Manejar el Fin de Texto: Identificar la condición de corte del ciclo principal (FDT) mediante EOF.

**Estructura de Archivos**
* main.c: Programa principal encargado de invocar al escáner de forma iterativa hasta alcanzar el token FDT, imprimiendo por pantalla el token reconocido y su respectivo lexema.
* scanner.c: Contiene la implementación de la matriz de transición, la lógica de clasificación de caracteres, el manejo de retroceso (lookahead) y el buffer estático para almacenar los lexemas.
* scanner.h: Archivo de cabecera con la definición de los enumerados, prototipos de funciones y declaraciones públicas del escáner.
* tabla.xlsx: Documentación formal de la tabla de transición detallando las transiciones del autómata.
