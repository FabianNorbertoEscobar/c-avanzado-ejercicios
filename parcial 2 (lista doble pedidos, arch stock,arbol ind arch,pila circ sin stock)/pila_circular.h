#include <stdio.h>
#include <stdlib.h>

#define     PILA_VACIA          0
#define     MEMORIA_LLENA       0
#define     OK                  1

typedef struct
{
    char codigo_producto[6];
    int cantidad_pedida;
}t_dato_pila;

typedef struct s_nodo_pila
{
    t_dato_pila dato;
    struct s_nodo_pila *sig;
}t_nodo_pila;

typedef t_nodo_pila* t_pila;

void crear_pila(t_pila*);
int pila_vacia(const t_pila*);
int pila_llena(const t_pila*);
int apilar(t_pila*,const t_dato_pila*);
int desapilar(t_pila*,t_dato_pila*);
