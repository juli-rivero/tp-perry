#ifndef MI_LIBRERIA_H
#define MI_LIBRERIA_H

//#include "constantes.h"

typedef unsigned long size_t;

// PRE: Se espera un máximo positivo.
// POST: devuelve un numero entre [0 , max_exclusive).
int rand_index(int max_exclusive);

// PRE: Se esperan minimos y máximos positivos.
// POST: devuelve un numero entre [min_inclusive , max_inclusive].
int rand_minI_maxI(int min_inclusive, int max_inclusive);

//POST: intercambia dos variables
void swap(void* elemento1, void* elemento2, size_t size_elemento);

//POST: elimina del arreglo el elemento del indice especificado.
void eliminar_elemento(void* vector, size_t size_elemento, int* tope, size_t indice);

void centrar_verticalmente(int filas_contenido);

void centrar_horizontalmente(int columnas_contenido);

void imprimir_linea_centrada(const char* texto);

void imprimir_en_el_centro(const char* texto);

char* concatenar_textos(const char** textos, size_t cantidad);

void destruir_concatenacion(char* concatenacion);

#endif /* MI_LIBRERIA_H */