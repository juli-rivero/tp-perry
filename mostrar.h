#ifndef MOSTRAR_H
#define MOSTRAR_H

#include "constantes.h"
#include "feria.h"
#include "estilos.h"

//POST: Imprime por consola el terreno.
void mostrar_terreno(terreno_t terreno);

//POST: Imprime por consola las estadisticas de perry.
void mostrar_stats(personaje_t perry);

void imprimir_mensaje_final(juego_t juego);

#endif /* MOSTRAR_H */
