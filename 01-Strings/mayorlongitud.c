#include <stdio.h>
#include "Strings.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        return 0;
    }

    char* mayor = argv[1];

    for (char** argumento = argv + 2; argumento < argv + argc; argumento++) {
        
        if (GetLength(*argumento) > GetLength(mayor)) {
            mayor = *argumento;
        }
    }

    printf("%s\n", mayor);

    return 0;
}