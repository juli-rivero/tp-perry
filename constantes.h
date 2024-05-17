#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <stdbool.h>
#include <wchar.h>

//INICIALIZACION
    #define MAX_VIDAS 20
    extern const int I_VIDA;
    extern const int I_ENERGIA;
    extern const bool I_CAMUFLADO;
    extern const int I_CANT_BOMBAS;
    enum Timer_bomba {
        TIEMPO_MIN = 50,
        TIEMPO_MAX = 300,
    };
    extern const int I_CANT_SOMBREROS;
    extern const int I_CANT_GOLOSINAS;
    extern const int I_CANT_FAMILIA;

//ACCIONES - con 'const enum' para que puedan usarse en el switch.
    enum Direcciones {
        ARRIBA = 'W',
        ABAJO = 'S',
        DERECHA = 'D',
        IZQUIERDA = 'A',
    };

    enum Habilidades {
        CAMUFLARSE = 'Q',
    };
    extern const char NO_VALIDO;

//CONVENCIONES
    //Nombres
        extern const char PERRY;
        extern const char PHINEAS;
        extern const char FERB;
        extern const char CANDACE;
    //Obstaculos
        extern const char BOMBAS;
    //Herramientas
        extern const char SOMBREROS;
        extern const char GOLOSINAS;

//ESTADISTICAS
    extern wchar_t VISTA_VIDA;
    extern wchar_t VISTA_ENERGIA;
    extern wchar_t VISTA_AGENTE;

//DETALLES
    enum Advertencia_timer_bomba {
        ADVERT_AMARILLA = 100,
        ADVERT_ROJA = 25
    };

//TERRENO
    #define TER_FIL 5
    #define TER_COL 5
    extern const char VACIO;
    extern const char NO_VACIO;

//ESTADO JUEGO
    enum Estado_juego {
        GAME_OVER = -1,
        EN_JUEGO = 0,
        GANADO = 1
    };

//AUXILIARES
    extern const int MAXIMO_BUCLE;

#endif /* CONSTANTES_H */