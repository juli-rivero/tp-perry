#include "utils.h"

#include <stdlib.h>
#include <math.h>

int rand_index(int max_exclusive)
{
    return rand() % max_exclusive;
}

int rand_min_inclusive_max_inclusive(int min_inclusive, int max_inclusive)
{
    return rand() % (max_inclusive - min_inclusive + 1) + min_inclusive;
}


bool son_pos_iguales(coordenada_t pos1, coordenada_t pos2) {
    return (pos1.fil == pos2.fil && pos1.col == pos2.col);
}


int calcular_distancia(coordenada_t pos1, coordenada_t pos2) {
    return abs(pos1.fil - pos2.fil) + abs(pos1.col - pos2.col);
}