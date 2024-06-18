#include "feria.h"
#include "constantes.h"

#include "utils.h"
#include "estilos.h"
#include "cursor.h"

#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>


typedef enum inicial_objeto {
    PERRY = 'P',
    BOMBAS = 'B',
    PHINEAS = 'H',
    FERB = 'F',
    CANDACE = 'C',
    ROBOTS = 'R',
    SOMBREROS = 'S',
    GOLOSINAS = 'G',
} inicial_objeto_t;

//Cantidad elementos iniciales

    const int CANT_BOMBAS_INICIALES= 10;
    const int CANT_SOMBREROS_INICIALES = 3;
    const int CANT_GOLOSINAS_INICIALES = 5;
    const int CANT_FAMILIA_INICIALES = 3;
    const int CANT_ROBOTS_INICIALES = 0;

//Atributos iniciales PERRY

    const wchar_t VISTA_VIDA = L'❤';
    const int VIDA_INICIAL = 3;
    
    const wchar_t VISTA_ENERGIA = L'⚡';
    const int ENERGIA_INICIAL = 100;

    const wchar_t VISTA_AGENTE = L'ㅛ';
    const bool CAMUFLADO_AL_INICIAR = false;

//Atributos iniciales bombas

    const int TIEMPO_MIN = 50;
    const int TIEMPO_MAX = 300;

    const int ADVERTENCIA_POCO_TIEMPO = 100;
    const int ADVERTENCIA_MUY_POCO_TIEMPO = 25;

    const int ENERGIA_PARA_DESACTIVAR_BOMBA = 10;

//Atributos iniciales familiares

    const char SENTIDO_INICIAL_PHINEAS = DERECHA;
    const char SENTIDO_INICIAL_FERB = IZQUIERDA;
    const char SENTIDO_INICIAL_CANDACE = ARRIBA;

    const int RADIO_FAMILIA = 1;

    /*  Con cambiar de orden este enum se puede modificar la prioridad de visualizacion. 
        El que se encuentre mas abajo en el enum sera el que se muestre por encima de todos */
    enum indice_familiar {
        INDICE_PHINEAS,
        INDICE_FERB,
        INDICE_CANDACE,
    };

//Atributos iniciales robots

    const int RADIO_ROBOTS = 2;
    const int ENERGIA_PARA_DESTRUIR_ROBOT = 5;

//Atributos iniciales herramientas

    const int VIDA_AL_PISAR_SOMBRERO = 1;
    const int ENERGIA_AL_PISAR_GOLOSINA = 20;

//Terreno

    #define TER_FIL 20
    #define TER_COL 20
    typedef styled_char_t* terreno_t[TER_FIL][TER_COL];

//Auxiliares
    typedef coordenada_t robot_t;
    const int MAXIMO_BUCLE = 1000;
    const int NO_SE_PISA = -1;
    // Para que el contenido esté centrado verticalmente
    const int alto_contenido = TER_FIL + 2;
    // Para que el contenido esté centrado horizontalmente
    const int ancho_contenido = TER_COL * 2 + 3;



// Devuelve el indice de la bomba que se encuentra en esa posicion. Si no se encuentra devuelve NO_SE_PISA
int chequear_bombas(bomba_t bombas[MAX_BOMBAS], int tope, coordenada_t posicion) {
    bool se_pisa = false;
    int i = 0;
    while (i < tope && !se_pisa){
        if(
            !bombas[i].desactivada &&
            son_pos_iguales(bombas[i].posicion, posicion)
        )   
            se_pisa = true;
        else 
            i++;
    }
    return se_pisa ? i : NO_SE_PISA;
}
// Devuelve el indice de la herramienta que se encuentra en esa posicion. Si no se encuentra devuelve NO_SE_PISA
int chequear_herramientas(herramienta_t herramientas[MAX_HERRAMIENTAS], int tope, coordenada_t posicion) {
    bool se_pisa = false;
    int i = 0;
    while (i < tope && !se_pisa) {
        if(son_pos_iguales(herramientas[i].posicion, posicion))
            se_pisa = true;
        else
            i++;
    }
    return se_pisa ? i : NO_SE_PISA;
}
// Devuelve el indice del familiar que se encuentra en esa posicion. Si no se encuentra devuelve NO_SE_PISA
int chequear_familiares(familiar_t familiares[MAX_FAMILIARES], int tope, coordenada_t posicion) {
    bool se_pisa = false;
    int i = 0;
    while (i < tope && !se_pisa) {
        if(son_pos_iguales(familiares[i].posicion, posicion))
            se_pisa = true;
        else
            i++;
    }
    return se_pisa ? i : NO_SE_PISA;
}
// Devuelve el indice del robot que se encuentra en esa posicion. Si no se encuentra devuelve NO_SE_PISA
int chequear_robots(coordenada_t* robots, int tope, coordenada_t posicion) {
    bool se_pisa = false;
    int i = 0;
    while (i < tope && !se_pisa) {
        if(son_pos_iguales(robots[i], posicion))
            se_pisa = true;
        else
            i++;
    }
    return se_pisa ? i : NO_SE_PISA;
}

/* 
- Los topes deben estar bien definidos con respecto a sus vectores
- Retorna el caracter del objeto que representa la posicion en el terreno.
  En caso de no encontrar devuelve false.
*/
inicial_objeto_t objeto_en_posicion(juego_t juego, coordenada_t posicion) {
    int aux;

    if (chequear_bombas(juego.bombas, juego.tope_bombas, posicion) != NO_SE_PISA)
        return BOMBAS;

    if ((aux = chequear_herramientas(juego.herramientas, juego.tope_herramientas, posicion)) != NO_SE_PISA)
        return juego.herramientas[aux].tipo;
    
    if ((aux = chequear_familiares(juego.familiares, juego.tope_familiares, posicion)) != NO_SE_PISA)
        return juego.familiares[aux].inicial_nombre;

    if (chequear_robots(juego.robots, juego.cantidad_robots, posicion) != NO_SE_PISA)
        return ROBOTS;
    
    if (son_pos_iguales(juego.perry.posicion, posicion))
        return PERRY;

    return false;
}

/* 
- Los topes deben estar bien definidos con respecto a sus vectores
- Genera una posicion, verificando que no sobreeescribe ningun otro objeto dentro del terreno 
    o que no se encuentre perry en el radio especificado (0 para ignorar el radio).
    En caso de haber terreno disponible, modifica la posicion pasada con una nueva posicion y devuelve true, 
    en caso contrario no modifica nada y devuelve false
*/
bool agarrar_rand_posicion(juego_t juego, coordenada_t* posicion, int radio) {
    coordenada_t aux;
    int contador = 0;
    do {
        aux.fil = rand_index(TER_FIL);
        aux.col = rand_index(TER_COL);
    } while ( (
            (objeto_en_posicion(juego, aux)) || 
            (calcular_distancia(aux, juego.perry.posicion) <= radio)
        ) && (
            (++contador < MAXIMO_BUCLE)
        ) );
    bool hay_terreno_disponible = contador < MAXIMO_BUCLE;
    if (hay_terreno_disponible)  {
        *posicion = aux;
    }
    return hay_terreno_disponible;
}





//Devuelve a perry con su posicion y sus atributos iniciales
personaje_t crear_personaje() {
    return (personaje_t) {
        VIDA_INICIAL,
        ENERGIA_INICIAL,
        CAMUFLADO_AL_INICIAR,
        {rand_index(TER_FIL), rand_index(TER_COL)}
    };
}
//Setea todos los topes a 0
void inicializar_topes(juego_t* juego) {
    juego->tope_bombas = 0;
    juego->tope_herramientas = 0;
    juego->tope_familiares = 0;
    juego->cantidad_robots = 0;
}
//tope_bombas debe estar en 0
//Inicializa cada bomba con sus posiciones y sus atributos iniciales, aumentando asi el tope_bombas
void inicializar_bombas(juego_t* juego) {
    int* tope = &(juego->tope_bombas);
    bool error = false;
    while ( ( *tope < CANT_BOMBAS_INICIALES ) && ( !error ) ) {
        bomba_t* bomba = &(juego->bombas[*tope]);
        error = !agarrar_rand_posicion(*juego, &(bomba->posicion), 0);
        if ( !error ) {
            bomba->timer = rand_min_inclusive_max_inclusive(TIEMPO_MIN, TIEMPO_MAX);
            bomba->desactivada = false;
            (*tope)++;
        }
    }
}
//tope_herramientas debe estar en 0
//Inicializa cada herramienta (golosinas y sombreros) con sus posiciones y sus atributos iniciales, aumentando asi el tope_herramientas
void inicializar_herramientas(juego_t* juego) {
    int* tope = &(juego->tope_herramientas);
    bool error = false;
    while ( ( *tope < CANT_SOMBREROS_INICIALES + CANT_GOLOSINAS_INICIALES ) && ( !error ) ) {
        herramienta_t* herramienta = &(juego->herramientas[*tope]);
        error = !agarrar_rand_posicion(*juego, &(herramienta->posicion), 0);
        if ( !error ) {
            herramienta->tipo = (*tope < CANT_SOMBREROS_INICIALES) ? SOMBREROS : GOLOSINAS;
            (*tope)++;
        }
    }
}
//tope_familiares debe estar en 0
//Inicializa cada familiar (Phineas, Ferb y Candace) con sus posiciones y sus atributos iniciales, aumentando asi el tope_familiares
void inicializar_familiares(juego_t* juego) {
    familiar_t* familiares = juego->familiares;

    int* tope = &(juego->tope_familiares);
    bool error = false;
    while ( ( *tope < CANT_FAMILIA_INICIALES ) && ( !error ) ) {
        error = !agarrar_rand_posicion(*juego, &(familiares[*tope].posicion), RADIO_FAMILIA);
        if ( !error ) {
            (*tope)++;
        }
    }

    familiares[INDICE_PHINEAS].inicial_nombre = PHINEAS;
    familiares[INDICE_PHINEAS].sentido = SENTIDO_INICIAL_PHINEAS;

    familiares[INDICE_FERB].inicial_nombre = FERB;
    familiares[INDICE_FERB].sentido = SENTIDO_INICIAL_FERB;

    familiares[INDICE_CANDACE].inicial_nombre = CANDACE;
    familiares[INDICE_CANDACE].sentido = SENTIDO_INICIAL_CANDACE;
}
//Setea robots a NULL en caso de que la cantidad de robots iniciales sea 0
//Crea un arreglo dinamico con la cantidad de robots iniciales en caso de que esta cantidad no sea 0
//Se espera que el tope de robots este en 0;
void inicializar_robots(juego_t* juego) {
    if (CANT_ROBOTS_INICIALES) {
        juego->robots =  malloc(sizeof(coordenada_t) * (size_t) CANT_ROBOTS_INICIALES);
        if(juego->robots == NULL) {
            fprintf(stderr, "ERROR MALLOC: no hay memoria disponible");
            return;
        }
        int* tope = &(juego->cantidad_robots);
        bool error = false;
        while ( ( *tope < CANT_ROBOTS_INICIALES ) && ( !error ) ) {
            error = !agarrar_rand_posicion(*juego, &(juego->robots[*tope]), RADIO_ROBOTS);
            if ( !error ) {
                (*tope)++;
            }
        }

    } else {
        juego->robots = NULL;
    }
    
}

void inicializar_juego(juego_t *juego)
{
    juego->movimientos = 0;
    juego->perry = crear_personaje();
    inicializar_topes(juego);
    inicializar_bombas(juego);
    inicializar_herramientas(juego);
    inicializar_familiares(juego);
    inicializar_robots(juego);
}




// Destruye el terreno previamente creado por crear_terreno.
// La matriz terreno sera una matriz de NULL
void destruir_terreno(terreno_t terreno) {
    for (int i = 0; i < TER_FIL; i++)
        for (int j = 0; j < TER_COL; j++) {
            destruir_styled_char(terreno[i][j]);
            terreno[i][j] = NULL;
        }
}
// Crea un terreno vacio. Este terreno luego se debera destruir usando la funcion destruir_terreno()
// En caso de que no se pueda crear el terreno, el terreno sera una matriz de NULL
void crear_terreno(terreno_t terreno) {
    for (int i = 0; i < TER_FIL; i++)
        for (int j = 0; j < TER_COL; j++)
            terreno[i][j] = NULL;
    bool error = false;
    
    int i = 0;
    while ((i < TER_FIL) && (!error)) {
        int j = 0;
        while ((j < TER_COL) && (!error))  {
            terreno[i][j] = crear_styled_char();
            if (terreno[i][j] == NULL)
                error = true;
            j++;
        }
        i++;
    }

    if (error) {
        destruir_terreno(terreno);
    }
}


// Se colocan las B (customizadas) en el terreno
void colocar_bombas(terreno_t terreno, bomba_t bombas[MAX_BOMBAS], int tope) {
    for (int i = 0; i < tope; i++) {
        if (!bombas[i].desactivada){
            styled_char_t* s_char = terreno[bombas[i].posicion.fil][bombas[i].posicion.col];
            set_caracter(s_char, BOMBAS);
            int timer = bombas[i].timer;
            if (timer < ADVERTENCIA_MUY_POCO_TIEMPO) {
                set_color_texto(s_char, ROJO);
                set_estilo(s_char, BLINK_FAST);
            } else if (timer < ADVERTENCIA_POCO_TIEMPO) {
                set_estilo(s_char, BLINK_FAST);
            } else {
                set_estilo(s_char, BLINK_SLOW);
            }
        }
    }
}
// Se colocan las G o S (customizadas) en el terreno
void colocar_herramientas(terreno_t terreno, herramienta_t herramientas[MAX_HERRAMIENTAS], int tope) {
    for (int i = 0; i < tope; i++) {
        styled_char_t* s_char = terreno[herramientas[i].posicion.fil][herramientas[i].posicion.col];

        set_caracter(s_char, herramientas[i].tipo);
        set_estilo(s_char, DIM);        
    }
}
// Se colocan las C, H o F (customizadas) en el terreno
void colocar_familiares(terreno_t terreno, familiar_t familiares[MAX_FAMILIARES], int tope) {
    for (int i = 0; i < tope; i++) {
        styled_char_t* s_char = terreno[familiares[i].posicion.fil][familiares[i].posicion.col];

        set_caracter(s_char, familiares[i].inicial_nombre);
    }
}
// Se colocan las R (customizadas) en el terreno
void colocar_robots(terreno_t terreno, coordenada_t* robots, int tope) {
    for (int i = 0; i < tope; i++) {
        styled_char_t* s_char = terreno[robots[i].fil][robots[i].col];

        set_caracter(s_char, ROBOTS);
    }
}
// Se colocan la P (customizada) en el terreno
void colocar_perry(terreno_t terreno, personaje_t perry) {
    styled_char_t* s_char = terreno[perry.posicion.fil][perry.posicion.col];

    set_caracter(s_char, PERRY);
    set_estilo(s_char, BOLD);
}

//Pinta el color de fondo de las posiciones pasadas y sus posiciones cercanas (a menos de la distancia especificada). No va a pintar cercanias del borde del terreno.
void pintar_cercania(terreno_t terreno, coordenada_t pos_centrales[], int tope_pos_centrales, int radio, color_t color_fondo, modo_fondo_t modo) {
    for (int i=0; i < TER_FIL; i++) {
        for (int j=0; j < TER_COL; j++) {
            for (int k=0; k < tope_pos_centrales; k++) {
                if (calcular_distancia((coordenada_t){ i, j }, pos_centrales[k]) <= radio) {
                    set_color_fondo(terreno[i][j], color_fondo);
                    set_modo_fondo(terreno[i][j], modo);
                    set_reset(terreno[i][j], 
                        // True si es la ultima columna
                        (j == TER_COL - 1) || 
                        // True si no hay que pintar en la siguiente posicion
                        (calcular_distancia((coordenada_t){ i, j + 1 }, pos_centrales[k]) > radio) 
                        );
                }
            }
        }
    }
}
//Pinta el alrededor de cada familiar
void estilo_cercania_familia(terreno_t terreno, juego_t juego) {
    if (juego.perry.camuflado) //si no esta modo agente
        return;

    coordenada_t f_posiciones[MAX_FAMILIARES];
    for (int i = 0; i < juego.tope_familiares; i++)
        f_posiciones[i] = juego.familiares[i].posicion;
    
    pintar_cercania(
        terreno,
        f_posiciones,
        juego.tope_familiares,
        RADIO_FAMILIA,
        ROJO,
        FONDO_BRILLANTE
    );
}
//Pinta el alrededor de cada robot
void estilo_cercania_robots(terreno_t terreno, juego_t juego) {
    bool modo_agente = !(juego.perry.camuflado);
    pintar_cercania(
        terreno,
        juego.robots,
        juego.cantidad_robots,
        RADIO_ROBOTS,
        modo_agente ? AMARILLO : ROJO,
        modo_agente ? FONDO_NORMAL : FONDO_BRILLANTE
    );
}
/* Coloca detalles visuales:
    - Pinta el alrededor de cada familiar
    - Pinta el alrededor de cada robot
*/
void colocar_estilos(terreno_t terreno, juego_t juego) {
    estilo_cercania_robots(terreno, juego);
    estilo_cercania_familia(terreno, juego);
}
// Imprime por consola las estadisticas de perry.
void mostrar_stats(personaje_t perry) {
    centrar_verticalmente(alto_contenido);

    reset_estilo();
    
    centrar_horizontalmente(ancho_contenido);
    printf("┏");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("━");
    printf("┓\n");

    centrar_horizontalmente(ancho_contenido);
    
    printf("┃");
    cursor(GUARDAR_POSICION_CURSOR);
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf(" ");
    printf("┃");
    printf("\n");

    cursor(RESTAURAR_POSICION_CURSOR);
    printf("%lc%d\t", VISTA_ENERGIA, perry.energia);
    
    imprimir_estilo(NORMAL, ROJO, TEXTO_BRILLANTE, DEFAULT_COLOR, FONDO_NORMAL);
    if (perry.vida <= 0)
        printf("(SIN VIDAS)");
    else 
        for (int i=0; i<perry.vida; i++)
            printf("%lc",VISTA_VIDA);
    reset_estilo();


    cursor(RESTAURAR_POSICION_CURSOR);
    mover_cursor_n_veces(MOVER_CURSOR_DERECHA, TER_COL * 2 - 1);
    if(!perry.camuflado)
        printf("%lc", VISTA_AGENTE);
    mover_cursor_n_veces(MOVER_CURSOR_INICIO_LINEA_ABAJO, 1);   
}
// Imprime por consola el terreno.
void mostrar_terreno(terreno_t terreno) {
    centrar_horizontalmente(ancho_contenido);
    printf("┏");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("━");
    printf("┓\n");
    for (int i = 0; i < TER_FIL; i++) {
        centrar_horizontalmente(ancho_contenido);
        printf("┃ ");
        for (int j = 0; j < TER_COL; j++) {
            if (get_caracter(terreno[i][j]) == PERRY)
                cursor(GUARDAR_POSICION_CURSOR);
            imprimir_styled_char(terreno[i][j]);
            printf(" ");
        }
        printf("┃\n");
    }
    centrar_horizontalmente(ancho_contenido);
    printf("┗");
    for (int i = 0; i < TER_COL * 2 + 1; i++)
        printf("━");
    printf("┛\n\n");
    cursor(RESTAURAR_POSICION_CURSOR);
    reset_estilo();
}

void imprimir_terreno(juego_t juego)
{
    terreno_t terreno;
    crear_terreno(terreno);
    if (terreno[0][0] == NULL)
        return;

    colocar_bombas(terreno, juego.bombas, juego.tope_bombas);
    colocar_herramientas(terreno, juego.herramientas, juego.tope_herramientas);
    colocar_familiares(terreno, juego.familiares, juego.tope_familiares);
    colocar_robots(terreno, juego.robots, juego.cantidad_robots);
    colocar_perry(terreno, juego.perry);

    colocar_estilos(terreno, juego);

    mostrar_stats(juego.perry);
    mostrar_terreno(terreno);

    destruir_terreno(terreno);
}




/*  Modifica la posicion un lugar arriba o abajo, segun lo especificado
    sentido: +1 para arriba, -1 para abajo.
    Si se cambia la coordenada devuelve true.
    En caso de llegar al borde no se cambia la coordenada y devuelve false
*/
bool mover_arriba_abajo(coordenada_t* posicion, int sentido) {
    int aux = posicion->fil - sentido;
    bool cambio = false;
    if(0 <= aux && aux < TER_FIL) {
        posicion->fil = aux;
        cambio = true;
    }
    return cambio;
}
/*  Modifica la posicion un lugar a la derecha o izquierda segun lo especificado
    sentido: +1 para derecha, -1 para izquierda.
    Si se cambia la coordenada devuelve true.
    En caso de llegar al borde no se cambia la coordenada y devuelve false
*/
bool mover_derecha_izquierda(coordenada_t* posicion, int sentido) {
    int aux = posicion->col + sentido;
    bool cambio = false;
    if(0 <= aux && aux < TER_COL) {
        posicion->col = aux;
        cambio = true;
    }
    return cambio;
}
/*  Modifica la posicion un lugar en el sentido especificado
    sentido debe ser una de estas: 'A','W','S','D'
    En caso de moverse por el terreno actualiza la posicion y devuelve true
    En caso de salirse del terreno no cambia nada y devuelve false
*/
bool mover(coordenada_t* posicion, char sentido) {
    switch (sentido)
    {
    case ARRIBA:
        return mover_arriba_abajo(posicion, +1);
    case ABAJO:
        return mover_arriba_abajo(posicion, -1);
    case DERECHA:
        return mover_derecha_izquierda(posicion, +1);
    case IZQUIERDA:
        return mover_derecha_izquierda(posicion, -1);
    }
    return false;
}

//  Agrega un robot al vector de robots, aumentando la cantidad de robots
void agregar_robot(juego_t* juego) {
    int* tope = &(juego->cantidad_robots);
    void* aux = realloc(juego->robots, sizeof(robot_t) * (size_t) (*tope + 1));
    if (!aux) {
        return;
    }
    juego->robots = aux;
    if (agarrar_rand_posicion(*juego, &(juego->robots[*tope]), RADIO_ROBOTS))
        (*tope)++;
}

// Resta la vida de perry en 1 y hace un efecto visual de perdida de vida
void perder_vida(juego_t* juego) {
    (juego->perry.vida)--;
    imprimir_estilo(NORMAL, DEFAULT_COLOR, TEXTO_NORMAL, ROJO, FONDO_NORMAL);
    rellenar_pantalla();
    reset_estilo();
}

// Decrementa el timer de las bombas y las hace explotar en caso de que lleguen a ser 0
void decrementar_timer_bombas(juego_t* juego) {
    for (int i = 0; i < juego->tope_bombas; i++) {
        bomba_t* bomba = &(juego->bombas[i]);
        if (!(bomba->desactivada)) {
            (bomba->timer)--;
            if (bomba->timer <= 0) {
                perder_vida(juego);
                bomba->desactivada = true;
            }
        }
    }
}

//  Cambia el sentido:
//  - IZQUIERDA <--> DERECHA
//  - ARRIBA <--> ABAJO
void cambiar_sentido(char* sentido) {
    switch (*sentido)
        {
        case ARRIBA:
            *sentido = ABAJO;
            break;
        case ABAJO:
            *sentido = ARRIBA;
            break;
        case DERECHA:
            *sentido = IZQUIERDA;
            break;
        case IZQUIERDA:
            *sentido = DERECHA;
            break;
        }
}
//  Mueve cada familiar en la direccion que le pertenece. En caso de llegar al borde se invierte el sentido.
void mover_familia(familiar_t familiares[MAX_FAMILIARES], int tope) {
    for (int i = 0; i<tope; i++) {
        coordenada_t* posicion = &(familiares[i].posicion);
        char* sentido = &(familiares[i].sentido);
        bool llego_al_borde = !mover(posicion, *sentido);
        if (llego_al_borde){
            cambiar_sentido(sentido);
            mover(posicion, *sentido);
        }
    }
}

//  Coloca el valor de herramienta1 en herramienta2 y viceversa.
void intercambiar_herramientas(herramienta_t* herramienta1, herramienta_t* herramienta2) {
    herramienta_t aux;
    aux = *herramienta1;
    *herramienta1 = *herramienta2;
    *herramienta2 = aux;
}
//  Elimina la primera herramienta que se encuentre en la posicion especificada.
//  La posicion mandada debe pertenecer a alguna herramienta
void eliminar_herramienta_en_posicion(herramienta_t herramientas[MAX_HERRAMIENTAS], int* tope, coordenada_t posicion) {
    (*tope)--;
    int i = 0;
    bool encontrado = false;
    while ((i < *tope) && (!encontrado)) {
        if (son_pos_iguales(herramientas[i].posicion, posicion)) {
            encontrado = true;
        } else {
            i++;
        }
    }
    intercambiar_herramientas(herramientas + i, herramientas + (*tope));
}
//  Desactiva la bomba que se encuentre en la posicion especificada
//  La posicion mandada debe pertenecer a alguna bomba
void desactivar_bomba_en_posicion(bomba_t bombas[MAX_BOMBAS], int tope, coordenada_t posicion) {
    int i = 0;
    bool encontrado = false;
    while ((i < tope) && (!encontrado)) {
        if (son_pos_iguales(bombas[i].posicion, posicion)) {
            encontrado = true;
        } else {
            i++;
        }
    }
    bombas[i].desactivada = true;
}
//  Coloca el valor de robot1 en robot2 y viceversa.
void intercambiar_robots(robot_t* robot1, robot_t* robot2) {
    robot_t aux;
    aux = *robot1;
    *robot1 = *robot2;
    *robot2 = aux;
}
//  Elimina el robot del indice indicado, disminuyendo la cantidad de robots
void eliminar_robot(coordenada_t** robots, int* tope, int indice) {
    if (*tope == 0)
        return;

    if (*tope == 1) {
        (*tope)--;
        free(*robots);
        *robots = NULL;

    } else {
        intercambiar_robots((*robots) + indice, (*robots) + ((*tope) - 1));

        robot_t* aux = realloc(*robots, sizeof(robot_t) * (size_t) ((*tope) - 1));
        if (!aux) {
            return;
        }
        (*tope)--;
        *robots = aux;
    }
}
//  Comprueba donde esta posicionado perry y toma acción al respecto.
void comprobar_posicion(juego_t* juego) {
    coordenada_t p_posicion = juego->perry.posicion;
    switch (objeto_en_posicion(*juego, p_posicion)) {
        case SOMBREROS:
            (juego->perry.vida)+= VIDA_AL_PISAR_SOMBRERO;
            eliminar_herramienta_en_posicion(juego->herramientas, &(juego->tope_herramientas), p_posicion);
            break;
        case GOLOSINAS:
            juego->perry.energia += ENERGIA_AL_PISAR_GOLOSINA;
            eliminar_herramienta_en_posicion(juego->herramientas, &(juego->tope_herramientas), p_posicion);
            break;
        case BOMBAS:
            //Si está modo agente y tiene energia suficiente
            if ((!juego->perry.camuflado) && (juego->perry.energia >= ENERGIA_PARA_DESACTIVAR_BOMBA)) {
                juego->perry.energia -= ENERGIA_PARA_DESACTIVAR_BOMBA;
                desactivar_bomba_en_posicion(juego->bombas, juego->tope_bombas, p_posicion);
            }
            break;
        default:
            break;
    }
    for (int i = 0; i < juego->tope_familiares; i++) 
        if (
            !juego->perry.camuflado && //Si esta en modo agente
            calcular_distancia(p_posicion, juego->familiares[i].posicion) <= RADIO_FAMILIA
        ) 
            perder_vida(juego);
    for (int i = 0; i < juego->cantidad_robots; i++)
        if (calcular_distancia(p_posicion, juego->robots[i]) <= RADIO_ROBOTS) {
            if (!juego->perry.camuflado) { //Si esta en modo agente 
                eliminar_robot(&(juego->robots), &(juego->cantidad_robots), i);
                if (juego->perry.energia > ENERGIA_PARA_DESTRUIR_ROBOT)
                    juego->perry.energia -= ENERGIA_PARA_DESTRUIR_ROBOT;
                else
                    perder_vida(juego);
            } else {
                perder_vida(juego);
            }
        }
}

void realizar_jugada(juego_t *juego, char accion) {
    personaje_t* perry = &(juego->perry);
    switch (accion)
    {
    case CAMUFLARSE:
        perry->camuflado = !perry->camuflado;
        break;
    
    case ARRIBA:
    case ABAJO:
    case DERECHA:
    case IZQUIERDA:
        if (mover(&(perry->posicion), accion)) {
            (juego->movimientos)++;
            if (juego->movimientos % 10 == 0)
                agregar_robot(juego);
            decrementar_timer_bombas(juego);
            mover_familia(juego->familiares, juego->tope_familiares);
        }
        break;
    }
    comprobar_posicion(juego);
}





// Retorna false si alguna de las bombas no se desactivó, retorna true si todas se desactivaron
bool bombas_desactivadas(int tope, bomba_t bombas[MAX_BOMBAS]) {
    bool todas_desactivadas = true;
    int i = 0;
    while (i < tope && todas_desactivadas)
        if (!bombas[i++].desactivada)
            todas_desactivadas = false;
    return todas_desactivadas;
}
// Destruye los robots
// Setea robots a NULL y la cantidad de robots a 0
void destruir_robots(robot_t** robots, int* tope) {
    if (robots != NULL && *robots != NULL) {
        free(*robots);
        *robots = NULL;
    }
    if (tope != NULL)
        *tope = 0;
}
// Libera la memoria dinamica creada a lo largo del juego. Esta funcion se debe llamar cuando el juego termine
void liberar_memoria(juego_t* juego) {
    destruir_robots(&(juego->robots), &(juego->cantidad_robots));
}
int estado_juego(juego_t juego) {

    //Ganó?
    if (bombas_desactivadas(juego.tope_bombas, juego.bombas)) {
        liberar_memoria(&juego);
        return GANADO;
    }

    //Perdió?
    if (juego.perry.vida <= 0) {
        liberar_memoria(&juego);
        return GAME_OVER;
    }

    //No ganó ni perdió.
    return EN_JUEGO;    
}