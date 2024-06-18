#include "constantes.h"
#include "feria.h"

#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <ctype.h>

#include "conio.h"
#include "cursor.h"
#include "estilos.h"

// Devuelve true en caso de que el caracter sea uno del enum accion, en caso contrario devuelve false
bool es_caracter_valido(int entrada) {
    switch ((char) toupper(entrada)) {
        case ARRIBA:
        case ABAJO:
        case DERECHA:
        case IZQUIERDA:
        case CAMUFLARSE:
            return true;
        default:
            return false;
    }
}
/* Solicita por consola una accion valida.
    - En caso de que la accion sea valida en el primer intento, devuelve la accion
    - En caso de que no sea valida, se muestra en medio de pantalla un mensaje de "Caracter no valido" con una lista de los caracteres validos, y se vuelve a solicitar hasta que esta sea valida. Cuando el caracter es valido, devuelve false. Esto se hace con el proposito de que esté en un while y que se pueda limpiar la pantalla, solicitando de nuevo el caracter una vez el terreno sea completamente visible.
*/
accion_t recibir_accion() {
    int entrada;
    do { entrada = c_getch(); } while (entrada == '\n' || entrada == EOF); 

    if (es_caracter_valido((char) entrada)) {
    
        return (char) toupper(entrada);
    
    } else {
        mover_cursor_inicio();
        
        imprimir_estilo(NORMAL, ROJO, TEXTO_NORMAL, DEFAULT_COLOR, FONDO_NORMAL);
        
        imprimir_en_el_centro(
            " \n"
            "Caracter no valido.\n"
            "Para moverse presione:\n"
            "W (ARRIBA) - S (ABAJO) - D (DERECHA) - A (IZQUIERDA).\n"
            "Para habilidades presione:\n"
            "Q (CAMUFARSE)\n"
            " \n"
        );
        cursor(GUARDAR_POSICION_CURSOR);
        rellenar_linea();
        cursor(RESTAURAR_POSICION_CURSOR);
        imprimir_linea_centrada("CARACTER PRESIONADO: ");
        cursor(GUARDAR_POSICION_CURSOR);
        printf("\n");
        rellenar_linea();
        do {
            cursor(RESTAURAR_POSICION_CURSOR);
            printf("%c", entrada);
            cursor(RESTAURAR_POSICION_CURSOR);
            do { entrada = c_getch(); } while (entrada == '\n' || entrada == EOF);
        } while (!es_caracter_valido((char) entrada));
        
        reset_estilo();

        return false;
    }
}

//  Imprime si se perdió o se ganó
void imprimir_mensaje_final(estado_juego_t estado) {
    reset_estilo();
    rellenar_pantalla();

    centrar_verticalmente(1);

    if (estado == GANADO) {
        imprimir_estilo(BOLD, VERDE, TEXTO_BRILLANTE, DEFAULT_COLOR, FONDO_NORMAL);
        imprimir_linea_centrada("¡El area limitrofe está a salvo!\n");
    } else {
        imprimir_estilo(BOLD, ROJO, TEXTO_NORMAL, DEFAULT_COLOR, FONDO_NORMAL);
        imprimir_linea_centrada("GAME OVER\n");
    }
    imprimir_estilo(DIM, DEFAULT_COLOR, TEXTO_NORMAL, DEFAULT_COLOR, FONDO_NORMAL);
    imprimir_linea_centrada("[Presionar cualquier letra...]  \n");
    c_setcursortype(_NOCURSOR);
    c_getch();
    c_setcursortype(_SOLIDCURSOR);    
}

//Consulta si desea seguir jugando y devuelve la respuesta.
bool desea_seguir_jugando() {
    reset_estilo();
    rellenar_pantalla();    
    centrar_verticalmente(1);
    reset_estilo();
    imprimir_linea_centrada("¿Desea seguir jugando? ");
    cursor(GUARDAR_POSICION_CURSOR);
    printf("S N");
    cursor(RESTAURAR_POSICION_CURSOR);
    bool seguir_jugando = true;

    const int ENTER = 10;
    int entrada;
    do {
        entrada = c_getch(); 
        if (toupper(entrada) == IZQUIERDA) {
            cursor(RESTAURAR_POSICION_CURSOR);
            seguir_jugando = true;
        }
        if (toupper(entrada) == DERECHA) {
            cursor(RESTAURAR_POSICION_CURSOR);
            mover_cursor_n_veces(MOVER_CURSOR_DERECHA, 2);
            seguir_jugando = false;
        }
    } while (entrada != ENTER);
    
    return seguir_jugando;
}

int main() {
    setlocale(LC_ALL, ""); // Para UTF-8
    srand((unsigned)time(NULL)); // Se debe hacer solamente una vez.
    
    do {
        juego_t juego;
        estado_juego_t estado;
        inicializar_juego(&juego);

        do {
            system("clear");
            imprimir_terreno(juego);

            accion_t accion = recibir_accion();
            if (accion == false)
                continue;
                
            realizar_jugada(&juego, accion);
        } while((estado = estado_juego(juego)) == EN_JUEGO);

        imprimir_mensaje_final(estado);
    } while (desea_seguir_jugando());

    system("clear");
    return 0;
} 