#ifndef INICIALIZAR_H
#define INICIALIZAR_H

#include "feria.h"
#include "constantes.h"


personaje_t inicializar_personaje(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]);

void inicializar_bombas(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], juego_t* juego);

void inicializar_herramientas(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], juego_t* juego);

void inicializar_familiares(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], juego_t* juego);

#endif /* INICIALIZAR_H */