#ifndef SCANNER_H_
#define SCANNER_H_

typedef enum{
    TOKEN_ID,
    TOKEN_CONST,
    TOKEN_OP,
    TOKEN_OP_ASIGN,
    TOKEN_POTENCIA,
    TOKEN_ASIGN_SIMP,
    TOKEN_FDT,
    ERROR_LEXICO,
    ERROR_PUNTO_AISLADO
} Token;

const char* get_lexema(void);

Token get_token(void);

#endif  