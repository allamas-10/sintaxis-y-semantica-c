#ifndef STRINGS_H
#define STRINGS_H

#include <stdbool.h>
#include <stdlib.h>

/*
Pre: Puntero a una cadena terminada en \0
Post: Devuelve true si la cadena es vacía, false en caso contrario
*/
bool IsEmpty(const char* s);

/*
Pre: Puntero a una cadena terminada en \0
Post: Devuelve la longitud de la cadena
*/
size_t GetLength(const char* s);

/*
Pre: Puntero a dos cadenas terminadas en \0
Post: Devuelve true si las cadenas son iguales, false en caso contrario
*/
bool AreEqual(const char* s1, const char* s2);

/*
Pre: Puntero a una cadena terminada en \0
Post: Devuelve true si la cadena contiene solo dígitos decimales, false en caso contrario
*/
bool AreDecimalDigits(const char* s);

/*
Pre: Puntero a una cadena terminada en \0 y un carácter
Post: Devuelve true si la cadena contiene el carácter, false en caso contrario
*/
bool Contains(const char* s, char c);

/*
Pre: Puntero a una cadena terminada en \0
Post: Devuelve el valor entero representado por la cadena
*/
int ToInteger(const char* s);

/*
Pre: Puntero a una cadena de destino y un puntero a una cadena de fuente
Post: Concatena la cadena de fuente a la cadena de destino
*/
void Concatenate(char* destino, const char* fuente);

/*
Pre: Puntero a una cadena terminada en \0 y un número entero positivo
Post: Concatena la cadena consigo misma n veces
*/
void Power(char* s, unsigned int n);

/*
Pre: Puntero a una cadena terminada en \0
Post: Invierte la cadena
*/
void Reverse(char* s);

/*
Pre: Puntero a dos cadenas terminadas en \0
Post: Devuelve true si s comienza con el prefijo dado, false en caso contrario
*/
bool StartsWith(const char* s, const char* prefix);

#endif