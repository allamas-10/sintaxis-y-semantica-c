#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoVariable{
    char* nombre;
    double valor;
    struct NodoVariable* siguiente;
} NodoVariable;

//Punterio al inicio del diccionario
static NodoVariable* diccionario = NULL;

static NodoVariable* buscar_variable(const char* nombre){
    NodoVariable* actual = diccionario;

    while(actual != NULL){
        if(strcmp(actual->nombre, nombre) == 0){
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

static NodoVariable* crear_variable(const char* nombre, double valor_inicial){
    NodoVariable* nuevo = (NodoVariable*)malloc(sizeof(NodoVariable));

    if(nuevo == NULL){
        fprintf(stderr, "Error, se ha quedado sin memoria para crear variable\n");
        exit(EXIT_FAILURE);
    }

    nuevo->nombre = (char*)malloc(strlen(nombre) + 1);

    if(nuevo->nombre == NULL){
        free(nuevo);
        fprintf(stderr, "Error, sin memoria para el nombre de la variable\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nuevo->nombre, nombre);

    nuevo->valor = valor_inicial;
    nuevo->siguiente = diccionario;
    diccionario = nuevo;

    return nuevo;
}

double obtener_valor(const char* nombre){
    NodoVariable* var = buscar_variable(nombre);

    if(var == NULL){
        var = crear_variable(nombre, valor);
    }
    return var->valor;
}

double asignar_valor(const char* nombre, double valor){
    NodoVariable* var = buscar_variable(nombre);
    if(var == NULL){
        var = crear_variable(nombre, 0.0);
    }
    else{
        var->valor = valor;
    }
    return var->valor;
}

void liberar_diccionario(void){
    NodoVariable* actual = diccionario;
    while(actual != NULL){
        NodoVariable* temp = actual;
        actual = actual->siguiente;
        free(temp->nombre);
        free(temp);
    }
    diccionario = NULL;
}
