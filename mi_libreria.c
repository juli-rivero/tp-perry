#include "mi_libreria.h"

#include <stdlib.h>
#include <string.h> // Necesario para memcpy
#include <stdio.h>
#include <math.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "cursor.h"
#include "estilos.h"

int rand_index(int max_exclusive)
{
    return rand() % max_exclusive;
}

int rand_minI_maxI(int min_inclusive, int max_inclusive)
{
    return rand() % (max_inclusive - min_inclusive + 1) + min_inclusive;
}

void swap(void* elemento1, void* elemento2, size_t size_elemento) {
    void* aux = malloc(size_elemento); 
    if (aux == NULL){
        printf("ERROR");
        return;
    }
    
    memcpy(aux, elemento1, size_elemento);
    memcpy(elemento1, elemento2, size_elemento);
    memcpy(elemento2, aux, size_elemento);
    free(aux);
}

void eliminar_elemento(void* vector, size_t size_elemento, int* tope, size_t indice) {
    if (*tope == 0)
        return;
    (*tope)--;
    swap(
        vector + (size_elemento * indice), 
        vector + (size_elemento * ((size_t) *tope)), 
        size_elemento
        );
}

void centrar_verticalmente(int filas_contenido) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int height = w.ws_row;
    int padding_vertical = (height - filas_contenido) / 2;
    for (int i = 0; i < padding_vertical; i++) {
        printf("\n");
    }
}

void centrar_horizontalmente(int columnas_contenido) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int width = w.ws_col;
    int padding_horizontal = (width - columnas_contenido) / 2;
    mover_cursor_columna(padding_horizontal);
}

void imprimir_linea_centrada(const char* texto) {
    centrar_horizontalmente((int) strlen(texto));
    printf("%s", texto);
}

void imprimir_en_el_centro(const char* texto) {
    int enters = 0;
    int len = (int) strlen(texto);
    for (size_t i = 0; i < len; i++)
        if (texto[i] == '\n') enters++;
    
    centrar_verticalmente(enters);

    int contador_letras = 0;
    while(texto[contador_letras] != '\0') {
        rellenar_linea();
        mover_cursor_inicio_linea();
        int indice_a_imprimir = contador_letras;
        while (texto[contador_letras] != '\n') {
            contador_letras++;
        }
        contador_letras++;
        centrar_horizontalmente(contador_letras - indice_a_imprimir);
        while (indice_a_imprimir < contador_letras) {
            printf("%c", texto[indice_a_imprimir]);
            indice_a_imprimir++;
        }
    }

}


char* concatenar_textos(const char** textos, size_t cantidad) {
    size_t total_len = 0;
    for (size_t i = 0; i < cantidad; ++i) {
        total_len += strlen(textos[i]);
    }

    char* result = (char*)malloc(total_len + 1);
    if (!result) {
        fprintf(stderr, "MALLOC ERROR");
        exit(EXIT_FAILURE);
    }

    strcpy(result, textos[0]);

    for (size_t i = 1; i < cantidad; ++i) {
        strcat(result, textos[i]);
    }

    return result;
}

void destruir_concatenacion(char* concatenacion) {
    free(concatenacion);
}