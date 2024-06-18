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
    //Se mueve al inicio de la linea; se mueve abajo la cantidad de veces especificada.
    MOVER_CURSOR_INICIO_LINEA_ABAJO = 'E',
    //Se mueve al inicio de la linea; se mueve arriba la cantidad de veces especificada.
    MOVER_CURSOR_INICIO_LINEA_ARRIBA = 'F'
} movimiento_cursor_t;

//Se puede guardar la posicion del cursor en la terminal y restaurar la previamente guardada.
void cursor(accion_con_cursor_t accion);

//Mueve el cursor al inicio de la terminal
void mover_cursor_inicio();

//Mueve el cursor al inicio de la linea en la que se esté situado en la terminal
void mover_cursor_inicio_linea();

//Mueve la cantidad de veces el movimiento pasado como parametro
void mover_cursor_n_veces(movimiento_cursor_t movimiento, int veces);

//El cursor se mantiene en la misma linea, cambia la posicion horizontal.
void mover_cursor_columna(int col);

//El cursor se mueve a una posicion especifica (fil, col) de la terminal
void mover_cursor_fila_columna(int fil, int col);

//Rellena desde el cursor hasta el final de la pantalla con caracteres vacios ' '
void rellenar_pantalla();

//Rellena desde el cursor hasta el final de la linea con caracteres vacios ' '
void rellenar_linea();

/* 
    Pone el cursor en el inicio de donde se deberia empezar a escribir para que este verticalmente centrado
    ejemplo:
    - el alto del terminal es 100 filas,
    - el contenido, lo que quiero que este verticalmente centrado es de 20 filas
    entonces, el cursor se coloca en la fila 40, para que cuando se escriba el contenido se muestre centrado
*/
void centrar_verticalmente(int filas_contenido);

/* 
    El contenido no puede ser mas de una linea
    Pone el cursor en el inicio de donde se deberia empezar a escribir para que este horizontalmente centrado
    ejemplo:
    - el ancho del terminal es 100 columnas,
    - el contenido, lo que quiero que este horizontalmente centrado es de 20 columnas
    entonces, el cursor se coloca en la columna 40 de la fila actual, para que cuando se escriba el contenido se muestre centrado
*/
void centrar_horizontalmente(int columnas_contenido);

/* 
    Se imprime el texto, que no puede ser mas de una linea, en el centro de la terminal
    El cursor queda en el final del texto.
*/
void imprimir_linea_centrada(const char* texto);

/* 
    Se imprime el texto, que puede ser de varias lineas (con varios '\n'), en el centro de la terminal.
*/
void imprimir_en_el_centro(const char* texto);

#endif /* CURSOR_H */
