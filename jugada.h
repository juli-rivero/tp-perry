#ifndef JUGADA_H
#define JUGADA_H

#include "feria.h"

//PRE: la variable sentido debe ser una de estas: 'A','W','S','D'
//POST: devuelve la posicion movida en el sentido dado sin salirse del terreno.
coordenada_t mover(coordenada_t posicion, char sentido);

//POST: Comprueba donde esta posicionado perry y toma acción al respecto.
void comprobar_posicion(juego_t* juego);

#endif /* JUGADA_H */