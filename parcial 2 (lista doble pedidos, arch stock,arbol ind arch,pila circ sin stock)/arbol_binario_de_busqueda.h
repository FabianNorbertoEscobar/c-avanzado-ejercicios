#include <stdio.h>
#include <stdlib.h>

#define     ARBOL_VACIO         0
#define     MEMORIA_LLENA       0
#define     DUPLICADO           0
#define     NO_ENCONTRADO       0
#define     OK                  1

typedef struct
{
    int posicion_en_archivo;
    char codigo_producto[6];
}t_dato_arbol;

typedef struct s_nodo_arbol
{
    t_dato_arbol dato;
    struct s_nodo_arbol *izq;
    struct s_nodo_arbol *der;
}t_nodo_arbol;

typedef t_nodo_arbol* t_arbol;

typedef int(*t_cmp)(const void*,const void*);
typedef void(*t_mst)(const void*);

void crear_arbol(t_arbol*);
int arbol_vacio(const t_arbol*);
int arbol_lleno(const t_arbol*);
int insertar_en_arbol(t_arbol*,const t_dato_arbol*,t_cmp);
int buscar_en_arbol_y_retornar_dato(const t_arbol*,t_dato_arbol*,void *clave,t_cmp);
void vaciar_arbol(t_arbol*);
