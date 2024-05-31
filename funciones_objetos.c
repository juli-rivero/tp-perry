#include "funciones_objetos.h"
#include "mi_libreria.h"

#include <stdio.h>
#include <stdlib.h>

bool son_pos_iguales(coordenada_t pos1, coordenada_t pos2) {
    return (pos1.fil == pos2.fil && pos1.col == pos2.col);
}


int calcular_distancia(coordenada_t pos1, coordenada_t pos2) {
    return abs(pos1.fil - pos2.fil) + abs(pos1.col - pos2.col);
}

void filtrar_coordenadas_segun_distancia(int distancia, coordenada_t* posiciones, int tope_posiciones, coordenada_t* filtrados[TER_FIL], int topes_filtrados[TER_FIL]) {
    for (int i=0; i < TER_FIL; i++) {
        topes_filtrados[i] = 0;
        for (int j=0; j < TER_COL; j++) {
            for (int k=0; k < tope_posiciones; k++) {
                if (calcular_distancia((coordenada_t){ i, j }, posiciones[k]) <= distancia) {
                    (topes_filtrados[i])++;
                    filtrados[i] = realloc(filtrados[i], sizeof(coordenada_t) * (size_t) topes_filtrados[i]);
                    if (filtrados[i] == NULL) {
                        printf("ERROR REALLOC");
                        return;
                    }
                    filtrados[i][topes_filtrados[i] - 1] = (coordenada_t){ i, j };
                }
            }
        }
    }
}

coordenada_t obtener_posicion(void* objeto, tipo_de_objeto_t tipo_de_objeto, size_t offset) {
    switch (tipo_de_objeto)
    {
        case TIPO_ROBOT:
            return *((coordenada_t*)objeto + offset);
        case TIPO_PERSONAJE:
            return ((personaje_t*)objeto + offset)->posicion;
        case TIPO_BOMBA:
            return ((bomba_t*)objeto + offset)->posicion;
        case TIPO_HERRAMIENTA:
            return ((herramienta_t*)objeto + offset)->posicion;
        case TIPO_FAMILIAR:
            return ((familiar_t*)objeto + offset)->posicion;
    }
    return (coordenada_t) {-1,-1};
}

size_t encontrar_indice_segun_posicion(void* objeto, tipo_de_objeto_t tipo_de_objeto, int tope, coordenada_t posicion) {
    for (int i=0; i < tope; i++){
        coordenada_t obj_pos = obtener_posicion(objeto, tipo_de_objeto, (size_t) i);
        if (son_pos_iguales(obj_pos, posicion))
            return (size_t) i;
    }

    return (size_t) -1;
}

size_t sizeof_tipo_de_objeto(tipo_de_objeto_t tipo_de_objeto) {
    switch (tipo_de_objeto)
    {
        case TIPO_ROBOT:
            return sizeof(coordenada_t);
        case TIPO_PERSONAJE:
            return sizeof(personaje_t);
        case TIPO_BOMBA:
            return sizeof(bomba_t);
        case TIPO_HERRAMIENTA:
            return sizeof(herramienta_t);
        case TIPO_FAMILIAR:
            return sizeof(familiar_t);
    }
    return 0;
}

void eliminar_objeto_segun_posicion(void* objeto, tipo_de_objeto_t tipo_de_objeto, int* tope, coordenada_t posicion) {
    size_t indice = encontrar_indice_segun_posicion(objeto, tipo_de_objeto, *tope, posicion);
    eliminar_elemento(objeto, sizeof_tipo_de_objeto(tipo_de_objeto), tope, indice);
}