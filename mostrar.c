#include "mostrar.h"

#include "mi_libreria.h"

#include <stdio.h>

void mostrar_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]) {
    printf("⌌");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("—");
    printf("⌍\n");
    for (int i = 0; i < TER_FIL; i++) {
        printf("| ");
        for (int j = 0; j < TER_COL; j++) {
            printf("%s ", terreno[i][j]);
        }
        printf("|\n");
    }
    printf("⌎");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("—");
    printf("⌏\n");
}

void mostrar_stats(juego_t juego) {
    printf(" %s%d\t", VISTA_ENERGIA, juego.perry.energia);
    printf(" %s", repetir_str(VISTA_VIDA, juego.perry.vida));
    if(juego.perry.camuflado)
        printf("\t\t\t\t%s", VISTA_CAMUFLAJE);
    printf("\n");
}