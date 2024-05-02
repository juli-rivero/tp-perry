#include "colocar_en_terreno.h"

#include "colores.h"
#include "mi_libreria.h"

#include <string.h>

//POST: Coloca en la posicion del terreno recibida, el nombre recibido.
void colocar_en_terreno(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], coordenada_t posicion, char nombre[MAX_NOMBRE]) {
    strcpy(terreno[posicion.fil][posicion.col], nombre);
}

void colocar_bombas(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], int tope, bomba_t bombas[MAX_BOMBAS]) {
    for (int i = 0; i < tope; i++) {
        char styled_B[MAX_NOMBRE] = "";
        if (bombas[i].timer < ADVERT_ROJA)
            strcpy(styled_B, ROJO_T);
        else if (bombas[i].timer < ADVERT_AMARILLA)
            strcpy(styled_B, AMARILLO_T);
        strcat(styled_B, (char[MAX_NOMBRE]) {BOMBAS});
        strcat(styled_B, RESET_COLOR);
        colocar_en_terreno(terreno, bombas[i].posicion, styled_B);
    }
}

void colocar_herramientas(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], int tope, herramienta_t herramientas[MAX_HERRAMIENTAS]) {
    for (int i = 0; i < tope; i++) {
        colocar_en_terreno(terreno, herramientas[i].posicion, (char[MAX_NOMBRE]) {herramientas[i].tipo});
    }
}

void colocar_familiares(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], int tope, familiar_t familiares[MAX_FAMILIARES]) {
    for (int i = 0; i < tope; i++) {
        colocar_en_terreno(terreno, (familiares[i].posicion), (char[MAX_NOMBRE]) {familiares[i].inicial_nombre});
    }
}

void colocar_perry(char terreno[TER_FIL][TER_COL][MAX_NOMBRE], personaje_t perry) {
    char style_P[MAX_NOMBRE] = STYLE_BOLD;
    strcat(style_P, STYLE_UNDERLINE);
    strcat(style_P, (char[MAX_NOMBRE]){PERRY});
    strcat(style_P, STYLE_NO_BOLD);
    strcat(style_P, STYLE_NO_UNDERLINE);
    colocar_en_terreno(terreno, perry.posicion, style_P); 
}