#include<stdio.h>
#include<stdlib.h>

#include "lista_simplemente_enlazada.h"

void crear_lista(t_lista *l)
    {
    *l=NULL;
    }

int lista_vacia(const t_lista *l)
    {
    return *l==NULL;
    }

int sacar_de_lista_primero(t_lista *l,t_dato *d)
    {
    if(!*l)
        return LISTA_VACIA;
    t_nodo *aux=*l;
    *d=aux->dato;
    *l=aux->sig;
    free(aux);
    return OK;
    }

int insertar_en_lista_ordenado_con_duplicado(t_lista *l,const t_dato *d,t_cmp comparar)
    {
    int cmp;
    while(*l&&(cmp=comparar((void*)&(*l)->dato,(void*)d)<=0))
        l=&(*l)->sig;
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    nue->sig=*l;
    *l=nue;
    return OK;
    }
