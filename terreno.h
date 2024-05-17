#ifndef TERRENO_H
#define TERRENO_H

#include "constantes.h"
#include "feria.h"
#include "tipos_de_datos.h"

//PRE: Los topes deben estar bien definidos con respecto a sus vectores
//POST: Retorna el caracter que representa la posicion en el terreno
char visualizacion_de_posicion(juego_t juego, coordenada_t posicion);

//PRE: Los topes deben estar bien definidos con respecto a sus vectores
//POST: Genera una posicion, verificando que no sobreeescribe ningun otro objeto dentro del terreno.
// En caso de no haber, devuelve -1 en la coordenada fila.
coordenada_t agarrar_rand_posicion(juego_t juego);

//POST: Llena todo el terreno con la constante VACIO.
void vaciar_terreno(styled_char terreno[TER_FIL][TER_COL]);

#endif /* TERRENO_H */