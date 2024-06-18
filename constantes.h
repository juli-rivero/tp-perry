#ifndef CONSTANTES_H
#define CONSTANTES_H

//constantes de tipo: char
typedef enum accion {
    //tipo de dato: char
    ARRIBA = 'W',
    //tipo de dato: char
    ABAJO = 'S',
    //tipo de dato: char
    DERECHA = 'D',
    //tipo de dato: char
    IZQUIERDA = 'A',
    //tipo de dato: char
    CAMUFLARSE = 'Q',
} accion_t;

typedef enum estado_juego {
    GAME_OVER = -1,
    EN_JUEGO = 0,
    GANADO = 1
} estado_juego_t;


#endif /* CONSTANTES_H */