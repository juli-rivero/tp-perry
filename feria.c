#include "feria.h"
#include "structs.h"
#include "constantes.h"
#include "terreno.h"
#include "mi_libreria.h"
#include <ctype.h>
#include <stdio.h>
#include "colores.h"
#include <string.h>

void inicializar_juego(juego_t *juego)
{
    /* Funciona pero descartado porque despues se tiene que volver a usar y es, por esta razón, más eficiente la otra que se usa.

    //Terreno disponible se va a ir descontando a medida que los espacios se vayan ocupando.
    ter_disponible_t ter_disp = inicializar_ter_disponible();
    */

    char terreno[TER_FIL][TER_COL][MAX_NOMBRE];
    vaciar_terreno(terreno);

    // perry
    juego->perry.vida = I_VIDA;
    juego->perry.energia = I_ENERGIA;
    juego->perry.camuflado = I_CAMUFLADO;
    juego->perry.posicion = agarrar_rand_posicion(terreno);
    //juego->perry.posicion = init_rand_posicion(&ter_disp);

    // bombas
    juego->tope_bombas = I_CANT_BOMBAS;
    for (int i = 0; i < juego->tope_bombas; i++) {
        juego->bombas[i].desactivada = false;
        juego->bombas[i].timer = rand_minI_maxI(TIEMPO_MIN, TIEMPO_MAX);
        juego->bombas[i].posicion = agarrar_rand_posicion(terreno);
        //juego->bombas[i].posicion = init_rand_posicion(&ter_disp);
    }

    // herramientas
    juego->tope_herramientas = I_CANT_SOMBREROS + I_CANT_GOLOSINAS;
    for (int i = 0; i < I_CANT_SOMBREROS; i++)
        juego->herramientas[i].tipo = SOMBREROS;
    for (int i = I_CANT_SOMBREROS; i < juego-> tope_herramientas; i++)
        juego->herramientas[i].tipo = GOLOSINAS;
    for (int i = 0; i < juego->tope_herramientas; i++)
        juego->herramientas[i].posicion = agarrar_rand_posicion(terreno);
        //juego->herramientas[i].posicion = init_rand_posicion(&ter_disp);

    // familiares
    juego->tope_familiares = I_CANT_FAMILIA;
    juego->familiares[0].inicial_nombre = PHINEAS;
    juego->familiares[1].inicial_nombre = FERB;
    juego->familiares[2].inicial_nombre = CANDACE;
    for (int i = 0; i < I_CANT_FAMILIA; i++)
        juego->familiares[i].posicion = agarrar_rand_posicion(terreno);
        //juego->familiares[i].posicion = init_rand_posicion(&ter_disp);
}

void imprimir_terreno(juego_t juego)
{
    char terreno[TER_FIL][TER_COL][MAX_NOMBRE];
    vaciar_terreno(terreno);

    for (int i = 0; i < juego.tope_bombas; i++) {
        bomba_t bomba = juego.bombas[i];
        char styled_B[MAX_NOMBRE] = "";
        if (bomba.timer < ADVERT_ROJA)
            strcpy(styled_B, ROJO_T);
        else if (bomba.timer < ADVERT_AMARILLA)
            strcpy(styled_B, AMARILLO_T);
        strcat(styled_B, (char[MAX_NOMBRE]) {BOMBAS, '\0'});
        strcat(styled_B, RESET_COLOR);
        colocar_en_terreno(terreno, juego.bombas[i].posicion, styled_B);
    }
    for (int i = 0; i < juego.tope_herramientas; i++) {
        colocar_en_terreno(terreno, juego.herramientas[i].posicion, (char[MAX_NOMBRE]) {juego.herramientas->tipo, '\0'});
    }
    for (int i = 0; i < juego.tope_familiares; i++) {
        colocar_en_terreno(terreno, (juego.familiares[i].posicion), (char[MAX_NOMBRE]) {juego.familiares[i].inicial_nombre, '\0'});
    }
    char style_P[MAX_NOMBRE] = STYLE_BOLD;
    strcat(style_P, STYLE_UNDERLINE);
    strcat(style_P, (char[MAX_NOMBRE]){PERRY, '\0'});
    strcat(style_P, STYLE_NO_BOLD);
    strcat(style_P, STYLE_NO_UNDERLINE);
    colocar_en_terreno(terreno, juego.perry.posicion, style_P); 


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

int estado_juego(juego_t juego) {
    //Perdió?
    if (juego.perry.vida <= 0)
        return -1;

    //Ganó?
    bool ganado = true;
    for (int i = 0; i < juego.tope_bombas; i++)
        if (!juego.bombas[i].desactivada)
            ganado = false;
    if (ganado) return 1;

    //No ganó ni perdió.
    return 0;    
}