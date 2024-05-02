#include "feria.h"

#include "constantes.h"
#include "terreno.h"
#include "inicializar.h"
#include "colocar_en_terreno.h"
#include "entrada.h"
#include "mostrar.h"

#include <ctype.h>

void inicializar_juego(juego_t *juego)
{
    char terreno[TER_FIL][TER_COL][MAX_NOMBRE];
    vaciar_terreno(terreno);

    juego->perry = inicializar_personaje(terreno);

    inicializar_bombas(terreno, juego);
    inicializar_herramientas(terreno, juego);
    inicializar_familiares(terreno, juego);
}

void imprimir_terreno(juego_t juego)
{
    char terreno[TER_FIL][TER_COL][MAX_NOMBRE];
    vaciar_terreno(terreno);
    
    colocar_bombas(terreno, juego.tope_bombas, juego.bombas);
    colocar_herramientas(terreno, juego.tope_herramientas, juego.herramientas);
    colocar_familiares(terreno, juego.tope_familiares, juego.familiares);
    colocar_perry(terreno, juego.perry);

    mostrar_terreno(terreno);
}

void realizar_jugada(juego_t *juego, char accion) {
    personaje_t* perry = &(juego->perry);
    switch (toupper(accion))
    {
    case ARRIBA:
        move_arriba_abajo(&(perry->posicion.fil), +1);
        break;
    case ABAJO:
        move_arriba_abajo(&(perry->posicion.fil), -1);
        break;
    case DERECHA:
        move_derecha_izquierda(&(perry->posicion.col), +1);
        break;
    case IZQUIERDA:
        move_derecha_izquierda(&(perry->posicion.col), -1);
        break;
    case CAMUFLARSE:
        perry->camuflado = !perry->camuflado;
        break;
    
    default:
        break;
    }
}

bool bombas_desactivadas(int tope, bomba_t bombas[MAX_BOMBAS]) {
    for (int i = 0; i < tope; i++)
        if (!bombas[i].desactivada)
            return false;
    return true;
}
int estado_juego(juego_t juego) {
    //Perdió?
    if (juego.perry.vida >= 0)
        return -1;

    //Ganó?
    if (bombas_desactivadas(juego.tope_bombas, juego.bombas))
        return 1;

    //No ganó ni perdió.
    return 0;    
}