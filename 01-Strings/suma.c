#include <stdio.h>
#include "Strings.h" 

int main(int argc, char* argv[]) {
    int acumulador = 0;
    for (char** p = argv + 1; *p != NULL; p++) {
        acumulador += ToInteger(*p);
    }
    printf("%d\n", acumulador);
    return 0;
}