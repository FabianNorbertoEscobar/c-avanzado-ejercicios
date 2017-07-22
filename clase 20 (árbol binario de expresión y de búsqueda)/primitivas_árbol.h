#include "primitivas_pila_dinámica.h"

#include<stdio.h>
#include<stdlib.h>

#define     ARBOL_VACIO     0
#define     MEMORIA_LLENA   0
#define     DUPLICADO       0
#define     NO_ENCONTRADO   0
#define     OK              1

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *izq;
    struct s_nodo *der;
}t_nodo;

typedef t_nodo* t_arbol;

typedef int(*t_cmp)(const void*,const void*);
typedef void(*t_mst)(const void*);

void crear_arbol(t_arbol*);
void vaciar_arbol(t_arbol*);

int arbol_vacio(const t_arbol*);
int arbol_lleno(const t_arbol*);

void recorrer_arbol_inorden_recursiva(const t_arbol*,t_mst);
void recorrer_arbol_preorden_recursiva(const t_arbol*,t_mst);
void recorrer_arbol_posorden_recursiva(const t_arbol*,t_mst);

void recorrer_arbol_inorden_iterativa(const t_arbol*,t_mst);
void recorrer_arbol_preorden_iterativa(const t_arbol*,t_mst);
void recorrer_arbol_posorden_iterativa(const t_arbol*,t_mst);

int insertar_en_arbol_recursiva(t_arbol*,const t_dato*,t_cmp);
int insertar_en_arbol_iterativa(t_arbol*,const t_dato*,t_cmp);

int buscar_en_arbol_recursiva(const t_arbol*,t_dato*,t_cmp);
int buscar_en_arbol_iterativa(const t_arbol*,t_dato*,t_cmp);

t_nodo *buscar_en_arbol_y_retornar_direccion_padre_recursiva(const t_arbol*,t_dato*,t_cmp);
t_nodo *buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(const t_arbol*,t_dato*,t_cmp,t_nodo*);
t_nodo *buscar_en_arbol_y_retornar_direccion_padre_iterativa(const t_arbol*,t_dato*,t_cmp);

void grabar_arbol_en_inorden_en_archivo_binario(const t_arbol*,FILE*);
void grabar_arbol_en_preorden_en_archivo_binario(const t_arbol*,FILE*);
void grabar_arbol_en_posorden_en_archivo_binario(const t_arbol*,FILE*);

void grabar_arbol_en_inorden_en_archivo_de_texto(const t_arbol*,FILE*);
void grabar_arbol_en_preorden_en_archivo_de_texto(const t_arbol*,FILE*);
void grabar_arbol_en_posorden_en_archivo_de_texto(const t_arbol*,FILE*);

int cargar_arbol_en_preorden_desde_archivo_binario(t_arbol*,FILE*,t_cmp);
int cargar_arbol_en_posorden_desde_archivo_binario(t_arbol*,FILE*,t_cmp);

int cargar_arbol_en_preorden_desde_archivo_de_texto(t_arbol*,FILE*,t_cmp);
int cargar_arbol_en_posorden_desde_archivo_de_texto(t_arbol*,FILE*,t_cmp);
