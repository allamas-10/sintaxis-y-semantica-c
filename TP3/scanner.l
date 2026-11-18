%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
%}

%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput nounput
%option noyywrap

letra       [a-zA-Z]
digito      [0-9]
entero      {digito}+
exponente   [eE][+-]?{digito}+
fraccion    ({digito}+"."{digito}*|{digito}*"."{digito}+)
real        ({fraccion}{exponente}?|{entero}{exponente})
numero      ({real}|{entero})
ident       {letra}({letra}|{digito})*

%%

{numero}        { yylval.valor = atof(yytext); return NUM; }
{ident}         { yylval.nombre = strdup(yytext); return ID; }

"+="            { return MAS_IGUAL; }
"-="            { return MENOS_IGUAL; }
"*="            { return POR_IGUAL; }
"/="            { return DIV_IGUAL; }

[-+*/^=()]      { return yytext[0]; }

\n              { return '\n'; }

[ \t\r]+        { }

 /* Las reglas de error van después de las válidas para que estas ganen los empates */

({digito}|".")({letra}|{digito}|".")* {
                    if (strchr(yytext, '.') != NULL)
                        printf("Error léxico REAL inválido: %s\n", yytext);
                    else
                        printf("Error léxico: constante inválida: %s\n", yytext);
                }

{letra}[^ \t\r\n+\-*/^=()]* {
                    printf("Error léxico: identificador inválido: %s\n", yytext);
                }

[^ \t\r\n+\-*/^=()a-zA-Z0-9.]+ {
                    printf("Error léxico: cadena desconocida: %s\n", yytext);
                }

%%
