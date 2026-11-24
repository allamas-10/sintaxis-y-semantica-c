#include "parser.h"
#include <stdio.h>
#include "calc.h"

int main(void) {
    int resultado = yyparse();
    liberar_diccionario();
    return resultado;
}
