%code top {
#include <stdio.h>
#include <stdlib.h>
}

%code provides {
int yylex(void);
void yyerror(const char *s);
}

%output "parser.c"
%defines "parser.h"

%union {
    double valor;
    char  *nombre;
}

%token <valor>  NUM
%token <nombre> ID
%token MAS_IGUAL MENOS_IGUAL POR_IGUAL DIV_IGUAL

%%

sesion
    : %empty
    ;

%%

void yyerror(const char *s) {
    printf("%s\n", s);
}
