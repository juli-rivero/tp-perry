#ifndef IMPRIMIR_TERRENO_H
#define IMPRIMIR_TERRENO_H

#include "feria.h"
#include "estilos.h"
#include "constantes.h"

//POST: Se colocan las B (customizadas) en el terreno
void colocar_bombas(terreno_t terreno, bomba_t bombas[MAX_BOMBAS], int tope);

//POST: Se colocan las G o S (customizadas) en el terreno
void colocar_herramientas(terreno_t terreno, herramienta_t herramientas[MAX_HERRAMIENTAS], int tope);

//POST: Se colocan las C, H o F (customizadas) en el terreno
void colocar_familiares(terreno_t terreno, familiar_t familiares[MAX_FAMILIARES], int tope);

//POST: Se colocan la P (customizada) en el terreno
void colocar_perry(terreno_t terreno, personaje_t perry);

//POSR: Se colocan las R (customizadas) en el terreno
void colocar_robots(terreno_t terreno, coordenada_t* robots, int tope);

//POST: coloca detalles como el fondo de color diferente a familiares y sus alrededores.
void colocar_estilos(terreno_t terreno, juego_t juego);

#endif /* IMPRIMIR_TERRENO_H */