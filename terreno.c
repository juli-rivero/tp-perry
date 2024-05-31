#include "terreno.h"

#include "mi_libreria.h"
#include "funciones_objetos.h"

#include "estilos.h"
#include <stdlib.h>
#include <stdio.h>

char visualizacion_de_posicion(juego_t juego, coordenada_t posicion) {
    for (int i = 0; i < juego.tope_bombas; i++)
        if(
            !juego.bombas[i].desactivada &&
            son_pos_iguales(juego.bombas[i].posicion, posicion)
        )   return BOMBAS;

    for (int i = 0; i < juego.tope_herramientas; i++)
        if(son_pos_iguales(juego.herramientas[i].posicion, posicion))
            return juego.herramientas[i].tipo;
    
    for (int i = 0; i < juego.tope_familiares; i++)
        if(son_pos_iguales(juego.familiares[i].posicion, posicion))
            return juego.familiares[i].inicial_nombre;

    for (int i = 0; i < juego.cantidad_robots; i++)
        if(son_pos_iguales(juego.robots[i], posicion))
            return ROBOTS;
    
    if (son_pos_iguales(juego.perry.posicion, posicion))
        return PERRY;

    return false;
}
coordenada_t agarrar_rand_posicion(juego_t juego) {
    coordenada_t posicion;
    int contador = 0;
    do {
        posicion.fil = rand_index(TER_FIL);
        posicion.col = rand_index(TER_COL);
    } while ((visualizacion_de_posicion(juego, posicion)) && (++contador < MAXIMO_BUCLE));

    if (contador >= MAXIMO_BUCLE)  {
        fprintf(stderr, "Terreno insuficiente para la cantidad de objetos");
        exit(EXIT_FAILURE);
    }
    return posicion;
}

void destruir_terreno(terreno_t terreno) {
    for (int i = 0; i < TER_FIL; i++)
        for (int j = 0; j < TER_COL; j++)
            destruir_styled_char(terreno[i][j]);
}

void crear_terreno(terreno_t terreno) {
    for (int i = 0; i < TER_FIL; i++)
        for (int j = 0; j < TER_COL; j++)
            terreno[i][j] = NULL;
    for (int i = 0; i < TER_FIL; i++)
        for (int j = 0; j < TER_COL; j++)  {
            terreno[i][j] = crear_styled_char();
            if (terreno[i][j] == NULL) {
                destruir_terreno(terreno);
                fprintf(stderr, "Terreno no se pudo crear, memoria insuficiente");
                exit(EXIT_FAILURE);
            }
        }
}

void pintar_cercania(terreno_t terreno, coordenada_t pos_centrales[], int tope_pos_centrales, distancia_respecto_perry_t dist, color_t color_fondo, modo_fondo_t modo) {
    coordenada_t* filtrados[TER_FIL]; //vector de punteros
    int topes_filtrados[TER_FIL];
    for (int i=0; i<TER_FIL; i++)
        filtrados[i] = NULL;

    filtrar_coordenadas_segun_distancia(
        dist,
        pos_centrales,
        tope_pos_centrales,
        filtrados,
        topes_filtrados
    );
    for (int i=0; i < TER_FIL; i++) {
        for (int j=0; j < topes_filtrados[i]; j++) {
            styled_char_t* s_char = terreno[filtrados[i][j].fil][filtrados[i][j].col];
            set_color_fondo(s_char, color_fondo);
            set_modo_fondo(s_char, modo);
            set_reset(s_char, 
                (j == (topes_filtrados[i]-1)) || // True si es la ultima columna
                (filtrados[i][j + 1].col - filtrados[i][j].col > 1) // True si no hay que pintar en la siguiente posicion
                );
        }
    }

    for (int i=0; i<TER_FIL; i++)
        free(filtrados[i]);
}