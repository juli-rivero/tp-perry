#ifndef FUNCIONES_ARRAY_H
#define FUNCIONES_ARRAY_H

#include <stdlib.h>


//POST: intercambia dos variables
void swap(void* elemento1, void* elemento2, size_t size_elemento);

//libera el vector, lo apunta a NULL y setea el tope a 0. Esta simplemente para no tener que llamar a la libreria stdlib ;D
void liberar_vector_dinamico(void ** vector, int* tope);

//POST: agrega en un arreglo dinamico un elemento con el valor pasado.
void agregar_elemento_dinamico(void** vector, size_t size_elemento, int* tope, void* valor);

//POST: elimina del arreglo el elemento del indice especificado.
void eliminar_elemento(void* vector, size_t size_elemento, int* tope, size_t indice);

//POST: elimina de un arreglo dinamico el elemento del indice especificado.
void eliminar_elemento_dinamico(void** vector, size_t size_elemento, int* tope, size_t indice);

#endif /* FUNCIONES_ARRAY_H */