#include "primitivas_cola_dinámica.h"

void crear_cola(t_cola *c)
{
    c->pri=NULL;
    c->ult=NULL;
}

int cola_vacia(const t_cola *c)
{
    return c->pri==NULL;
}

int cola_llena(const t_cola *c)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int acolar(t_cola *c,const t_dato *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    nue->sig=NULL;
    if(c->ult==NULL)
        c->pri=nue;
    else
        c->ult->sig=nue;
    c->ult=nue;
    return OK;
}

int desacolar(t_cola *c,t_dato *d)
{
    t_nodo *aux;
    if(c->pri==NULL)
        return COLA_VACIA;
    aux=c->pri;
    *d=aux->dato;
    c->pri=aux->sig;
    if(c->pri==NULL)
        c->ult=NULL;
    free(aux);
    return OK;
}

int ver_primero(const t_cola *c,t_dato *d)
{
    if(c->pri==NULL)
        return COLA_VACIA;
    *d=c->pri->dato;
    return OK;
}

int ver_ultimo(const t_cola *c,t_dato *d)
{
    if(c->pri==NULL)
        return COLA_VACIA;
    *d=c->ult->dato;
    return OK;
}

void vaciar_cola(t_cola *c)
{
    t_nodo *aux;
    while(c->pri)
    {
        aux=c->pri;
        c->pri=aux->sig;
        free(aux);
    }
    c->ult=NULL;
}
