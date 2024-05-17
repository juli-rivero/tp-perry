#include "mi_libreria.h"

#include <stdlib.h>

int rand_index(int max_exclusive)
{
    return rand() % max_exclusive;
}

int rand_minI_maxI(int min_inclusive, int max_inclusive)
{
    return rand() % (max_inclusive - min_inclusive + 1) + min_inclusive;
}

