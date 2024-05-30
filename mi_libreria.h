#ifndef MI_LIBRERIA_H
#define MI_LIBRERIA_H

#include "feria.h"
#include "constantes.h"

typedef unsigned long size_t;

// PRE: Se espera un máximo positivo.
// POST: devuelve un numero entre [0 , max_exclusive).
int rand_index(int max_exclusive);

// PRE: Se esperan minimos y máximos positivos.
// POST: devuelve un numero entre [min_inclusive , max_inclusive].
int rand_minI_maxI(int min_inclusive, int max_inclusive);

//POST: intercambia dos variables
void swap(void* elemento1, void* elemento2, size_t size_elemento);

//POST: Calcula la distancia manhatan entre dos posiciones.
int calcular_distancia(coordenada_t pos1, coordenada_t pos2);

//POST: modifica filtrados para que sea un arreglo de longitud TER_FIL donde cada elemento sea un arreglo con las coordenadas que complen la condicion de que la distancia manhatan de cualquier coordenada con las coordenadas pasadas sean menor a la distancia especificada.
void filtrar_coordenadas_segun_distancia(int distancia, coordenada_t* posiciones, int tope_posiciones, coordenada_t* filtrados[TER_FIL], int topes_filtrados[TER_FIL]);

void centrar_verticalmente(int filas_contenido);

void centrar_horizontalmente(int columnas_contenido);

void imprimir_linea_centrada(const char* texto);

void imprimir_en_el_centro(const char* texto);

char* concatenar_textos(const char** textos, size_t cantidad);

void destruir_concatenacion(char* concatenacion);

#endif /* MI_LIBRERIA_H */