#ifndef MI_LIBRERIA_H
#define MI_LIBRERIA_H

#define MAX_ARRAY 1000
#include "feria.h"

// PRE: Se espera un máximo positivo.
// POST: devuelve un numero entre [0 , max_exclusive).
int rand_index(int max_exclusive);

// PRE: Se esperan minimos y máximos positivos.
// POST: devuelve un numero entre [min_inclusive , max_inclusive].
int rand_minI_maxI(int min_inclusive, int max_inclusive);

// POST: Se eliminara el elemento del arreglo indicado, el arreglo quedara desordenado.
void eliminar_elemento(coordenada_t* arreglo, int indice, int* tope);

// PRE: El string debe ser una variable.
// POST: Repite el string recibido la cantidad de veces especificada y devuelve la cadena
char* repetir_str(char* str, int cant);

#endif /* MI_LIBRERIA_H */