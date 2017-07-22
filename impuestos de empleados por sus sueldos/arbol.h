#include <stdio.h>
#include <stdlib.h>

#define     ARBOL_VACIO         0
#define     MEMORIA_LLENA       0

#define     FALSO               0
#define     VERDADERO           1

typedef struct
{
    int codigo_concepto;
    float importe_concepto;
}t_dato_arbol;

typedef struct s_nodo_arbol
{
    t_dato_arbol dato;
    struct s_nodo_arbol *izq;
    struct s_nodo_arbol *der;
}t_nodo_arbol;

typedef t_nodo_arbol* t_arbol;

typedef int(*t_cmp)(const void*,const void*);

void crear_arbol(t_arbol *a);
int insertar_en_arbol_iterativa(t_arbol *a,const t_dato_arbol *d,t_cmp comparar);

int buscar_en_arbol_iterativa_y_retornar_dato(t_arbol *a,t_dato_arbol *d,void *clave,t_cmp comparar);
int buscar_en_arbol_iterativa_y_actualizar_dato(t_arbol *a,const t_dato_arbol *d,void *clave,t_cmp comparar);
