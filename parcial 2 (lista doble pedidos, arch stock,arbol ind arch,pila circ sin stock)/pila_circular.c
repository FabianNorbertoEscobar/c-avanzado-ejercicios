#include "pila_circular.h"

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
    void *aux=malloc(sizeof(t_nodo_pila));
    free(aux);
    return aux==NULL;
}

int apilar(t_pila *p,const t_dato_pila *d)
{
    t_nodo_pila *nuevo=(t_nodo_pila*)malloc(sizeof(t_nodo_pila));

    if(!nuevo)
        return MEMORIA_LLENA;
    nuevo->dato=*d;

    if(!*p)
        *p=nuevo;
    else
        nuevo->sig=(*p)->sig;

    (*p)->sig=nuevo;
    return OK;
}

int desapilar(t_pila *p,t_dato_pila *d)
{
    t_nodo_pila *aux;

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
