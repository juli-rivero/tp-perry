#ifndef TERRENO_H
#define TERRENO_H

#include "constantes.h"
#include "feria.h"


//POST: Genera una posicion, verificando que no sobreeescribe ningun otro objeto dentro del terreno.
// En caso de no haber, devuelve -1 en la coordenada fila.
coordenada_t agarrar_rand_posicion(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]);

//POST: Llena todo el terreno con la constante VACIO.
void vaciar_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]);

#endif /* TERRENO_H */