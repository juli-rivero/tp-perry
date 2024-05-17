#include "inicializar.h"

#include "terreno.h"
#include "mi_libreria.h"

personaje_t inicializar_personaje() {
    return (personaje_t) {
        I_VIDA,
        I_ENERGIA,
        I_CAMUFLADO,
        {rand_index(TER_FIL), rand_index(TER_COL)}
    };
}

bomba_t inicializar_bomba(juego_t juego) {
    return (bomba_t) {
        agarrar_rand_posicion(juego),
        rand_minI_maxI(TIEMPO_MIN, TIEMPO_MAX),
        false
    };
}
void inicializar_bombas(juego_t* juego) {
    int* tope = &(juego->tope_bombas);
    for (*tope = 0; *tope < I_CANT_BOMBAS; (*tope)++)
        juego->bombas[*tope] = inicializar_bomba(*juego);
}

herramienta_t inicializar_herramienta(juego_t juego, char tipo) {
    return (herramienta_t) {
        agarrar_rand_posicion(juego),
        tipo
    };

}
void inicializar_herramientas(juego_t* juego) {
    int* tope = &(juego->tope_herramientas);
    for (*tope = 0; *tope < I_CANT_SOMBREROS + I_CANT_GOLOSINAS; (*tope)++)
        juego->herramientas[*tope] = 
            inicializar_herramienta(*juego, (*tope < I_CANT_SOMBREROS) ? SOMBREROS : GOLOSINAS);
}

familiar_t inicializar_familiar(juego_t juego, char sentido, char inicial_nombre) {
    return (familiar_t) {
        agarrar_rand_posicion(juego),
        sentido,
        inicial_nombre
    };
}
void inicializar_familiares(juego_t* juego) {
    familiar_t* familiares = juego->familiares;
    int* tope = &(juego->tope_familiares);

    *tope = 0;
    familiares[(*tope)++] = inicializar_familiar(*juego, DERECHA, PHINEAS);
    familiares[(*tope)++] = inicializar_familiar(*juego, IZQUIERDA, FERB);
    familiares[(*tope)++] = inicializar_familiar(*juego, ARRIBA, CANDACE);
    printf("%d", *tope);
}
void inicializar_topes(juego_t* juego) {
    juego->tope_bombas = 0;
    juego->tope_herramientas = 0;
    juego->tope_familiares = 0;
}