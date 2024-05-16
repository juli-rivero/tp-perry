#include "entrada.h"

#include "constantes.h"
#include "mi_libreria.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "conio.h"
#include "colores.h"

char recibir_accion() {
    int entrada;
    do {
        //entrada = getchar();
        entrada = c_getche();
    } while (entrada == '\n' || entrada == EOF); 
    char accion = (char) entrada;
    system("clear");
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
            printf("\v" RESET);
            break;
    }
    return accion;
}

void mover_arriba_abajo(int* coordenada, int sentido) {
    *coordenada -= sentido;
    if(*coordenada <= 0) *coordenada = 0;
    if(*coordenada >= TER_FIL) *coordenada = TER_FIL - 1;
}

void mover_derecha_izquierda(int* coordenada, int sentido) {
    *coordenada += sentido;
    if(*coordenada <= 0) *coordenada = 0;
    if(*coordenada >= TER_COL) *coordenada = TER_COL - 1;
}