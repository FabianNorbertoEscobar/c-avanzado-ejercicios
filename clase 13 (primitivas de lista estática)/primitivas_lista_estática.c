#include "primitivas_lista_estática.h"

void crear_lista(t_lista *l)
    {
    l->indice=0;
    l->ce=0;
    }

int lista_vacia(const t_lista *l)
    {
    return l->ce==0;
    }

int lista_llena(const t_lista *l)
    {
    return l->ce==TAM;
    }

int poner_en_lista(t_lista *l,const t_dato *d,t_cmp comparar)
    {
    int i,pos=0;
    if(l->ce==TAM)
        return LISTA_LLENA;
    l->dato[l->indice]=*d;
    while(l->ce>pos&&comparar((void*)&l->dato[l->pos[pos]],(void*)d))
        pos++;
    for(i=l->ce;i>=pos;i--)
        l->pos[pos]=l->indice;
    l->indice++;
    l->ce++;
    return OK;
    }

int sacar_de_lista(t_lista *l,t_dato *d)
    {
    int i;
    if(l->ce==0)
        return LISTA_VACIA;
    *d=l->dato[l->pos[0]];
    for(i=0;i<l->ce;i++)
        l->pos[i]=l->pos[i+1];
    l->ce--;
    return OK;
    }

int ver_primero_de_lista(const t_lista *l,t_dato *d)
    {
    if(l->ce==0)
        return LISTA_VACIA;
    *d=l->dato[l->pos[l->ce]];
    return OK;
    }

void vaciar_lista(t_lista *l)
    {
    l->indice=0;
    l->ce=0;
    }
