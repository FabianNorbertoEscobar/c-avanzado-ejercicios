#include "dato.h"

#include<stdio.h>
#include<stdlib.h>

#define     LISTA_VACIA         0
#define     MEMORIA_LLENA       0
#define     ENCONTRADO          0
#define     NO_ENCONTRADO       0
#define     DUPLICADO           0
#define     OK                  1

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_lista;

typedef int(*t_cmp)(const void*,const void*);

void crear_lista(t_lista*);
void vaciar_lista(t_lista*);

int lista_vacia(const t_lista*);
int lista_llena(const t_lista*);

int poner_en_lista_primero(t_lista*,const t_dato*);
int poner_en_lista_ultimo(t_lista*,const t_dato*);

int sacar_de_lista_primero(t_lista*,t_dato*);
int sacar_de_lista_ultimo(t_lista*,t_dato*);

int insertar_en_lista_por_posicion(t_lista*,const t_dato*,unsigned*);

int insertar_en_lista_ordenada_con_duplicado(t_lista*,const t_dato*,t_cmp);
int insertar_en_lista_ordenada_sin_duplicado(t_lista*,const t_dato*,t_cmp);

//int insertar_en_lista_si_no_existe_clave(t_lista*,const t_dato*,int);

int buscar_en_lista_ordenada(t_lista*,const t_dato*,t_cmp);
int buscar_en_lista_desordenada(t_lista*,const t_dato*,t_cmp);

int eliminar_por_clave_en_lista_ordenada(t_lista*,void*,t_cmp);
int eliminar_por_clave_en_lista_desordenada(t_lista*,void*,t_cmp);

void eliminar_todas_ocurrencias_en_lista_ordenada(t_lista*,void*,t_cmp);
void eliminar_todas_ocurrencias_en_lista_desordenada(t_lista*,void*,t_cmp);
