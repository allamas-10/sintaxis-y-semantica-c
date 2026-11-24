%code top {
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
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
%type <valor> expresion 

%right '=' MAS_IGUAL MENOS_IGUAL POR_IGUAL DIV_IGUAL
%left '+' '-'
%left '*' '/'
%precedence NEG
%right '^'


%%

sesion
    : %empty
    | sesion linea
    ;

linea
    : '\n'
    | expresion '\n'    {printf("%g\n", $1); }
    | error '\n'        {}
    ;

expresion
    : NUM               { $$ = $1; }
    | ID                {
                            $$ = obtener_valor($1);
                            free($1);
                        }
    | '(' expresion ')' { $$ = $2; } 
    | expresion '+' expresion   { $$ = $1 + $3; }
    | expresion '-' expresion   { $$ = $1 - $3; }
    | expresion '*' expresion   { $$ = $1 * $3; }
    | expresion '/' expresion   { 
                                    if($3 == 0.0){
                                        printf("Error semantico: division por cero \n");
                                        YYERROR;
                                    }
                                    $$ = $1 / $3;
                                }
    | '-' expresion %prec NEG   { $$ = -$2;}
    | expresion '^' expresion   { $$ = pow($1, $3); }
    | ID '=' expresion          { 
                                    $$ = asignar_valor($1, $3);
                                    free($1);
                                }
    | ID MAS_IGUAL expresion    {
                                    $$ = asignar_valor($1, obtener_valor($1) + $3);
                                    free($1);
                                }
    | ID MENOS_IGUAL expresion  {
                                    $$ = asignar_valor($1, obtener_valor($1) - $3);
                                    free($1);
                                }
    | ID POR_IGUAL expresion    {
                                    $$ = asignar_valor($1, obtener_valor($1) * $3);
                                    free($1);
                                }
    | ID DIV_IGUAL expresion    {
                                    if( $3 == 0.0){
                                        free($1);
                                        printf("Error semantico: divison por cero \n");
                                        YYERROR;
                                    }
                                    $$ = asignar_valor($1, obtener_valor($1) / $3);
                                    free($1);
                                }
    ;

%%

void yyerror(const char *s) {
    printf("%s\n", s);
}
