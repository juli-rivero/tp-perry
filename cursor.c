#include "cursor.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <math.h>

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


void rellenar_pantalla() {
    mover_cursor_inicio();
    printf(SECUENCIA "J");
}

void rellenar_linea() {
    printf(SECUENCIA "K");
}

void centrar_verticalmente(int filas_contenido) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int height = w.ws_row;
    int padding_vertical = (height - filas_contenido) / 2;
    for (int i = 0; i < padding_vertical; i++) {
        printf("\n");
    }
}

void centrar_horizontalmente(int columnas_contenido) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int width = w.ws_col;
    int padding_horizontal = (int) round(((double)(width - columnas_contenido)) / 2.0);
    mover_cursor_columna(padding_horizontal);
}

void imprimir_linea_centrada(const char* texto) {
    centrar_horizontalmente((int) strlen(texto));
    printf("%s", texto);
}

void imprimir_en_el_centro(const char* texto) {
    int enters = 0;
    int len = (int) strlen(texto);
    for (size_t i = 0; i < len; i++)
        if (texto[i] == '\n') enters++;
    
    centrar_verticalmente(enters);

    int contador_letras = 0;
    while(texto[contador_letras] != '\0') {
        rellenar_linea();
        mover_cursor_inicio_linea();
        int indice_a_imprimir = contador_letras;
        while (texto[contador_letras] != '\n') {
            contador_letras++;
        }
        contador_letras++;
        centrar_horizontalmente(contador_letras - indice_a_imprimir);
        while (indice_a_imprimir < contador_letras) {
            printf("%c", texto[indice_a_imprimir]);
            indice_a_imprimir++;
        }
    }

}
