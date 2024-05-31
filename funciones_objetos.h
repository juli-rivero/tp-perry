#ifndef MOSTRAR_H
#define MOSTRAR_H

#include "feria.h"
#include "constantes.h"

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

//POST: Calcula la distancia manhatan entre dos posiciones.
int calcular_distancia(coordenada_t pos1, coordenada_t pos2);

//POST: modifica filtrados para que sea un arreglo de longitud TER_FIL donde cada elemento sea un arreglo con las coordenadas que complen la condicion de que la distancia manhatan de cualquier coordenada con las coordenadas pasadas sean menor a la distancia especificada.
void filtrar_coordenadas_segun_distancia(int distancia, coordenada_t* posiciones, int tope_posiciones, coordenada_t* filtrados[TER_FIL], int topes_filtrados[TER_FIL]);

//POST: Encuentra el elemento del arreglo que contiene esa posicion y devuelve su indice.
//      En caso de no encontrar devuelve -1.
size_t encontrar_indice_segun_posicion(void* objeto, tipo_de_objeto_t tipo_de_objeto, int tope, coordenada_t posicion);

//POST: elimina del arreglo el elemento que tenga la posicion especificada.
void eliminar_objeto_segun_posicion(void* objeto, tipo_de_objeto_t tipo_de_objeto, int* tope, coordenada_t posicion);

#endif /* MOSTRAR_H */
