#ifndef MOSTRAR_H
#define MOSTRAR_H

#include "constantes.h"
#include "feria.h"
#include "tipos_de_datos.h"

//POST: Imprime por consola el terreno.
void mostrar_terreno(styled_char terreno[TER_FIL][TER_COL]);

//POST: Imprime por consola las estadisticas de perry.
void mostrar_stats(personaje_t perry);

#endif /* MOSTRAR_H */
