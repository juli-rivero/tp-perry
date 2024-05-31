#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <stdbool.h>
#include <wchar.h>
#include "estilos.h"


/* INICIALIZACION */

    enum atributo_perry_inicial {
        I_VIDA = 3,
        I_ENERGIA = 100,
        //tipo de dato: booleano
        I_CAMUFLADO = false,
    };
    enum cantidad_inicial {
        I_CANT_BOMBAS = 10,
        I_CANT_SOMBREROS = 3,
        I_CANT_GOLOSINAS = 5,
        I_CANT_FAMILIA = 3,
    };
    enum indice_familiar {
        INDICE_PHINEAS,
        INDICE_FERB,
        INDICE_CANDACE
    };
    enum timer_bomba {
        TIEMPO_MIN = 50,
        TIEMPO_MAX = 300,
    };
    typedef enum distancia_respecto_perry {
        DIST_FAMILIA = 1,
        DIST_ROBOTS = 2,
        DIST_BOMBA = 2 * 20 // Para que ocupe todo el mapa
    } distancia_respecto_perry_t;


/* ACCIONES */
    //constantes de tipo: char
    enum direccion {
        //tipo de dato: char
        ARRIBA = 'W',
        //tipo de dato: char
        ABAJO = 'S',
        //tipo de dato: char
        DERECHA = 'D',
        //tipo de dato: char
        IZQUIERDA = 'A',
    };
    //constantes de tipo: char
    enum habilidad {
        //tipo de dato: char
        CAMUFLARSE = 'Q',
    };


/* CONVENCIONES */

    //constantes de tipo: char
    enum inicial_falimiar {
        //tipo de dato: char
        PERRY = 'P',
        //tipo de dato: char
        PHINEAS = 'H',
        //tipo de dato: char
        FERB = 'F',
        //tipo de dato: char
        CANDACE = 'C',
    };
    //constantes de tipo: char
    enum inicial_obstaculo {
        //tipo de dato: char
        ROBOTS = 'R',
        //tipo de dato: char
        BOMBAS = 'B',
    };
    //constantes de tipo: char
    enum inicial_herramienta {
        //tipo de dato: char
        SOMBREROS = 'S',
        //tipo de dato: char
        GOLOSINAS = 'G',
    };


/* ESTADISTICAS */

    //constantes de tipo: w_char
    enum vista_atributo_perry {
        //tipo de dato: w_char
        VISTA_VIDA = L'❤',
        //tipo de dato: w_char
        VISTA_ENERGIA = L'⚡',
        //tipo de dato: w_char
        VISTA_AGENTE = L'ㅛ',
    };


/* DETALLES */

    enum advertencia_timer_bomba {
        ADVERT_AMARILLA = 100,
        ADVERT_ROJA = 25
    };


/* TERRENO */

    enum dimension_terreno {
        TER_FIL = 20,
        TER_COL = 20,
    };
    typedef styled_char_t* terreno_t[TER_FIL][TER_COL];


/* ESTADO JUEGO */

    enum estado_juego {
        GAME_OVER = -1,
        EN_JUEGO = 0,
        GANADO = 1
    };


/* AUXILIARES */

    enum constante_auxiliar {
        MAXIMO_BUCLE = 1000
    };

#endif /* CONSTANTES_H */