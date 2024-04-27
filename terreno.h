#ifndef TERRENO_H
#define TERRENO_H

#include "constantes.h"
#include "structs.h"
#include "feria.h"

/*  Funciona pero descartado porque despues se tiene que volver a usar y es, por esta razón, más eficiente la otra que se usa. 

//POST: Devuelve un terreno con las posiciones en cada posicion del vector.
ter_disponible_t inicializar_ter_disponible();

//POST: Genera una posicion, verificando que no sobreeescribe ningun otro objeto dentro del terreno.
coordenada_t init_rand_posicion(ter_disponible_t* ter_disponible);
*/

//POST: Genera una posicion, verificando que no sobreeescribe ningun otro objeto dentro del terreno.
// En caso de no haber, devuelve -1 en la coordenada fila.
coordenada_t agarrar_rand_posicion(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]);

//POST: Coloca en la posicion del terreno recibida, el nombre recibido.
void colocar_en_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], coordenada_t posicion, char nombre[MAX_NOMBRE]);

//POST: Llena todo el terreno con la constante VACIO.
void vaciar_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]);

//POST: Imprime por consola el terreno.
void mostrar_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]);

//PRE: 
//  coordenada: columna o fila.
//  sentido: +1 para arriba, -1 para abajo.
//POST: Se cambia la coordenada sin salirse del terreno.
void move_arriba_abajo(int* coordenada, int sentido);

//PRE: 
//  coordenada: columna o fila.
//  sentido: +1 para derecha, -1 para izquierda.
//POST: Se cambia la coordenada sin salirse del terreno.
void move_derecha_izquierda(int* coordenada, int sentido);

#endif /* TERRENO_H */