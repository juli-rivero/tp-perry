#ifndef INICIALIZAR_H
#define INICIALIZAR_H

#include "feria.h"
#include "constantes.h"
#include "tipos_de_datos.h"


personaje_t inicializar_personaje(styled_char terreno[TER_FIL][TER_COL]);

void inicializar_bombas(styled_char terreno[TER_FIL][TER_COL], juego_t* juego);

void inicializar_herramientas(styled_char terreno[TER_FIL][TER_COL], juego_t* juego);

void inicializar_familiares(styled_char terreno[TER_FIL][TER_COL], juego_t* juego);

#endif /* INICIALIZAR_H */