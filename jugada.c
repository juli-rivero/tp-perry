#include "jugada.h"

#include "constantes.h"
#include "terreno.h"
#include "funciones_objetos.h"
#include "mi_libreria.h"
#include "obstaculos.h"
#include "inicializar.h"

//PRE: 
//  coordenada: columna o fila.
//  sentido: +1 para arriba, -1 para abajo.
//POST: Se cambia la coordenada sin salirse del terreno.
coordenada_t mover_arriba_abajo(coordenada_t posicion, int sentido) {
    posicion.fil -= sentido;
    if(posicion.fil <= 0) posicion.fil = 0;
    if(posicion.fil >= TER_FIL) posicion.fil = TER_FIL - 1;
    return posicion;
}

//PRE: 
//  coordenada: columna o fila.
//  sentido: +1 para derecha, -1 para izquierda.
//POST: Se cambia la coordenada sin salirse del terreno.
coordenada_t mover_derecha_izquierda(coordenada_t posicion, int sentido) {
    posicion.col += sentido;
    if(posicion.col <= 0) posicion.col = 0;
    if(posicion.col >= TER_COL) posicion.col = TER_COL - 1;
    return posicion;
}

coordenada_t mover(coordenada_t posicion, char sentido) {
    switch (sentido)
    {
    case ARRIBA:
        return mover_arriba_abajo(posicion, +1);
    case ABAJO:
        return mover_arriba_abajo(posicion, -1);
    case DERECHA:
        return mover_derecha_izquierda(posicion, +1);
    case IZQUIERDA:
        return mover_derecha_izquierda(posicion, -1);
    }
    return (coordenada_t) {-1, -1};
}


void comprobar_posicion(juego_t* juego) {
    coordenada_t p_posicion = juego->perry.posicion;
    switch (visualizacion_de_posicion(*juego, juego->perry.posicion)) {
        case SOMBREROS:
            (juego->perry.vida)++;
            eliminar_objeto_segun_posicion(
                juego->herramientas, 
                TIPO_HERRAMIENTA, 
                &(juego->tope_herramientas), 
                p_posicion
                );
            break;
        case GOLOSINAS:
            juego->perry.energia += 10;
            eliminar_objeto_segun_posicion(
                juego->herramientas, 
                TIPO_HERRAMIENTA, 
                &(juego->tope_herramientas), 
                p_posicion
                );
            break;
        case BOMBAS:
            if (!juego->perry.camuflado && juego->perry.energia >= 10) {//Si está modo agente y tiene energia suficiente
                juego->perry.energia -= 10;
                size_t indice = encontrar_indice_segun_posicion(
                    juego->bombas, 
                    TIPO_BOMBA, 
                    juego->tope_bombas, 
                    p_posicion
                );
                juego->bombas[indice].desactivada = true;
            }
            break;
    }
    for (int i = 0; i < juego->tope_familiares; i++) 
        if (
            !juego->perry.camuflado && //Si esta en modo agente
            calcular_distancia(p_posicion, juego->familiares[i].posicion) <= DIST_FAMILIA
        ) 
            perder_vida(juego);
    for (int i = 0; i < juego->cantidad_robots; i++)
        if (calcular_distancia(p_posicion, juego->robots[i]) <= DIST_ROBOTS) {
            if (!juego->perry.camuflado && juego->perry.energia > 5) { //Si esta en modo agente 
                eliminar_robot(juego, i);
                juego->perry.energia -= 5;
            } else {
                perder_vida(juego);
            }
        }
    
    

}