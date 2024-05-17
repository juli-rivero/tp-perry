#include "constantes.h"

// INICIALIZACION
    const int I_VIDA = 3;
    const int I_ENERGIA = 100;
    const bool I_CAMUFLADO = false;

    const int I_CANT_BOMBAS = 10; //NO debe superar a MAXBOMBAS de feria.h
    /* En constantes.h 
    enum Timer_bomba {
        TIEMPO_MIN = 50,
        TIEMPO_MAX = 300,
    };
    */

    const int I_CANT_SOMBREROS = 3; 
    const int I_CANT_GOLOSINAS = 5; 
    // (I_CANT_SOMBREROS + I_CANT_GOLOSINAS) NO debe superar a MAX_HERRAMIENTAS de feria.h

    const int I_CANT_FAMILIA = 3; // Phineas, Ferb y Candace
    // Por más que en feria.h diga que MAX_FAMILIARES es 10, si se quieren agregar más familiares, se debera agregar los respectivos "inicial_nombre" manualmente en feria.c

// ACCIONES
    /* En constantes.h 
    enum Direcciones {
        ARRIBA = 'W',
        ABAJO = 'S',
        DERECHA = 'D',
        IZQUIERDA = 'A'
    };
    enum Habilidades {
        CAMUFLARSE = 'Q'
    };
    */
    const char NO_VALIDO = '-';

// CONVENCIONES - estan como cadena para despues poder usarlos con strcat (y usar colores)
    // Nombres
        const char PERRY = 'P';
        const char PHINEAS = 'H';
        const char FERB = 'F';
        const char CANDACE = 'C';
    // Obstaculos
        const char BOMBAS = 'B';
    // Herramientas
        const char SOMBREROS = 'S';
        const char GOLOSINAS = 'G';

// ESTADISTICAS
    wchar_t VISTA_VIDA = L'❤';
    wchar_t VISTA_ENERGIA = L'⚡';
    wchar_t VISTA_AGENTE = L'ㅛ';

// DETALLES
    /* En constantes.h 
    enum Advertencia_timer_bomba {
        ADVERT_AMARILLA = 100,
        ADVERT_ROJA = 25
    }; 
    */

// TERRENO
    /* En constantes.h 
        #define TER_FIL 20
        #define TER_COL 20
    */
    const char VACIO = ' ';
    const char NO_VACIO = '#';

// AUXILIARES
    const int MAXIMO_BUCLE = 1000;