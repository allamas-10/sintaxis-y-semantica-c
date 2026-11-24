#include "parser.h"
#include <stdio.h>
#include "calc.h"

int main(void) {
    return yyparse();
    liberar_diccionario();
    return 0;
}
