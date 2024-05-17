#ifndef JUGADAS_H
#define JUGADAS_H

#include "feria.h"

//PRE: 
//  coordenada: columna o fila.
//  sentido: +1 para arriba, -1 para abajo.
//POST: Se cambia la coordenada sin salirse del terreno.
void mover_arriba_abajo(int* coordenada, int sentido);

//PRE: 
//  coordenada: columna o fila.
//  sentido: +1 para derecha, -1 para izquierda.
//POST: Se cambia la coordenada sin salirse del terreno.
void mover_derecha_izquierda(int* coordenada, int sentido);

//POST: Comprueba donde esta posicionado perry y toma acción al respecto.
void comprobar_posicion();

#endif /* JUGADAS_H */