#include "mostrar.h"

#include "mi_libreria.h"

#include <stdio.h>

void mostrar_terreno(styled_char terreno[TER_FIL][TER_COL]) {
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

void mostrar_stats(personaje_t perry) {
    printf(" %s%d\t", VISTA_ENERGIA, perry.energia);
    printf(" %s", repetir_str(VISTA_VIDA, perry.vida));
    if(perry.camuflado)
        printf("\t\t\t\t%s", VISTA_CAMUFLAJE);
    printf("\n");
}