#include "lista_doblemente_enlazada.h"

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

int insertar_en_lista_ordenada_sin_duplicados(t_lista *l,const t_dato *d,t_cmp comparar)
{
    int cmp;
    t_nodo *act=*l;
    t_nodo *ant=NULL;
    t_nodo *sig=NULL;

    if(act)
    {
        while(act->sig&&comparar((void*)&act->dato,(void*)d)<0)
            act=act->sig;
        while(act->ant&&comparar((void*)&act->dato,(void*)d)>0)
            act=act->ant;

        if(!(cmp=comparar((void*)&act->dato,(void*)d)))
            return DUPLICADO;

        if(cmp>0)
        {
            sig=act;
            ant=act->ant;
        }
        else
        {
            ant=act;
            sig=act->sig;
        }
    }

    act=(t_nodo*)malloc(sizeof(t_nodo));
    if(!act)
        return MEMORIA_LLENA;

    act->dato=*d;
    act->ant=ant;
    act->sig=sig;

    if(ant)
        ant->sig=act;
    if(sig)
        sig->ant=act;

    *l=act;
    return OK;
}

int insertar_en_lista_ordenada_con_duplicados(t_lista *l,const t_dato *d,t_cmp comparar)
{
    t_nodo *act=*l;
    t_nodo *ant=NULL;
    t_nodo *sig=NULL;

    if(act)
    {
        while(act->sig&&comparar((void*)&act->dato,(void*)d)<0)
            act=act->sig;
        while(act->ant&&comparar((void*)&act->dato,(void*)d)>0)
            act=act->ant;

        if(comparar((void*)&act->dato,(void*)d)>0)
        {
            sig=act;
            ant=act->ant;
        }
        else
        {
            ant=act;
            sig=act->sig;
        }
    }

    act=(t_nodo*)malloc(sizeof(t_nodo));
    if(!act)
        return MEMORIA_LLENA;

    act->dato=*d;
    act->ant=ant;
    act->sig=sig;

    if(ant)
        ant->sig=act;
    if(sig)
        sig->ant=act;

    *l=act;
    return OK;
}

int eliminar_de_lista_ordenada_con_clave(t_lista *l,t_dato *d,void *clave,t_cmp comparar)
{
    t_nodo *act=*l;
    t_nodo *ant;
    t_nodo *sig;

    if(!act)
        return LISTA_VACIA;

    while(act->sig&&comparar((void*)&act->dato,(void*)clave)<0)
        act=act->sig;
    while(act->ant&&comparar((void*)&act->dato,(void*)clave)>0)
        act=act->ant;

    if(comparar((void*)&act->dato,(void*)clave))
        return NO_ENCONTRADO;

    *d=act->dato;
    ant=act->ant;
    sig=act->sig;

    if(ant)
    {
        ant->sig=sig;
        *l=ant;
    }

    if(sig)
    {
        sig->ant=ant;
        *l=sig;
    }

    if(!ant&&!sig)
        *l=NULL;

    free(act);
    return OK;
}

int ver_primero_de_lista(const t_lista *l,t_dato *d)
{
    if(!*l)
        return LISTA_VACIA;

    while((*l)->ant)
        l=&(*l)->ant;

    *d=(*l)->dato;
    return OK;
}

int ver_ultimo_de_lista(const t_lista *l,t_dato *d)
{
    if(!*l)
        return LISTA_VACIA;

    while((*l)->sig)
        l=&(*l)->sig;

    *d=(*l)->dato;
    return OK;
}

void mostrar_lista_orden_ascendente(const t_lista *l,t_mst mostrar)
{
    while((*l)->ant)
        l=&(*l)->ant;

    mostrar((void*)&(*l)->dato);
    while((*l)->sig)
    {
        l=&(*l)->sig;
        mostrar((void*)&(*l)->dato);
    }
}

void mostrar_lista_orden_descendente(const t_lista *l,t_mst mostrar)
{
    while((*l)->sig)
        l=&(*l)->sig;

    mostrar((void*)&(*l)->dato);
    while((*l)->ant)
    {
        l=&(*l)->ant;
        mostrar((void*)&(*l)->dato);
    }
}

void vaciar_lista(t_lista *l)
{
    t_nodo *aux;

    while((*l)->sig)
        l=&(*l)->sig;

    while((*l)->sig)
    {
        aux=*l;
        l=&(*l)->sig;
        free(aux);
    }

    *l=NULL;
}
