#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <stdbool.h>
#include <wchar.h>
#include "estilos.h"

//INICIALIZACION
    extern const int I_VIDA;
    extern const int I_ENERGIA;
    extern const bool I_CAMUFLADO;
    extern const int I_CANT_BOMBAS;
    enum timer_bomba {
        TIEMPO_MIN = 50,
        TIEMPO_MAX = 300,
    };
    extern const int I_CANT_SOMBREROS;
    extern const int I_CANT_GOLOSINAS;
    extern const int I_CANT_FAMILIA;
    typedef enum distancia_respecto_perry {
        DIST_FAMILIA = 1,
        DIST_ROBOTS = 2,
        DIST_BOMBA = 2 * 20 // Para que ocupe todo el mapa
    } distancia_respecto_perry_t;

//ACCIONES - con 'const enum' para que puedan usarse en el switch.
    enum direcciones {
        ARRIBA = 'W',
        ABAJO = 'S',
        DERECHA = 'D',
        IZQUIERDA = 'A',
    };

    enum habilidades {
        CAMUFLARSE = 'Q',
    };
    extern const char NO_VALIDO;

//CONVENCIONES
    enum iniciales_falimia {
        PERRY = 'P',
        PHINEAS = 'H',
        FERB = 'F',
        CANDACE = 'C',
    };
    enum iniciales_obstaculos {
        ROBOTS = 'R',
        BOMBAS = 'B',
    };
    enum iniciales_herramientas {
        SOMBREROS = 'S',
        GOLOSINAS = 'G',
    };

//ESTADISTICAS
    extern wchar_t VISTA_VIDA;
    extern wchar_t VISTA_ENERGIA;
    extern wchar_t VISTA_AGENTE;

//DETALLES
    enum advertencia_timer_bomba {
        ADVERT_AMARILLA = 100,
        ADVERT_ROJA = 25
    };

//TERRENO
    enum dimensiones_terreno {
        TER_FIL = 20,
        TER_COL = 20,
    };
    typedef styled_char_t* terreno_t[TER_FIL][TER_COL];
    extern const char VACIO;
    extern const char NO_VACIO;

//ESTADO JUEGO
    enum estado_juego {
        GAME_OVER = -1,
        EN_JUEGO = 0,
        GANADO = 1
    };

//AUXILIARES
    extern const int MAXIMO_BUCLE;

#endif /* CONSTANTES_H */