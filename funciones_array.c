#include "funciones_array.h"

#include <stdio.h>
#include <string.h>

void swap(void* elemento1, void* elemento2, size_t size_elemento) {
    void* aux = malloc(size_elemento); 
    if (aux == NULL){
        printf("ERROR");
        return;
    }
    
    memcpy(aux, elemento1, size_elemento);
    memcpy(elemento1, elemento2, size_elemento);
    memcpy(elemento2, aux, size_elemento);
    free(aux);
}

void liberar_vector_dinamico(void ** vector, int* tope) {
    free(*vector);
    *vector = NULL;
    (*tope) = 0;
}

void agregar_elemento_dinamico(void** vector, size_t size_elemento, int* tope, void* valor) {
    (*tope)++;
    void* aux = realloc(*vector, size_elemento * (size_t) (*tope));
    if (!aux) {
        free(*vector);
        fprintf(stderr, "ERROR REALLOC");
        exit(EXIT_FAILURE);
    }
    *vector = aux;
    
    memcpy((*vector) + size_elemento * (size_t) ((*tope) - 1), valor, size_elemento);
}

void eliminar_elemento(void* vector, size_t size_elemento, int* tope, size_t indice) {
    if (*tope == 0)
        return;
    (*tope)--;
    swap(
        vector + (size_elemento * indice), 
        vector + (size_elemento * ((size_t) *tope)), 
        size_elemento
        );
}

void eliminar_elemento_dinamico(void** vector, size_t size_elemento, int* tope, size_t indice) {
    if (*tope == 0)
        return;

    (*tope)--;
    if (*tope == 0) {
        free(*vector);
        *vector = NULL;

    } else {
        swap((*vector) + size_elemento * indice, (*vector) + size_elemento * (size_t) (*tope), size_elemento);

        void* aux = realloc(*vector, size_elemento * (size_t) (*tope));
        if (!aux) {
            free(*vector);
            fprintf(stderr, "ERROR REALLOC");
            exit(EXIT_FAILURE);
        }
        *vector = aux;
    }
}