#include "dato.h"

#define     PILA_VACIA      0
#define     MEMORIA_LLENA      0
#define     OK              1

typedef struct s_nodo_pila
    {
    t_dato dato;
    struct s_nodo_pila *sig;
    }t_nodo_pila;

typedef t_nodo_pila* t_pila;

void crear_pila(t_pila*);
int pila_llena(const t_pila*);
int apilar(t_pila*,const t_dato*);
int pila_vacia(const t_pila*);
int desapilar(t_pila*,t_dato*);
int ver_tope(const t_pila*,t_dato*);
void vaciar_pila(t_pila*);
