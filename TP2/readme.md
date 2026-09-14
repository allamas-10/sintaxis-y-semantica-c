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

 **Arquitectura de Estados**
 
Para optimizar la evaluación en el código, los valores correspondientes a los estados aceptores y los estados de error están ubicados en rangos numéricos completamente separados. La matriz de transición completa se encuentra detallada en el archivo tabla.xlsx.

Estados Aceptores (Rango 50+):
* 50 (ID_DE_TOKEN): Identificador.
* 51 (TOKEN_CONST): Constante numérica.
* 52 (TOKEN_OP): Operador aritmético simple.
* 53 (ASIGNACIÓN DE TOKEN_OP): Operador de asignación compuesta.
* 54 (TOKEN_POTENCIA): Operador de potencia.
* 55 (TOKEN_ASIGN_SIMP): Asignación simple.
* 56 (TOKEN_FDT): Fin de archivo (EOF).

Estados de Error (Rango 90+):
* 90 (ERROR_LÉXICO): Carácter no reconocido por el lenguaje.
* 91 (ERROR_PUNTO_AISLADO): Se ingresó un punto que no forma parte de un número válido (rechazado por el autómata).

**Detalles de Implementación**
* Clasificación de Entrada: La función obtener_columna() clasifica el carácter leído (utilizando funciones de la biblioteca <ctype.h> como isalpha e isdigit) y retorna el índice de la columna correspondiente para consultar en la matriz tabla[estado][columna].
* Manejo del Buffer: Se utiliza un arreglo estático lexema[256] para almacenar temporalmente los caracteres que conforman una palabra válida. Al alcanzar un estado aceptor, la cadena se cierra agregando el carácter nulo (\0).
* Retroceso (Lookahead): Al evaluar identificadores, constantes y operadores simples (estados 50, 51 y 52), el autómata necesita leer un carácter adicional para confirmar el fin del token. En estos casos, se implementó la función ungetc() para devolver ese último carácter al flujo de entrada estándar (stdin) y evitar que se pierda en la siguiente iteración del escáner.
