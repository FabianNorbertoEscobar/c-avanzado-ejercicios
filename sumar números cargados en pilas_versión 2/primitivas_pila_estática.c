#include "primitivas_pila_estática.h"

void crear_pila(t_pila *p)
    {
    p->tope=0;
    }

int pila_llena(const t_pila *p)
    {
    return p->tope==TAM;
    }

int apilar(t_pila *p,const t_dato *d)
    {
    if(p->tope==TAM)
        return PILA_LLENA;
    p->pila[p->tope]=*d;
    p->tope++;
    return OK;
    }

int pila_vacia(const t_pila *p)
    {
    return p->tope==0;
    }

int desapilar(t_pila *p,t_dato *d)
    {
    if(p->tope==0)
        return PILA_VACIA;
    p->tope--;
    *d=p->pila[p->tope];
    return OK;
    }

int ver_tope(const t_pila *p,t_dato *d)
    {
    if(p->tope==0)
        return PILA_VACIA;
    *d=p->pila[p->tope-1];
    return OK;
    }

void vaciar_pila(t_pila *p)
    {
    p->tope=0;
    }

