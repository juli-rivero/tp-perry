#include "feria.h"

#include "constantes.h"
#include "terreno.h"
#include "estilos.h"
#include "inicializar.h"
#include "colocar_en_terreno.h"
#include "jugada.h"
#include "mostrar.h"
#include "obstaculos.h"

#include <ctype.h>

#include <stdio.h>
void inicializar_juego(juego_t *juego)
{
    juego->movimientos = 0;
    juego->perry = crear_personaje();
    inicializar_topes(juego);
    inicializar_bombas(juego);
    inicializar_herramientas(juego);
    inicializar_familiares(juego);
    inicializar_robots(juego);
}

void imprimir_terreno(juego_t juego)
{
    terreno_t terreno;
    crear_terreno(terreno);
    
    colocar_bombas(terreno, juego.bombas, juego.tope_bombas);
    colocar_herramientas(terreno, juego.herramientas, juego.tope_herramientas);
    colocar_familiares(terreno, juego.familiares, juego.tope_familiares);
    colocar_robots(terreno, juego.robots, juego.cantidad_robots);
    colocar_perry(terreno, juego.perry);

    colocar_estilos(terreno, juego);
    mostrar_terreno(terreno);
}

void realizar_jugada(juego_t *juego, char accion) {
    personaje_t* perry = &(juego->perry);
    switch (accion)
    {
    case CAMUFLARSE:
        perry->camuflado = !perry->camuflado;
        break;
    
    default:
        perry->posicion = mover(perry->posicion, accion);
        (juego->movimientos)++;
        if (juego->movimientos % 10 == 0)
            agregar_robot(juego);
        decrementar_timer_bombas(juego);
        mover_familia(juego->familiares, juego->tope_familiares);
        comprobar_posicion(juego);
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
    //Ganó?
    if (bombas_desactivadas(juego.tope_bombas, juego.bombas))
        return GANADO;

    //Perdió?
    if (juego.perry.vida <= 0)
        return GAME_OVER;

    //No ganó ni perdió.
    return EN_JUEGO;    
}