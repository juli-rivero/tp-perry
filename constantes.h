#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <stdbool.h>

//INICIALIZACION
    extern const int I_VIDA;
    extern const int I_ENERGIA;
    extern const bool I_CAMUFLADO;
    extern const int I_CANT_BOMBAS;
    extern const int TIEMPO_MIN;
    extern const int TIEMPO_MAX;
    extern const int I_CANT_SOMBREROS;
    extern const int I_CANT_GOLOSINAS;
    extern const int I_CANT_FAMILIA;

//ACCIONES - con #define para que puedan usarse en el switch.
    //Direcciones
        #define ARRIBA 'W'
        #define ABAJO 'S'
        #define DERECHA 'D'
        #define IZQUIERDA 'A'
    //Habilidades
        #define CAMUFLARSE 'Q'
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
    extern char* VISTA_VIDA;
    extern char* VISTA_ENERGIA;
    extern char* VISTA_CAMUFLAJE;

//DETALLES
    //Para el timer de las bombas
        extern const int ADVERT_AMARILLA;
        extern const int ADVERT_ROJA;

//TERRENO
    #define TER_FIL 20
    #define TER_COL 20
    #define MAX_NOMBRE 20 //Para poder estelizar un caracter
    extern const char VACIO;
    extern const char NO_VACIO;

//AUXILIARES
    extern const int MAXIMO_BUCLE;

#endif /* CONSTANTES_H */