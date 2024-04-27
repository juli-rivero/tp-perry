#include "feria.h"
#include "in_out.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand((unsigned)time(NULL)); // Se debe hacer solamente una vez.
    system("clear");
    printf("\v\v\v\v\v\v");
    juego_t juego;
    inicializar_juego(&juego);
    do {
        mostrar_stats(juego);
        imprimir_terreno(juego);
        char accion = recibir_accion();
        realizar_jugada(&juego, accion);
    } while(true);

    return 0;
} 