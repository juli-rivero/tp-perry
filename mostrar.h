#ifndef MOSTRAR_H
#define MOSTRAR_H

#include "constantes.h"
#include "feria.h"

//POST: Imprime por consola el terreno.
void mostrar_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]);

//POST: Imprime por consola las estadisticas de perry.
void mostrar_stats(juego_t juego);

#endif /* MOSTRAR_H */
