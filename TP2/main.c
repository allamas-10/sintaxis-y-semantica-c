#include <stdio.h>
#include "scanner.h"

void procesar_token(Token t) {
    switch(t) {
        case TOKEN_ID:
            printf("Identificador: %s\n", get_lexema());
            break;
        case TOKEN_CONST:
            printf("Constante: %s\n", get_lexema());
            break;
        case TOKEN_OP:
            printf("Operador: %s\n", get_lexema());
            break;
        case TOKEN_OP_ASIGN:
            printf("Operador Asignación Compuesta: %s\n", get_lexema());
            break;
        case TOKEN_POTENCIA:
            printf("Operador Potencia: %s\n", get_lexema());
            break;
        case TOKEN_ASIGN_SIMP:
            printf("Asignación Simple: %s\n", get_lexema());
            break;
        case TOKEN_FDT:
            printf("Fin de texto (FDT)\n");
            break;
        case ERROR_LEXICO:
            printf("Error Léxico: %s\n", get_lexema());
            break;
        case ERROR_PUNTO_AISLADO:
            printf("Error Punto Aislado: %s\n", get_lexema());
            break;
    }
}

int main(void) {
    Token t;

    do {
        t = get_token();
        procesar_token(t);

    } while (t != TOKEN_FDT);

    return 0;
}
