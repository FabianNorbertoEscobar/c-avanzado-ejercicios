#include "primitivas_pila_dinámica.h"

void crear_pila(t_pila *p)
{
    *p=NULL;
}

int pila_vacia(const t_pila *p)
{
    return *p==NULL;
}

int pila_llena(const t_pila *p)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int apilar(t_pila *p,const t_dato *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    nue->sig=*p;
    *p=nue;
    return OK;
}

int desapilar(t_pila *p,t_dato *d)
{
    t_nodo *aux;
    if(!*p)
        return PILA_VACIA;
    aux=*p;
    *d=aux->dato;
    *p=aux->sig;
    free(aux);
    return OK;
}

int ver_tope(const t_pila *p,t_dato *d)
{
    if(!*p)
        return PILA_VACIA;
    *d=(*p)->dato;
    return OK;
}

void vaciar_pila(t_pila *p)
{
    t_nodo *aux;
    while(*p)
    {
        aux=*p;
        (*p)=aux->sig;
        free(aux);
    }
}
