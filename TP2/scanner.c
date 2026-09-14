#include "scanner.h"
#include <stdio.h>
#include <ctype.h>

int obtener_columna(char c){
    if (isalpha(c)) return 0; // Letra
    if (isdigit(c)) return 1; // Dígito
    if (c == '.') return 2; // Punto
    if (c == '+' || c == '-' || c == '*' || c == '/') return 3; // Operador
    if (c == '^') return 4; // Potencia
    if (c == '=') return 5; // Asignación
    if (isspace(c)) return 6; // Espacio en blanco
    if (c == EOF) return 7; // Fin de archivo
    return 8; // Otro carácter
}

int tabla[7][9] = {
    {1, 2, 3, 6, 54, 55, 0, 56, 90},
    {1, 1, 50, 50, 50, 50, 50, 50, 50},
    {51, 2, 4, 51, 51, 51, 51, 51, 51},
    {91, 5, 91, 91, 91, 91, 91, 91, 91},
    {51, 5, 51, 51, 51, 51, 51, 51, 51},
    {51, 5, 51, 51, 51, 51, 51, 51, 51},
    {52, 52, 52, 52, 52, 53, 52, 52, 52}
};

static char lexema[256];

const char* get_lexema(void){
    return lexema;
}

Token get_token(void) {
    int estado = 0;
    int i = 0;
    char c;

    while (estado < 50){
        c = fgetc(stdin);
        int col = obtener_columna(c);
        estado = tabla[estado][col];

        if (estado != 0){
            lexema[i] = c;
            i++;
        }
    }

    if(estado == 50 || estado == 51 || estado == 52){

        ungetc(c, stdin); // Devolver el último carácter leído al flujo de entrada
        i--;
    }

    lexema[i] = '\0'; // Terminar la cadena lexema con un carácter nulo

    switch (estado) {
        case 50:
            return TOKEN_ID;
        case 51:
            return TOKEN_CONST;
        case 52:
            return TOKEN_OP;
        case 53:
            return TOKEN_OP_ASIGN;
        case 54:
            return TOKEN_POTENCIA;
        case 55:
            return TOKEN_ASIGN_SIMP;
        case 56:
            return TOKEN_FDT;
        case 90:
            return ERROR_LEXICO;
        case 91:
            return ERROR_PUNTO_AISLADO;
        default:
            return ERROR_LEXICO;
    }
}