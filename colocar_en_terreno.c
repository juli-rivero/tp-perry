#include "colocar_en_terreno.h"

#include "estilos.h"
#include "jugada.h"
#include "terreno.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>

void colocar_bombas(terreno_t terreno, bomba_t bombas[MAX_BOMBAS], int tope) {
    for (int i = 0; i < tope; i++) {
        if (!bombas[i].desactivada){
            
            styled_char_t* s_char = terreno[bombas[i].posicion.fil][bombas[i].posicion.col];
            set_caracter(s_char, BOMBAS);

            int timer = bombas[i].timer;
            if (timer < ADVERT_ROJA) {
                set_color_texto(s_char, ROJO);
                set_estilo(s_char, BLINK_FAST);
            } else if (timer < ADVERT_AMARILLA) {
                set_estilo(s_char, BLINK_FAST);
            } else {
                set_estilo(s_char, BLINK_SLOW);
            }
        }
    }
}

void colocar_herramientas(terreno_t terreno, herramienta_t herramientas[MAX_HERRAMIENTAS], int tope) {
    for (int i = 0; i < tope; i++) {
        styled_char_t* s_char = terreno[herramientas[i].posicion.fil][herramientas[i].posicion.col];

        set_caracter(s_char, herramientas[i].tipo);
        set_estilo(s_char, DIM);        
    }
}

void colocar_familiares(terreno_t terreno, familiar_t familiares[MAX_FAMILIARES], int tope) {
    for (int i = 0; i < tope; i++) {
        styled_char_t* s_char = terreno[familiares[i].posicion.fil][familiares[i].posicion.col];

        set_caracter(s_char, familiares[i].inicial_nombre);
    }
}

#include <stdio.h>
void colocar_robots(terreno_t terreno, coordenada_t* robots, int tope) {
    printf("%d", tope);
    for (int i = 0; i < tope; i++) {
        styled_char_t* s_char = terreno[robots[i].fil][robots[i].col];

        set_caracter(s_char, ROBOTS);
    }
}

void colocar_perry(terreno_t terreno, personaje_t perry) {
    styled_char_t* s_char = terreno[perry.posicion.fil][perry.posicion.col];

    set_caracter(s_char, PERRY);
    set_estilo(s_char, BOLD);
}



void estilo_cercania_familia(terreno_t terreno, juego_t juego) {
    if (juego.perry.camuflado) //si no esta modo agente
        return;

    coordenada_t f_posiciones[MAX_FAMILIARES];
    for (int i = 0; i < juego.tope_familiares; i++)
        f_posiciones[i] = juego.familiares[i].posicion;
    
    pintar_cercania(
        terreno,
        f_posiciones,
        juego.tope_familiares,
        DIST_FAMILIA,
        ROJO,
        FONDO_BRILLANTE
    );
}

void estilo_cercania_robots(terreno_t terreno, juego_t juego) {
    bool modo_agente = !(juego.perry.camuflado);
    pintar_cercania(
        terreno,
        juego.robots,
        juego.cantidad_robots,
        DIST_ROBOTS,
        modo_agente ? AMARILLO : ROJO,
        modo_agente ? FONDO_NORMAL : FONDO_BRILLANTE
    );
}

/* void estilo_explosion(styled_char terreno[TER_FIL][TER_COL]) {
    for (int i=0; i<TER_FIL; i++)
        for (int j=0; j<TER_COL; j++)
            colocar_estilo(terreno, (coordenada_t) { i, j }, ROJO_F, (j == TER_COL - 1));
} */

void colocar_estilos(terreno_t terreno, juego_t juego) {
    /* for (int i = 0; i < juego.tope_bombas; i++) {
        if ((!juego.bombas[i].desactivada) && (juego.bombas[i].timer == 0)) {
            estilo_explosion(terreno);
            return;
        }
    } */

    estilo_cercania_robots(terreno, juego);
    
        estilo_cercania_familia(terreno, juego);

}