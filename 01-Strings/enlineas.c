#include <stdio.h>
#include "Strings.h"

int main(int argc, char *argv[]) {
    //Empezamos desde argv +1 porque el primer argumento real 
    for (char **p = argv + 1; *p != NULL; p++) { //Se usa **p para acceder a un elemento de esa lista, p++ mueve al siguiente elemento
        
        //el *p nos permite acceder al contenido de la cadena de caracteres
        printf("%s\n", *p);
    }
    
    return 0;
}