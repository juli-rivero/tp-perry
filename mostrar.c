#include "mostrar.h"

#include "mi_libreria.h"
#include "cursor.h"

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "conio.h"
#include <string.h>

const int alto_contenido = TER_FIL + 2;
const int ancho_contenido = TER_COL * 2 + 3;
void mostrar_terreno(terreno_t terreno) {
    centrar_horizontalmente(ancho_contenido);
    printf("┏");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("━");
    printf("┓\n");
    for (int i = 0; i < TER_FIL; i++) {
        centrar_horizontalmente(ancho_contenido);
        printf("┃ ");
        for (int j = 0; j < TER_COL; j++) {
            if (get_caracter(terreno[i][j]) == PERRY)
                cursor(GUARDAR_POSICION_CURSOR);
            imprimir_styled_char(terreno[i][j]);
            printf(" ");
        }
        printf("┃\n");
    }
    centrar_horizontalmente(ancho_contenido);
    printf("┗");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("━");
    printf("┛\n\n");
    cursor(RESTAURAR_POSICION_CURSOR);
    reset_estilo();
}

void mostrar_stats(personaje_t perry) {
    system("clear");
    centrar_verticalmente(alto_contenido);

    reset_estilo();
    
    centrar_horizontalmente(ancho_contenido);
    printf("┏");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("━");
    printf("┓\n");

    centrar_horizontalmente(ancho_contenido);
    
    printf("┃");
    cursor(GUARDAR_POSICION_CURSOR);
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf(" ");
    printf("┃");
    printf("\n");

    cursor(RESTAURAR_POSICION_CURSOR);
    printf("%lc%d\t", VISTA_ENERGIA, perry.energia);
    
    imprimir_estilo(NORMAL, ROJO, TEXTO_BRILLANTE, DEFAULT_COLOR, FONDO_NORMAL);
    if (perry.vida <= 0)
        printf("(SIN VIDAS)");
    else 
        for (int i=0; i<perry.vida; i++)
            printf("%lc",VISTA_VIDA);
    reset_estilo();
    
    cursor(RESTAURAR_POSICION_CURSOR);
    mover_cursor_n_veces(MOVER_CURSOR_DERECHA, TER_COL * 2 - 1);
    if(!perry.camuflado)
        printf("%lc", VISTA_AGENTE);
    mover_cursor_n_veces(MOVER_CURSOR_INICIO_LINEA_ABAJO, 1);   
}

void imprimir_mensaje_final(juego_t juego) {
    mover_cursor_inicio();
    centrar_verticalmente(1);
    char* mensaje = NULL;
    if (estado_juego(juego) == GANADO) {
        imprimir_estilo(BOLD, VERDE, TEXTO_BRILLANTE, DEFAULT_COLOR, FONDO_NORMAL);
        mensaje = "¡El area limitrofe está a salvo!";
    } else {
        imprimir_estilo(BOLD, ROJO, TEXTO_NORMAL, DEFAULT_COLOR, FONDO_NORMAL);
        mensaje = "GAME OVER";
    }
    cursor(GUARDAR_POSICION_CURSOR);
    imprimir_linea_centrada(mensaje);
    mover_cursor_inicio();
    reset_estilo();
    c_getch();
    cursor(RESTAURAR_POSICION_CURSOR);
    int len = (int) strlen(mensaje);
    centrar_horizontalmente(len);
    for (int i=0; i < len; i++)
        printf(" ");

    
}