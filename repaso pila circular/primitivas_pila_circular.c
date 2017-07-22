#include "primitivas_pila_circular.h"

void crear_pila(t_lista *p)
{
    *p=NULL;
}

int pila_vacia(const t_lista *p)
{
    return *p==NULL;
}

int pila_llena(const t_lista *p)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int apilar(t_lista *p,const t_dato *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    if(!*p)
        *p=nue;
    else
        nue->sig=(*p)->sig;
    (*p)->sig=nue;
    return OK;
}

int desapilar(t_lista *p,t_dato *d)
{
    t_nodo *aux;
    if(!*p)
        return PILA_VACIA;
    aux=(*p)->sig;
    *d=aux->dato;
    if(*p==aux)
        *p=NULL;
    else
        (*p)->sig=aux->sig;
    free(aux);
    return OK;
}

int ver_tope(const t_lista *p,t_dato *d)
{
    if(!*p)
        return PILA_VACIA;
    *d=(*p)->sig->dato;
    return OK;
}

void vaciar_pila(t_lista *p)
{
    t_nodo *aux,*pri=*p;
    *p=(*p)->sig;
    while(*p&&*p!=pri)
    {
    aux=*p;
    *p=aux->sig;
    free(aux);
    }
    free(*p);
    *p=NULL;
}
