#ifndef TERRENO_H
#define TERRENO_H

#include "constantes.h"
#include "feria.h"
#include "tipos_de_datos.h"

//POST: Genera una posicion, verificando que no sobreeescribe ningun otro objeto dentro del terreno.
// En caso de no haber, devuelve -1 en la coordenada fila.
coordenada_t agarrar_rand_posicion(styled_char terreno[TER_FIL][TER_COL]);

//POST: Llena todo el terreno con la constante VACIO.
void vaciar_terreno(styled_char terreno[TER_FIL][TER_COL]);

#endif /* TERRENO_H */