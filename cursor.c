#include "cursor.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef SECUENCIA
#define SECUENCIA "\033[" // también puede ser \x1b[
#endif /* SECUENCIA */

#ifndef SEPARADOR
#define SEPARADOR ";"
#endif /* SEPARADOR */

void cursor(accion_con_cursor_t accion) {
    printf(SECUENCIA "%c", accion);
}

void mover_cursor_inicio() {
    printf(SECUENCIA "H");
}

void mover_cursor_inicio_linea() {
    printf(SECUENCIA "G");
}

void mover_cursor_columna(int col) {
    printf(SECUENCIA "%d" "G", col);
}

void mover_cursor_fila_columna(int fil, int col) {
    printf(SECUENCIA "%d" SEPARADOR "%d" "H", fil, col);
}

void mover_cursor_n_veces(movimiento_cursor_t movimiento, int veces) {
    printf(SECUENCIA "%d%c", veces, movimiento);
}