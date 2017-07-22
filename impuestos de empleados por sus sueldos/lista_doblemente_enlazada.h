#include <stdio.h>
#include <stdlib.h>

#define     LISTA_VACIA         0
#define     MEMORIA_LLENA       0

#define     FALSO               0
#define     VERDADERO           1

typedef struct
{
    char cuit[12];
    int codigo_concepto;
}t_dato_lista;

typedef struct s_nodo_lista
{
    t_dato_lista dato;
    struct s_nodo_lista *ant;
    struct s_nodo_lista *sig;
}t_nodo_lista;

typedef t_nodo_lista* t_lista;

typedef int(*t_cmp)(const void*,const void*);

void crear_lista(t_lista *l);
int lista_vacia(const t_lista *l);

int insertar_en_lista_ordenada_con_duplicados(t_lista *l,const t_dato_lista *d,t_cmp comparar);
int sacar_primero_de_lista(t_lista *l,t_dato_lista *d);

int ver_primero_de_lista(const t_lista *l,t_dato_lista *d);
