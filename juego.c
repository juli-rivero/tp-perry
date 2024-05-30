#include "feria.h"
#include "entrada.h"
#include "mostrar.h"
#include "inicializar.h"

#include <stdlib.h>
#include <time.h>
#include <locale.h>

void handler(int sig) {
    // necesario para evitar que la señal cierre el programa.
}

int main() {
    setlocale(LC_ALL, ""); // Para UTF-8
    srand((unsigned)time(NULL)); // Se debe hacer solamente una vez.
    
    do {
        juego_t juego;
        inicializar_juego(&juego);

        do {
            mostrar_stats(juego.perry);
            imprimir_terreno(juego);

            char accion = recibir_accion();
            if (accion == NO_VALIDO)
                continue;
                
            realizar_jugada(&juego, accion);
        } while(estado_juego(juego) == EN_JUEGO);

        mostrar_stats(juego.perry);
        imprimir_terreno(juego);
        
        liberar_memoria(&juego);
        imprimir_mensaje_final(juego);
    } while (desea_seguir_jugando());

    system("clear");
    return 0;
} 