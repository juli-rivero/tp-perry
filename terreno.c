#include "terreno.h"

#include "mi_libreria.h"

#include <string.h>

// POST: verifica que este vacio el terreno en la posicion recibida.
bool esta_disponible(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], coordenada_t posicion) {
    return terreno[posicion.fil][posicion.col][0] == VACIO;
}
coordenada_t agarrar_rand_posicion(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]) {
    coordenada_t posicion;
    int contador = 0;
    do {
        posicion.fil = rand_index(TER_FIL);
        posicion.col = rand_index(TER_COL);
    } while (!esta_disponible(terreno, posicion) && ++contador < MAXIMO_BUCLE);

    if (contador >= MAXIMO_BUCLE)  { //No hallo espacio disponible.
        posicion.fil = -1; 
        posicion.col = -1; 
    } else {
        strcpy(terreno[posicion.fil][posicion.col], (char[MAX_NOMBRE]) {NO_VACIO, '\0'});
    }
    return posicion;
}

void vaciar_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE]) {
    for (int i = 0; i < TER_FIL; i++)
        for (int j=0; j<TER_COL;j++)
            strcpy(terreno[i][j], (char[MAX_NOMBRE]){VACIO, '\0'});
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