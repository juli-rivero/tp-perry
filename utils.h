#ifndef UTILS_H
#define UTILS_H

#include "feria.h"

// PRE: Se espera un máximo positivo.
// POST: devuelve un numero entre [0 , max_exclusive).
int rand_index(int max_exclusive);

// PRE: Se esperan minimos y máximos positivos.
// POST: devuelve un numero entre [min_inclusive , max_inclusive].
int rand_min_inclusive_max_inclusive(int min_inclusive, int max_inclusive);

//POST: Comprueba si las dos posiciones son iguales
bool son_pos_iguales(coordenada_t pos1, coordenada_t pos2);

//POST: Calcula la distancia manhatan entre dos posiciones.
int calcular_distancia(coordenada_t pos1, coordenada_t pos2);

#endif /* UTILS_H */