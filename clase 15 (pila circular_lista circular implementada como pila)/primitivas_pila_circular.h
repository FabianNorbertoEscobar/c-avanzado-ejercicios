#include "dato.h"

#define         MEMORIA_LLENA         0
#define         PILA_VACIA         0
#define         OK                  1

typedef struct s_nodo
    {
    t_dato dato;
    struct s_nodo *sig;
    }t_nodo;

typedef t_nodo* t_lista;

void crear_pila(t_lista*);
int pila_vacia(const t_lista*);
int pila_llena(const t_lista*);
int apilar(t_lista*,const t_dato*);
int desapilar(t_lista*,t_dato*);
int ver_tope(const t_lista*,t_dato*);
void vaciar_pila(t_lista*);
