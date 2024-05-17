#ifndef MI_LIBRERIA_H
#define MI_LIBRERIA_H

#include "feria.h"

// PRE: Se espera un máximo positivo.
// POST: devuelve un numero entre [0 , max_exclusive).
int rand_index(int max_exclusive);

// PRE: Se esperan minimos y máximos positivos.
// POST: devuelve un numero entre [min_inclusive , max_inclusive].
int rand_minI_maxI(int min_inclusive, int max_inclusive);

#endif /* MI_LIBRERIA_H */