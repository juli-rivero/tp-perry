#ifndef MOSTRAR_H
#define MOSTRAR_H

#include "feria.h"

typedef unsigned long size_t;


typedef enum Tipos_de_objeto {
    TIPO_PERSONAJE,
    TIPO_BOMBA,
    TIPO_ROBOT,
    TIPO_HERRAMIENTA,
    TIPO_FAMILIAR,
} tipo_de_objeto_t;

//POST: Comprueba si las dos posiciones son iguales
bool son_pos_iguales(coordenada_t pos1, coordenada_t pos2);

//POST: Encuentra el elemento del arreglo que contiene esa posicion y devuelve su indice.
//      En caso de no encontrar devuelve -1.
size_t encontrar_indice_segun_posicion(void* objeto, tipo_de_objeto_t tipo_de_objeto, int tope, coordenada_t posicion);

//POST: elimina del arreglo el elemento del indice especificado.
void eliminar_objeto(void* objeto, tipo_de_objeto_t tipo_de_objeto, int* tope, size_t indice);

//POST: elimina del arreglo el elemento que tenga la posicion especificada.
void eliminar_objeto_segun_posicion(void* objeto, tipo_de_objeto_t tipo_de_objeto, int* tope, coordenada_t posicion);

#endif /* MOSTRAR_H */
