#include "terreno.h"

#include "mi_libreria.h"

#include "colores.h"
#include <string.h>
#include <stdio.h>

bool son_pos_iguales(coordenada_t pos1, coordenada_t pos2) {
    return (pos1.fil == pos2.fil && pos1.col == pos2.col);
}
bool esta_disponible2(juego_t juego, coordenada_t posicion) {
    if (son_pos_iguales(juego.perry.posicion, posicion))
        return false;

    for (int i = 0; i < juego.tope_bombas; i++)
        if(son_pos_iguales(juego.bombas[i].posicion, posicion))
            return false;

    for (int i = 0; i < juego.tope_herramientas; i++)
        if(son_pos_iguales(juego.herramientas[i].posicion, posicion))
            return false;
    
    for (int i = 0; i < juego.tope_familiares; i++)
        if(son_pos_iguales(juego.familiares[i].posicion, posicion))
            return false;
    
    return true;
}
coordenada_t agarrar_rand_posicion2(juego_t juego) {
    coordenada_t posicion;
    int contador = 0;
    do {
        posicion.fil = rand_index(TER_FIL);
        posicion.col = rand_index(TER_COL);
    } while (!esta_disponible2(juego, posicion) && ++contador < MAXIMO_BUCLE);

    if (contador >= MAXIMO_BUCLE)  {
        printf(ROJO_T"Terreno insuficiente para la cantidad de objetos\n"RESET);
        posicion.fil = -1; 
        posicion.col = -1; 
    }
    return posicion;
}

void vaciar_terreno(styled_char terreno[TER_FIL][TER_COL]) {
    for (int i = 0; i < TER_FIL; i++)
        for (int j=0; j<TER_COL;j++)
            strcpy(terreno[i][j], (styled_char){VACIO});
}

// POST: verifica que este vacio el terreno en la posicion recibida.
bool esta_disponible(styled_char terreno[TER_FIL][TER_COL], coordenada_t posicion) {
    return !strcmp(terreno[posicion.fil][posicion.col], (styled_char) {VACIO});
}
coordenada_t agarrar_rand_posicion(styled_char terreno[TER_FIL][TER_COL]) {
    coordenada_t posicion;
    int contador = 0;
    do {
        posicion.fil = rand_index(TER_FIL);
        posicion.col = rand_index(TER_COL);
    } while (!esta_disponible(terreno, posicion) && ++contador < MAXIMO_BUCLE);

    if (contador >= MAXIMO_BUCLE)  {
        printf(ROJO_T"Terreno insuficiente para la cantidad de objetos\n"RESET);
        posicion.fil = -1; 
        posicion.col = -1; 
    } else {
        strcpy(terreno[posicion.fil][posicion.col], (styled_char) {NO_VACIO});
    }
    return posicion;
}






/* Descartado porque despues se tiene que volver a usar y es, por esta razón, más eficiente la otra que se usa.

 - estaba en mi_libreria
void eliminar_elemento(coordenada_t* arreglo, int indice, int* tope) {
    coordenada_t aux = arreglo[indice];
    arreglo[indice] = arreglo[*tope - 1];
    arreglo[*tope - 1] = aux;
    (*tope)--;
}

 - estaba en un archivo structs.h
typedef struct ter_disponibles {
    coordenada_t posiciones[TER_FIL * TER_COL];
    int tope_posiciones;
} ter_disponible_t;
*/
/* Funciona pero descartado porque despues se tiene que volver a usar y es, por esta razón, más eficiente la otra que se usa. 

ter_disponible_t inicializar_ter_disponible() {
    ter_disponible_t ter_disp;
    ter_disp.tope_posiciones = TER_FIL * TER_COL;
    for (int i = 0; i < TER_FIL; i++)
        for (int j = 0; j < TER_COL; j++) {
            ter_disp.posiciones[TER_FIL*i + j].fil = i;
            ter_disp.posiciones[TER_FIL*i + j].col = j;
        }
    return ter_disp;
}


coordenada_t init_rand_posicion(ter_disponible_t* ter_disp) {
    if (!(ter_disp->tope_posiciones)) { 
        printf("error: el terreno no tiene espacio disponible");
        coordenada_t posicion = {-1, -1}; //Para que salte error.
        return posicion;
    }
    int indice = rand_index(ter_disp->tope_posiciones);
    coordenada_t posicion = ter_disp->posiciones[indice];

    eliminar_elemento(ter_disp->posiciones, indice, &(ter_disp->tope_posiciones));

    return posicion;
} 

    Nota: se borraron todas las invocaciones.
*/