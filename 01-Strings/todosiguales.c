#include <stdio.h>
#include "Strings.h" 

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        printf("1\n");
        return 0;
    }
    char* primer_arg = *(argv + 1);
    int son_iguales = 1;
    for (char** p = argv + 2; *p != NULL; p++) {
        if (!AreEqual(primer_arg, *p)) {
            son_iguales = 0;
            break;
        }
    }
    printf("%d\n", son_iguales);
    return 0;
}