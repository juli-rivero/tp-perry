#include "jugadas.h"

#include "constantes.h"
#include "terreno.h"

void mover_arriba_abajo(int* coordenada, int sentido) {
    *coordenada -= sentido;
    if(*coordenada <= 0) *coordenada = 0;
    if(*coordenada >= TER_FIL) *coordenada = TER_FIL - 1;
}

void mover_derecha_izquierda(int* coordenada, int sentido) {
    *coordenada += sentido;
    if(*coordenada <= 0) *coordenada = 0;
    if(*coordenada >= TER_COL) *coordenada = TER_COL - 1;
}

void comprobar_posicion(juego_t* juego) {
    /* switch (visualizacion_de_posicion(*juego, juego->perry.posicion)) {

    } */
}