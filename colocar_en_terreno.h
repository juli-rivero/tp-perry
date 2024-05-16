#ifndef IMPRIMIR_TERRENO_H
#define IMPRIMIR_TERRENO_H

#include "feria.h"
#include "tipos_de_datos.h"
#include "constantes.h"

//POST: Se colocan las B (customizadas) en el terreno
void colocar_bombas(styled_char terreno[TER_FIL][TER_COL], int tope, bomba_t bombas[MAX_BOMBAS]);

//POST: Se colocan las G o S (customizadas) en el terreno
void colocar_herramientas(styled_char terreno[TER_FIL][TER_COL], int tope, herramienta_t herramientas[MAX_HERRAMIENTAS]);

//POST: Se colocan las C, H o F (customizadas) en el terreno
void colocar_familiares(styled_char terreno[TER_FIL][TER_COL], int tope, familiar_t familiares[MAX_FAMILIARES]);

//POST: Se colocan la P (customizada) en el terreno
void colocar_perry(styled_char terreno[TER_FIL][TER_COL], personaje_t perry);

#endif /* IMPRIMIR_TERRENO_H */