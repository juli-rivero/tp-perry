#include "in_out.h"
#include "constantes.h"
#include "mi_libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "conio.h"
#include "colores.h"

char recibir_accion() {
    int entrada;
    do {
        //accion = (char) getchar();
        entrada = c_getche();
    } while (entrada == '\n' || entrada == EOF); 
    system("clear");
    char accion = (char) entrada;
    switch (toupper(accion)) {
        case ARRIBA:
        case ABAJO:
        case DERECHA:
        case IZQUIERDA:
        case CAMUFLARSE:
            printf("\v\v\v\v\v\v");
            break;
        default:
            printf(ROJO_T"ERROR: caracter no valido.\n");
            printf("Para moverse presione:\n");
            printf("\t%c (ARRIBA) - %c (ABAJO) - %c (DERECHA) - %c (IZQUIERDA).\n", ARRIBA, ABAJO, DERECHA, IZQUIERDA);
            printf("Para habilidades presione:\n\t%c (CAMUFARSE)\n", CAMUFLARSE);
            accion = NO_VALIDO;
            printf("\v" RESET_COLOR);
            break;
    }
    return accion;
}

void mostrar_stats(juego_t juego) {
    printf(" %s%d\t", VISTA_ENERGIA, juego.perry.energia);
    printf(" %s", repetir_str(VISTA_VIDA, juego.perry.vida));
    if(juego.perry.camuflado)
        printf("\t\t\t\t%s", VISTA_CAMUFLAJE);
    printf("\n");
}