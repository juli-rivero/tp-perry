#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include "feria.h"

void perder_vida(juego_t* juego);

void decrementar_timer_bombas(juego_t* juego);

void mover_familia(familiar_t familiares[MAX_FAMILIARES], int tope);

#endif /* OBSTACULOS_H */