#include "primitivas_pila_dinámica.h"

//no sé por qué si no pongo las bibliotecas acá me tira error
#include<stdio.h>
#include<stdlib.h>

void crear_pila(t_pila *p)
    {
    *p=NULL;
    }

int pila_llena(const t_pila *p)
    {
    void *aux=malloc(sizeof(t_nodo_pila));
    free(aux);
    return aux==NULL;
    }

int apilar(t_pila *p,const t_dato *d)
    {
    t_nodo_pila *nuevo=(t_nodo_pila*)malloc(sizeof(t_nodo_pila));
    if(!nuevo)
        return MEMORIA_LLENA;
    nuevo->dato=*d;
    nuevo->sig=*p;
    *p=nuevo;
    return OK;
    }

int pila_vacia(const t_pila *p)
    {
    return *p==NULL;
    }

int desapilar(t_pila *p,t_dato *d)
    {
    if(*p==NULL)
        return PILA_VACIA;
    t_nodo_pila *aux=*p;
    *d=(*p)->dato;//*d=aux->dato;
    *p=aux->sig;//*p=(*p)->sig;
    free(aux);
    return OK;
    }

int ver_tope(const t_pila *p,t_dato *d)
    {
    if(*p==NULL)
        return PILA_VACIA;
    *d=(*p)->dato;
    return OK;
    }

void vaciar_pila(t_pila *p)
    {
    t_nodo_pila *aux;
    while(*p)
        {
        aux=*p;
        *p=aux->sig;
        free(aux);
        }
    }
