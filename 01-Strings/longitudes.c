#include "Strings.h"
#include <stdio.h>

int main(int argc, char *argv[]){

    for(char **arg = argv + 1; *arg != NULL; arg++){
        printf("La longitud de \"%s\" es %zu\n", *arg, GetLength(*arg));
    }
    return 0;
}