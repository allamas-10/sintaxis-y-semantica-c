#ifndef CALC_H_
#define CALC_H_

//Busca variable y si no la encuentra lo asigna una nueva con valor 0
double obtener_valor(const char* nombre);

// Asigna un valor a una variable y si no existe crea una nueva y lo asigna
double asignar_valor(const char* nombre, double valor);

//libera toda la memoria pedida para el diccionario al terminar el programa
void liberar_diccionario(void);

#endif
