#ifndef CURSOR_H
#define CURSOR_H

typedef enum accion_con_cursor {
    GUARDAR_POSICION_CURSOR = 's',
    RESTAURAR_POSICION_CURSOR = 'u'
} accion_con_cursor_t;

typedef enum movimiento_cursor {
    MOVER_CURSOR_ARRIBA = 'A',
    MOVER_CURSOR_ABAJO = 'B',
    MOVER_CURSOR_DERECHA = 'C',
    MOVER_CURSOR_IZQUIERDA = 'D',
    MOVER_CURSOR_INICIO_LINEA_ABAJO = 'E',
    MOVER_CURSOR_INICIO_LINEA_ARRIBA = 'F',
    MOVER_CURSOR_COLUMNA = 'G',
} movimiento_cursor_t;

void cursor(accion_con_cursor_t accion);

void mover_cursor_inicio();

void mover_cursor_inicio_linea();

void mover_cursor_n_veces(movimiento_cursor_t movimiento, int veces);

void mover_cursor_columna(int col);

void mover_cursor_fila_columna(int fil, int col);

#endif /* CURSOR_H */
