#ifndef TERRENO_H
#define TERRENO_H

#include "constantes.h"
#include "feria.h"
#include "estilos.h"

//PRE: Los topes deben estar bien definidos con respecto a sus vectores
//POST: Retorna el caracter que representa la posicion en el terreno
char visualizacion_de_posicion(juego_t juego, coordenada_t posicion);

//PRE: Los topes deben estar bien definidos con respecto a sus vectores
//POST: Genera una posicion, verificando que no sobreeescribe ningun otro objeto dentro del terreno.
// En caso de no haber, devuelve -1 en la coordenada fila.
coordenada_t agarrar_rand_posicion(juego_t juego);

//POST: Crea un terreno vacio. Este terreno luego se debera destruir usando la funcion destruir_terreno()
void crear_terreno(terreno_t terreno);

//POST: Destruye el terreno previamente creado por crear_terreno.
void destruir_terreno(terreno_t terreno);

//POST: Pinta del color de fondo especificado las posiciones pasadas y sus posiciones cercanas (a menos de la distancia especificada). No va a pintar cercanias del borde del terreno.
void pintar_cercania(terreno_t terreno, coordenada_t pos_centrales[], int tope_pos_centrales, distancia_respecto_perry_t dist, color_t color_fondo, modo_fondo_t modo);

#endif /* TERRENO_H */