#include "inicializar.h"

#include "terreno.h"
#include "mi_libreria.h"
#include "funciones_objetos.h"

#include <stdio.h>
#include <stdlib.h>

personaje_t crear_personaje() {
    return (personaje_t) {
        I_VIDA,
        I_ENERGIA,
        I_CAMUFLADO,
        {rand_index(TER_FIL), rand_index(TER_COL)}
    };
}

void inicializar_topes(juego_t* juego) {
    juego->tope_bombas = 0;
    juego->tope_herramientas = 0;
    juego->tope_familiares = 0;
    juego->cantidad_robots = 0;
}

bomba_t crear_bomba(juego_t juego, int* tope) {
    (*tope)++;
    return (bomba_t) {
        agarrar_rand_posicion(juego),
        rand_minI_maxI(TIEMPO_MIN, TIEMPO_MAX),
        false
    };
}
void inicializar_bombas(juego_t* juego) {
    int* tope = &(juego->tope_bombas);
    while (*tope < I_CANT_BOMBAS)
        juego->bombas[*tope] = crear_bomba(*juego, tope);
}

herramienta_t crear_herramienta(juego_t juego, int* tope, char tipo) {
    (*tope)++;
    return (herramienta_t) {
        agarrar_rand_posicion(juego),
        tipo
    };

}
void inicializar_herramientas(juego_t* juego) {
    int* tope = &(juego->tope_herramientas);
    while (*tope < I_CANT_SOMBREROS + I_CANT_GOLOSINAS)
        juego->herramientas[*tope] = 
            crear_herramienta(*juego, tope, (*tope < I_CANT_SOMBREROS) ? SOMBREROS : GOLOSINAS);
}

familiar_t crear_familiar(juego_t juego, int* tope, char sentido, char inicial_nombre) {
    (*tope)++;
    return (familiar_t) {
        agarrar_rand_posicion(juego),
        sentido,
        inicial_nombre
    };
}
void inicializar_familiares(juego_t* juego) {
    familiar_t* familiares = juego->familiares;
    int* tope = &(juego->tope_familiares);

    familiares[INDICE_PHINEAS] = crear_familiar(*juego, tope, DERECHA, PHINEAS);
    familiares[INDICE_FERB] = crear_familiar(*juego, tope, IZQUIERDA, FERB);
    familiares[INDICE_CANDACE] = crear_familiar(*juego, tope, ARRIBA, CANDACE);
}

void inicializar_robots(juego_t* juego) {
    juego->cantidad_robots=0;
    juego->robots = NULL;
}
void destruir_robots(coordenada_t** robots, int* tope) {
    *tope = 0;
    free(*robots);
    *robots = NULL;
}

void liberar_memoria(juego_t* juego) {
    destruir_robots(&(juego->robots), &(juego->cantidad_robots));
}

void push_robot(coordenada_t** robots, int* tope) {
    (*tope)++;
    coordenada_t* aux = realloc(*robots, sizeof(coordenada_t) * (size_t) (*tope));
    if (!aux) {
        free(*robots);
        fprintf(stderr, "ERROR REALLOC");
        exit(EXIT_FAILURE);
    }
    *robots = aux;
}

void agregar_robot(juego_t* juego) {
    coordenada_t pos_ultimo_robot;
    do {
        pos_ultimo_robot = agarrar_rand_posicion(*juego);
    } while (calcular_distancia(pos_ultimo_robot, juego->perry.posicion) <= DIST_ROBOTS);

    push_robot(&(juego->robots), &(juego->cantidad_robots));
    juego->robots[juego->cantidad_robots - 1] = pos_ultimo_robot;
}

void eliminar_robot(coordenada_t** robots, int* tope, int indice) {
    eliminar_elemento(*robots, sizeof(coordenada_t), tope, (size_t) indice);
    //Liberar espacio no usado
    if ((*tope) == 0) {
        destruir_robots(robots, tope);
    } else {
        coordenada_t* aux = realloc(*robots, sizeof(coordenada_t) * (size_t) (*tope));
        if (!aux) {
            free(*robots);
            fprintf(stderr, "ERROR REALLOC");
            exit(EXIT_FAILURE);
        }
        *robots = aux;
    }
}