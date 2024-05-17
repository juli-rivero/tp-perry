#include "mostrar.h"

#include <stdio.h>
#include <wchar.h>

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

    wprintf(L" %lc%d\t", VISTA_ENERGIA, perry.energia);
    
    for (int i=0; i<perry.vida; i++)
        wprintf(L"%lc",VISTA_VIDA);
    
    if(!perry.camuflado)
        wprintf(L"\t\t\t\t%lc", VISTA_AGENTE);
    
    printf("\n");
}