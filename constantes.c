#include "constantes.h"

//INICIALIZACION
    const int I_VIDA = 3;
    const int I_ENERGIA = 100;
    const bool I_CAMUFLADO = false;

    const int I_CANT_BOMBAS = 10; //NO debe superar a MAXBOMBAS de feria.h
    const int TIEMPO_MIN = 50;
    const int TIEMPO_MAX = 300;

    const int I_CANT_SOMBREROS = 3; 
    const int I_CANT_GOLOSINAS = 5; 
    // (I_CANT_SOMBREROS + I_CANT_GOLOSINAS) NO debe superar a MAX_HERRAMIENTAS de feria.h

    const int I_CANT_FAMILIA = 3; // Phineas, Ferb y Candace
    // Por más que en feria.h diga que MAX_FAMILIARES es 10, si se quieren agregar más familiares, se debera agregar los respectivos "inicial_nombre" manualmente en feria.c

//ACCIONES
    // ver en constantes.h

    const char NO_VALIDO = '-';

//CONVENCIONES - estan como cadena para despues poder usarlos con strcat (y usar colores)
    //Nombres
        const char PERRY = 'P';
        const char PHINEAS = 'H';
        const char FERB = 'F';
        const char CANDACE = 'C';
    //Obstaculos
        const char BOMBAS = 'B';
    //Herramientas
        const char SOMBREROS = 'S';
        const char GOLOSINAS = 'G';

//ESTADISTICAS
    char* VISTA_VIDA = "❤";
    char* VISTA_ENERGIA = "⚡";
    char* VISTA_CAMUFLAJE = "ㅛ";

//DETALLES
    //Para el timer de las bombas
        const int ADVERT_AMARILLA = 100;
        const int ADVERT_ROJA = 25;

//TERRENO
    // ver en constantes.h

    const char VACIO = ' ';
    const char NO_VACIO = '#';

//AUXILIARES
    const int MAXIMO_BUCLE = 1000;