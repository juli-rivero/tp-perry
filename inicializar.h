#ifndef INICIALIZAR_H
#define INICIALIZAR_H

#include "feria.h"
#include "constantes.h"


personaje_t crear_personaje();

void inicializar_topes(juego_t* juego);

void inicializar_bombas(juego_t* juego);

void inicializar_herramientas(juego_t* juego);

void inicializar_familiares(juego_t* juego);

void inicializar_robots(juego_t* juego);

void liberar_memoria(juego_t* juego);

void agregar_robot(juego_t* juego);

void eliminar_robot(coordenada_t** robots, int* tope, int indice);

#endif /* INICIALIZAR_H */