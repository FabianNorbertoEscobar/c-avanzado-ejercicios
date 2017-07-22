#include "primitivas_cola_circular.h"

void crear_cola(t_lista *c)
{
    *c=NULL;
}

int cola_vacia(const t_lista *c)
{
    return *c==NULL;
}

int cola_llena(const t_lista *c)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int acolar(t_lista *c,const t_dato *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    if(!*c)
        nue->sig=nue;
    else
    {
        nue->sig=(*c)->sig;
        (*c)->sig=nue;
    }
    *c=nue;
    return OK;
}

int desacolar(t_lista *c,t_dato *d)
{
    t_nodo *aux;
    if(!*c)
        return COLA_VACIA;
    aux=(*c)->sig;
    *d=aux->dato;
    if(*c==aux)
        *c=NULL;
    else
        (*c)->sig=aux->sig;
    free(aux);
    return OK;
}

int ver_primero_en_cola(const t_lista *c,t_dato *d)
{
    if(!*c)
        return COLA_VACIA;
    *d=(*c)->sig->dato;
    return OK;
}

int ver_ultimo_en_cola(const t_lista *c,t_dato *d)
{
    if(!*c)
        return COLA_VACIA;
    *d=(*c)->dato;
    return OK;
}

void vaciar_cola(t_lista *c)
{
    t_nodo *aux,*ult=*c;
    *c=(*c)->sig;
    while(*c&&*c!=ult)
    {
        aux=*c;
        *c=aux->sig;
        free(aux);
    }
    free(*c);
    *c=NULL;
}
