#include <stdio.h>
#include <stdlib.h>

#define     LISTA_VACIA         0
#define     MEMORIA_LLENA       0
#define     OK                  1

typedef struct
{
    char codigo_producto[6];//clave
    int cantidad_pedida;
}t_dato_lista;

typedef struct s_nodo_lista
{
    t_dato_lista dato;
    struct s_nodo_lista *ant;
    struct s_nodo_lista *sig;
}t_nodo_lista;

typedef t_nodo_lista* t_lista;

typedef int(*t_cmp)(const void*,const void*);

void crear_lista(t_lista*);
int lista_vacia(const t_lista*);
int lista_llena(const t_lista*);
int insertar_en_lista_doble_ordenada_con_duplicado(t_lista*,const t_dato_lista*,t_cmp);
int sacar_primero_de_la_lista(t_lista*,t_dato_lista*);
int ver_primero_de_lista(const t_lista*,t_dato_lista*);
