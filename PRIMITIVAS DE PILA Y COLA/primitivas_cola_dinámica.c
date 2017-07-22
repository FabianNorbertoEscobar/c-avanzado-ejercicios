#include "primitivas_cola_dinámica.h"

//no sé por qué si no incluyo las bibliotecas tira error
#include<stdio.h>
#include<stdlib.h>

void crear_cola(t_cola *c)
    {
    c->pri=NULL;
    c->ult=NULL;
    }

int cola_llena(const t_cola *c)
    {
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
    }

int acolar(t_cola *c,const t_dato *d)
    {
    t_nodo *nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return MEMORIA_LLENA;
    nuevo->dato=*d;
    nuevo->sig=NULL;
    if(c->ult==NULL)
        c->pri=nuevo;
    else
        c->ult->sig=nuevo;
    c->ult=nuevo;
    return OK;
    }

int cola_vacia(const t_cola *c)
    {
    return c->pri==NULL;
    }

int desacolar(t_cola *c,t_dato *d)
    {
    if(c->pri==NULL)
        return COLA_VACIA;
    t_nodo *aux=c->pri;
    *d=aux->dato;//*d=c->prim->dato;
    c->pri=aux->sig;//c->pri=c->pri->sig;
    if(c->pri==NULL)
        c->ult=NULL;
    free(aux);
    return OK;
    }

int ver_primero_en_cola(const t_cola *c,t_dato *d)
    {
    if(c->pri==NULL)
        return COLA_VACIA;
    *d=c->pri->dato;
    return OK;
    }

int ver_ultimo_en_cola(const t_cola *c,t_dato *d)
    {
    if(c->pri==NULL)
        return COLA_VACIA;
    *d=c->ult->dato;
    return OK;
    }

void vaciar_cola(t_cola *c)
    {
    t_nodo *aux;
    while(c->pri!=NULL)
        {
        aux=c->pri;
        c->pri=aux->sig;
        free(aux);
        }
    c->ult=NULL;
    }
