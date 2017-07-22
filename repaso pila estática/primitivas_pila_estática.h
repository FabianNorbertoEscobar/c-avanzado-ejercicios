#include "dato.h"

#define     PILA_VACIA      0
#define     PILA_LLENA      0
#define     OK              1

typedef struct
{
    t_dato pila[TAM];
    int tope;
}t_pila;

void crear_pila(t_pila*);
int pila_vacia(const t_pila*);
int pila_llena(const t_pila*);
int apilar(t_pila*,const t_dato*);
int desapilar(t_pila*,t_dato*);
int ver_tope(const t_pila*,t_dato*);
void vaciar_pila(t_pila*);
