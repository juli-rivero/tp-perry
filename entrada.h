#ifndef ENTRADA_H
#define ENTRADA_H

#include "feria.h"

//POST: Solicita y retorna una accion valida de consola.
char recibir_accion();


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

#endif /* ENTRADA_H */