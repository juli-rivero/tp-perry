#ifndef ESTILOS_H
#define ESTILOS_H

#include <stdbool.h>

typedef enum texto_atributo {
    NORMAL          = '0',
    BOLD            = '1',
    DIM             = '2',
    ITALIC          = '3',
    UNDERLINE       = '4',
    BLINK_SLOW      = '5',
    BLINK_FAST      = '6',
    REVERSE         = '7',
    HIDDEN          = '8',
    STRIKETHROUGH   = '9',
} texto_atributo_t;

typedef enum modo_de_fondo {
    FONDO_NORMAL = 4,
    FONDO_BRILLANTE = 10,
} modo_fondo_t;

typedef enum modo_de_texto {
    TEXTO_NORMAL = '3',
    TEXTO_BRILLANTE = '9',
} modo_texto_t;

typedef enum {
    DEFAULT_COLOR = -1,
    NEGRO           = '0',
    ROJO            = '1',
    VERDE           = '2',
    AMARILLO        = '3',
    AZUL            = '4',
    FUCSIA          = '5',
    CIAN            = '6',
    BLANCO          = '7',
} color_t;

// Para poder estelizar un caracter
struct styled_char;
typedef struct styled_char styled_char_t;


// Crea un puntero a styled_char_t. Este puntero luego debe ser destruido llamando a destruir_styled_char(). En caso de fallar retorna NULL
styled_char_t* crear_styled_char();

// Libera la memoria de un styled_char_t previamente creado por crear_styled_char(). En caso de ser un NULL no pasa nada.
void destruir_styled_char(styled_char_t* s_char);

// Guarda el caracter en s_char
void set_caracter(styled_char_t* s_char, char caracter);

// Devuelve el caracter de s_char
char get_caracter(styled_char_t* s_char);

// Guarda el atributo del texto en s_char
void set_estilo(styled_char_t* s_char, texto_atributo_t estilo);

// Guarda el color del texto en s_char
void set_color_texto(styled_char_t* s_char, color_t color);

// Guarda el color del fondo en s_char
void set_color_fondo(styled_char_t* s_char, color_t color);

// Guarda el modo del fondo en s_char
void set_modo_texto(styled_char_t* s_char, modo_texto_t modo);

// Guarda el modo del fondo en s_char
void set_modo_fondo(styled_char_t* s_char, modo_fondo_t modo);

// Guarda si se desea resetear el formato luego de llamar a imprimir_styled_char
void set_reset(styled_char_t* s_char, bool reset);

// Imprime el s_char
// Se va imprimir el caracter con todos los atributos/colores que se hayan guardado/sobrescrito en éste.
void imprimir_styled_char(styled_char_t* s_char);

// Setea el estilo para cualquier texto siguiente que se imprima. Para cancelarlo hay que llamar a reset_estilo
void imprimir_estilo(texto_atributo_t atributo, color_t color_texto, modo_texto_t modo_texto, color_t color_fondo, modo_fondo_t modo_fondo);

// Setea el estilo a como viene por defecto en la terminal.
void reset_estilo();

#endif /* ESTILOS_H */