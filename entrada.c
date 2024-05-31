#include "entrada.h"

#include "constantes.h"
#include "mi_libreria.h"

#include <stdio.h>
#include <ctype.h>
#include "conio.h"
#include "estilos.h"
#include "cursor.h"

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
char recibir_accion() {
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

bool desea_seguir_jugando() {
    mover_cursor_inicio();
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
