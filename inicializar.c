#include "inicializar.h"

#include "terreno.h"
#include "mi_libreria.h"

personaje_t inicializar_personaje(styled_char terreno[TER_FIL][TER_COL]) {
    return (personaje_t) {
        I_VIDA,
        I_ENERGIA,
        I_CAMUFLADO,
        agarrar_rand_posicion(terreno)
    };
}

bomba_t inicializar_bomba(styled_char terreno[TER_FIL][TER_COL]) {
    return (bomba_t) {
        agarrar_rand_posicion(terreno),
        rand_minI_maxI(TIEMPO_MIN, TIEMPO_MAX),
        false
    };
}
void inicializar_bombas(styled_char terreno[TER_FIL][TER_COL], juego_t* juego) {
    juego->tope_bombas = I_CANT_BOMBAS;
    for (int i = 0; i < juego->tope_bombas; i++) {
        juego->bombas[i] = inicializar_bomba(terreno);
    }
}

herramienta_t inicializar_herramienta(styled_char terreno[TER_FIL][TER_COL], char tipo) {
    return (herramienta_t) {
        agarrar_rand_posicion(terreno),
        tipo
    };

}
void inicializar_herramientas(styled_char terreno[TER_FIL][TER_COL], juego_t* juego) {
    juego->tope_herramientas = I_CANT_SOMBREROS + I_CANT_GOLOSINAS;
    for (int i = 0; i < juego->tope_herramientas; i++)
        juego->herramientas[i] = 
            inicializar_herramienta(terreno, (i < I_CANT_SOMBREROS) ? SOMBREROS : GOLOSINAS);
}

familiar_t inicializar_familiar(styled_char terreno[TER_FIL][TER_COL], char inicial_nombre) {
    return (familiar_t) {
        agarrar_rand_posicion(terreno),
        inicial_nombre
    };
}
void inicializar_familiares(styled_char terreno[TER_FIL][TER_COL], juego_t* juego) {
    juego->tope_familiares = I_CANT_FAMILIA;
    juego->familiares[0] = inicializar_familiar(terreno, PHINEAS);
    juego->familiares[1] = inicializar_familiar(terreno, FERB);
    juego->familiares[2] = inicializar_familiar(terreno, CANDACE);
}