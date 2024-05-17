#ifndef INICIALIZAR_H
#define INICIALIZAR_H

#include "feria.h"
#include "constantes.h"
#include "tipos_de_datos.h"


personaje_t inicializar_personaje();

void inicializar_topes(juego_t* juego);

void inicializar_bombas(juego_t* juego);

void inicializar_herramientas(juego_t* juego);

void inicializar_familiares(juego_t* juego);

#endif /* INICIALIZAR_H */