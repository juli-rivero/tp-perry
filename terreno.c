#include "terreno.h"

#include "mi_libreria.h"

#include "colores.h"
#include <string.h>
#include <stdio.h>

bool son_pos_iguales(coordenada_t pos1, coordenada_t pos2) {
    return (pos1.fil == pos2.fil && pos1.col == pos2.col);
}
char visualizacion_de_posicion(juego_t juego, coordenada_t posicion) {
    if (son_pos_iguales(juego.perry.posicion, posicion))
        return PERRY;

    for (int i = 0; i < juego.tope_bombas; i++)
        if(son_pos_iguales(juego.bombas[i].posicion, posicion))
            return BOMBAS;

    for (int i = 0; i < juego.tope_herramientas; i++)
        if(son_pos_iguales(juego.herramientas[i].posicion, posicion))
            return juego.herramientas[i].tipo;
    
    for (int i = 0; i < juego.tope_familiares; i++)
        if(son_pos_iguales(juego.familiares[i].posicion, posicion))
            return juego.familiares[i].inicial_nombre;
    
    return VACIO;
}
coordenada_t agarrar_rand_posicion(juego_t juego) {
    coordenada_t posicion;
    int contador = 0;
    do {
        posicion.fil = rand_index(TER_FIL);
        posicion.col = rand_index(TER_COL);
    } while ((visualizacion_de_posicion(juego, posicion) != VACIO) && (++contador < MAXIMO_BUCLE));

    if (contador >= MAXIMO_BUCLE)  {
        printf(ROJO_T"Terreno insuficiente para la cantidad de objetos\n"RESET);
        posicion.fil = -1; 
        posicion.col = -1; 
    }
    return posicion;
}

void vaciar_terreno(styled_char terreno[TER_FIL][TER_COL]) {
    for (int i = 0; i < TER_FIL; i++)
        for (int j = 0; j < TER_COL; j++)
            strcpy(terreno[i][j], (styled_char){VACIO});
}