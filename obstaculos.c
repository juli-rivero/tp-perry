#include "obstaculos.h"

#include "jugada.h"
#include "constantes.h"
#include "mi_libreria.h"
#include "funciones_objetos.h"
#include "estilos.h"
#include "conio.h"

void perder_vida(juego_t* juego) {
    (juego->perry.vida)--;
    imprimir_estilo(NORMAL, DEFAULT_COLOR, TEXTO_NORMAL, ROJO, FONDO_NORMAL);
    rellenar_pantalla();
    reset_estilo();
}

void decrementar_timer_bombas(juego_t* juego) {
    for (int i = 0; i < juego->tope_bombas; i++) {
        bomba_t* bomba = &(juego->bombas[i]);
        if (!(bomba->desactivada)) {
            (bomba->timer)--;
            if (bomba->timer < 0) {
                perder_vida(juego);
                bomba->desactivada = true;
            }
        }
    }
}

char cambiar_sentido(char sentido) {
    switch (sentido)
        {
        case ARRIBA:
            sentido = ABAJO;
            break;
        case ABAJO:
            sentido = ARRIBA;
            break;
        case DERECHA:
            sentido = IZQUIERDA;
            break;
        case IZQUIERDA:
            sentido = DERECHA;
            break;
        }
    return sentido;
}
void mover_y_cambiar_sentido(coordenada_t* posicion, char* sentido) {
    coordenada_t nueva_posicion = mover(*posicion, *sentido);
    if (son_pos_iguales(*posicion, nueva_posicion)){
        *sentido = cambiar_sentido(*sentido);
        nueva_posicion = mover(*posicion, *sentido);
    }
    *posicion = nueva_posicion;
}

void mover_familia(familiar_t familiares[MAX_FAMILIARES], int tope) {
    for (int i = 0; i<tope; i++)
        mover_y_cambiar_sentido(&(familiares[i].posicion), &(familiares[i].sentido));
}