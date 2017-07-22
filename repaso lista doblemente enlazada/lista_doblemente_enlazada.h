#include "dato.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     LISTA_VACIA         0
#define     MEMORIA_LLENA       0
#define     DUPLICADO           0
#define     NO_ENCONTRADO       0
#define     OK                  1

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *ant;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_lista;

typedef int(*t_cmp)(const void*,const void*);
typedef void(*t_mst)(const void*);

void crear_lista(t_lista*);
int lista_vacia(const t_lista*);
int lista_llena(const t_lista*);
int insertar_en_lista_ordenada_sin_duplicado(t_lista*,const t_dato*,t_cmp);
int insertar_en_lista_ordenada_con_duplicado(t_lista*,const t_dato*,t_cmp);
int eliminar_de_lista_ordenada_por_clave(t_lista*,t_dato*,void*,t_cmp);
int eliminar_primero_de_lista(t_lista*,t_dato*);
int eliminar_ultimo_de_lista(t_lista*,t_dato*);
int ver_nodo_actual_de_lista(const t_lista*,t_dato*);
int ver_primero_de_lista(const t_lista*,t_dato*);
int ver_ultimo_de_lista(const t_lista*,t_dato*);
void mostrar_lista_orden_ascendente(const t_lista*,t_mst);
void mostrar_lista_orden_descendente(const t_lista*,t_mst);
int contar_nodos_de_lista(const t_lista*);
void vaciar_lista(t_lista*);
