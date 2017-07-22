#include <stdio.h>
#include <stdlib.h>

#define     ARBOL_VACIO     0
#define     ARBOL_LLENO     0

#define     FALSO           0
#define     VERDADERO       1

#define     ABS(x)      (((x)<0)?(-x):(x))

typedef struct
{
    int numero;
}t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *izq;
    struct s_nodo *der;
}t_nodo;

typedef t_nodo* t_arbol;

typedef int(*t_cmp)(const void*,const void*);
typedef void(*t_mst)(const void*);

void crear_arbol(t_arbol *a);
void vaciar_arbol(t_arbol *a);

int insertar_en_arbol_iterativa(t_arbol *a,const t_dato *d,t_cmp comparar);

int calcular_altura(const t_arbol *a);

int es_arbol_AVL(const t_arbol *a);

int es_arbol_balanceado(const t_arbol *a);
int es_arbol_balanceado_interna(const t_arbol *a,int altura);

int es_arbol_completo(const t_arbol *a);
int es_arbol_completo_interna(const t_arbol *a,int altura);

void graficar_arbol(const t_arbol *a,t_mst mostrar);
void graficar_arbol_interna(const t_arbol *a,int nivel,t_mst mostrar);

void tab(int nivel);
