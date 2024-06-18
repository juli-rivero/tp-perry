#include "estilos.h"

#include <stdlib.h>
#include <stdio.h>

#ifndef SECUENCIA
#define SECUENCIA "\033[" // también puede ser \x1b[
#endif /* SECUENCIA */

#ifndef SEPARADOR
#define SEPARADOR ";"
#endif /* SEPARADOR */

#ifndef FIN_ESTILO
#define FIN_ESTILO "m"
#endif /* SECUENCIA */

#ifndef RESET
#define RESET "\033[0m"
#endif /* RESET */

struct styled_char {
    char caracter;
    texto_atributo_t atributo;
    color_t color_texto;
    modo_texto_t modo_texto;
    color_t color_fondo;
    modo_fondo_t modo_fondo;
    bool reset;
};

styled_char_t* crear_styled_char() {
    styled_char_t* s_char = malloc(sizeof(styled_char_t));
    if (s_char) {
        *s_char = (styled_char_t) { ' ', NORMAL, DEFAULT_COLOR, TEXTO_NORMAL, DEFAULT_COLOR, FONDO_NORMAL, true };
    }
    return s_char;
}

void destruir_styled_char(styled_char_t* s_char){
    free(s_char);
}

void set_caracter(styled_char_t* s_char, char caracter) {
    s_char->caracter = caracter;
}

char get_caracter(styled_char_t* s_char) {
    return s_char->caracter;
}

void set_estilo(styled_char_t* s_char, texto_atributo_t atributo) {
    s_char->atributo = atributo;
}

void set_color_texto(styled_char_t* s_char, color_t color) {
    s_char->color_texto = color;
}

void set_color_fondo(styled_char_t* s_char, color_t color) {
    s_char->color_fondo = color;
}

void set_modo_texto(styled_char_t* s_char, modo_texto_t modo) {
    s_char->modo_texto = modo;
}
void set_modo_fondo(styled_char_t* s_char, modo_fondo_t modo) {
    s_char->modo_fondo = modo;
}

void set_reset(styled_char_t* s_char, bool reset) {
    s_char->reset = reset;
}

char* parse_string_modo_fondo(modo_fondo_t modo) {
    switch(modo) {
        case FONDO_NORMAL: return "4";
        case FONDO_BRILLANTE: return "10";
        default:
            fprintf(stderr, "ERROR parse_string_modo_fondo");
            exit(1);
    }
}

void imprimir_estilo(texto_atributo_t atributo, color_t color_texto, modo_texto_t modo_texto, color_t color_fondo, modo_fondo_t modo_fondo) {
    printf(SECUENCIA);

    printf("%c", atributo);

    if(color_texto != DEFAULT_COLOR) {
        printf(SEPARADOR);
        printf("%c%c", modo_texto, color_texto);

    }
    if(color_fondo != DEFAULT_COLOR) {
        printf(SEPARADOR);
        printf("%s%c", parse_string_modo_fondo(modo_fondo), color_fondo);
    }
    printf(FIN_ESTILO);
}

void reset_estilo() {
    printf(RESET);
}

void imprimir_styled_char(styled_char_t* s_char) {
    imprimir_estilo(
        s_char->atributo,
        s_char->color_texto,
        s_char->modo_texto,
        s_char->color_fondo,
        s_char->modo_fondo
    );
    
    printf("%c", s_char->caracter);

    if (s_char->reset) reset_estilo();
}