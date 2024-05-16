#include "colocar_en_terreno.h"

#include "colores.h"
#include "mi_libreria.h"

#include <string.h>

//POST: Coloca en la posicion del terreno recibida, el nombre recibido.
void colocar_en_terreno(styled_char terreno[TER_FIL][TER_COL], coordenada_t posicion, char* estilo, char inicial) {
    styled_char s_char = "";
    strcpy(
        terreno[posicion.fil][posicion.col], 
        strcat(
            strcat(
                strcat(
                    s_char,
                    estilo
                ), 
                (styled_char) {inicial}
            ), 
            RESET
        )
    );
}

void colocar_bombas(styled_char terreno[TER_FIL][TER_COL], int tope, bomba_t bombas[MAX_BOMBAS]) {
    for (int i = 0; i < tope; i++) {
        int timer = bombas[i].timer;
        colocar_en_terreno(
            terreno, 
            bombas[i].posicion, 
            (timer < ADVERT_ROJA) ? ROJO_T : ((timer < ADVERT_AMARILLA) ? AMARILLO_T : ""), 
            BOMBAS
        );
    }
}

void colocar_herramientas(styled_char terreno[TER_FIL][TER_COL], int tope, herramienta_t herramientas[MAX_HERRAMIENTAS]) {
    for (int i = 0; i < tope; i++) {
        colocar_en_terreno(
            terreno, 
            herramientas[i].posicion, 
            "", 
            herramientas[i].tipo
        );
    }
}

void colocar_familiares(styled_char terreno[TER_FIL][TER_COL], int tope, familiar_t familiares[MAX_FAMILIARES]) {
    for (int i = 0; i < tope; i++) {
        colocar_en_terreno(
            terreno, 
            familiares[i].posicion, 
            "", 
            familiares[i].inicial_nombre
        );
    }
}

void colocar_perry(styled_char terreno[TER_FIL][TER_COL], personaje_t perry) {
    colocar_en_terreno(
        terreno, 
        perry.posicion, 
        STYLE_BOLD STYLE_UNDERLINE, 
        PERRY
    ); 
}