#include "mi_libreria.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int rand_index(int max_exclusive)
{
    return rand() % max_exclusive;
}

int rand_minI_maxI(int min_inclusive, int max_inclusive)
{
    return rand() % (max_inclusive - min_inclusive + 1) + min_inclusive;
}

void eliminar_elemento(coordenada_t* arreglo, int indice, int* tope) {
    coordenada_t aux = arreglo[indice];
    arreglo[indice] = arreglo[*tope - 1];
    arreglo[*tope - 1] = aux;
    (*tope)--;
}

char* repetir_str(char* str, int cant) {
    if (!cant) return "";

    char strcopy[MAX_ARRAY];
    return strcat(strcpy(strcopy, str), repetir_str(str, cant - 1));
}