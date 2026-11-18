# Trabajo Práctico N.º 3: Calculadora con Flex y Bison

**Datos del Grupo**
* Grupo: 26-003-13
* Materia: Sintaxis y Semántica de los Lenguajes (K2003)
* Facultad Regional Buenos Aires - UTN

## Descripción

Calculadora completamente funcional construida a partir de la gramática de la cátedra,
usando flex para el análisis léxico y bison para el análisis sintáctico, con las rutinas
semánticas y el diccionario de variables en `calc.c`.

## Estructura

| Archivo | Contenido |
|---|---|
| `main.c` | Programa principal, invoca a `yyparse()` |
| `scanner.l` | Definiciones de flex (escáner) |
| `parser.y` | Definiciones de bison (parser) |
| `calc.c` / `calc.h` | Rutinas semánticas y diccionario de variables |
| `makefile` | Construye el ejecutable `calc`; `make clean` borra lo generado |

## Compilación y uso

```
make
./calc < entrada.txt
make clean
```

## Escáner (`scanner.l`)

* Las opciones `outfile`, `header-file`, `noinput`, `nounput` y `noyywrap` están dentro del
  fuente, así que flex se invoca sin parámetros.
* Tokens: `NUM` (entero o real, con exponente opcional; valor `double`), `ID` (nombre),
  `MAS_IGUAL`, `MENOS_IGUAL`, `POR_IGUAL`, `DIV_IGUAL`, y los caracteres
  `+ - * / ^ = ( )` y `\n` devueltos como su propio código.
* Errores léxicos: se informan y no se devuelve token.
  * Obligatorio: caracteres fuera del alfabeto → `Error léxico: cadena desconocida: @@#;@`
  * Opcionales: `Error léxico: constante inválida: 12a3`,
    `Error léxico: identificador inválido: a#2.4`, `Error léxico REAL inválido: 2.3.4a2.3`
* Los patrones de error se definen después de los válidos: ante un empate de longitud
  flex aplica el primero definido, y ante distinta longitud el más largo.

