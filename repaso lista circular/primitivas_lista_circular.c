#include "primitivas_lista_circular.h"

void crear_lista(t_lista *l)
{
    *l=NULL;
}

int lista_vacia(const t_lista *l)
{
    return *l==NULL;
}

int lista_llena(const t_lista *l)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

int poner_en_lista(t_lista *l,const t_dato *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;

    nue->dato=*d;
    if(*l)
    {
        nue->sig=(*l)->sig;
        (*l)->sig=nue;
    }
    else
    {
        *l=nue;
        nue->sig=nue;
    }
    return OK;
}

int sacar_de_lista(t_lista *l,t_dato *d)
{
    t_nodo *aux;
    if(!*l)
        return LISTA_VACIA;
    aux=(*l)->sig;
    *d=aux->dato;
    if(*l==aux)
        *l=NULL;
    else
        (*l)->sig=aux->sig;
    free(aux);
    return OK;
}

int ver_primero_de_lista(const t_lista *l,t_dato *d)
{
    if(!*l)
        return LISTA_VACIA;
    *d=(*l)->dato;
    return OK;
}

void vaciar_lista(t_lista *l)
{
    t_nodo *aux,*pri=*l;
    while(*l&&*l!=pri)
    {
        aux=*l;
        l=&(*l)->sig;
        free(aux);
    }
    free(*l);
    *l=NULL;
}
