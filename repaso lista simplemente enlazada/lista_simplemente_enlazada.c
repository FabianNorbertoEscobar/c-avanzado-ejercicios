#include "lista_simplemente_enlazada.h"

void crear_lista(t_lista *l)
{
    *l=NULL;
}

void vaciar_lista(t_lista *l)
{
    t_nodo *aux;
    while(*l)
    {
        aux=*l;
        (*l)=aux->sig;
        free(aux);
    }
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

int poner_en_lista_primero(t_lista *l,const t_dato *d)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    nue->sig=*l;
    *l=nue;
    return OK;
}

int poner_en_lista_ultimo(t_lista *l,const t_dato *d)
{
    while(*l)
        l=&(*l)->sig;
    *l=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*l)
        return MEMORIA_LLENA;
    (*l)->dato=*d;
    (*l)->sig=NULL;
    return OK;
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

int sacar_de_lista_ultimo(t_lista *l,t_dato *d)
{
    if(!*l)
        return LISTA_VACIA;
    while((*l)->sig)
        l=&(*l)->sig;
    t_nodo *aux=*l;
    *d=aux->dato;
    *l=NULL;
    free(aux);
    return OK;
}

int insertar_en_lista_por_posicion(t_lista *l,const t_dato *d,unsigned *pos)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    while(*l&&*pos-->1)
        l=&(*l)->sig;
    nue->dato=*d;
    nue->sig=*l;
    *l=nue;
    return OK;
}

int insertar_en_lista_ordenada_con_duplicado(t_lista *l,const t_dato *d,t_cmp comparar)
{
    while(*l&&comparar((void*)&(*l)->dato,(void*)d)<=0)
        l=&(*l)->sig;
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    nue->sig=*l;
    *l=nue;
    return OK;
}
/*
int insertar_en_lista_ordenada_sin_duplicado(t_lista l*,const t_dato *d,t_cmp comparar)
{
    int cmp;
    while(*l&&(cmp=comparar((void*)&(*l)->sig,(void*)d))<0)
    {
        if(!cmp)
            return DUPLICADO;
        l=&(*l)->sig;
    }
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    nue->sig=*l;
    *l=nue;
    return OK;
}

 ESTA FUNCIÓN ANDA PERO LA PODEMOS RETOCAR PARA QUE SEA UN POCO MÁS EFICIENTE--> QUEDA ASÍ
*/

int insertar_en_lista_ordenada_sin_duplicado(t_lista *l,const t_dato *d,t_cmp comparar)
{
    while(*l&&comparar((void*)&(*l)->sig,(void*)d)<0)
        l=&(*l)->sig;
    if(*l&&!comparar((void*)&(*l)->sig,(void*)d))
        return DUPLICADO;
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return MEMORIA_LLENA;
    nue->dato=*d;
    nue->sig=*l;
    *l=nue;
    return OK;
}

/*
    esta función solo tiene sentido si se implementa un tipo de dato que contenga un campo clave y un campo contador de la cantidad de repeticiones

int insertar_en_lista_si_no_existe_clave(t_lista *l,const t_dato *d,int clave)
{
    while(*l&&(*l)->dato.clave!=clave)
        l=&(*l)->sig;
    if(*l)
    {
        (*l)->dato.cant_rep++;
        return CLAVE_DUPLICADA;//return 1, ya que la inserción no se hizo pero se aumentó el contador de la cantidad de repeticiones
    }
    *l=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*l)
        return MEMORIA_LLENA;
    (*l)->dato.clave=clave;
    (*l)->dato.cant_rep=0;
    (*l)->sig=NULL;
    return OK;
}
*/

int buscar_en_lista_ordenada(t_lista *l,const t_dato *d,t_cmp comparar)
{
    while(*l&&comparar((void*)&(*l)->sig,(void*)d)<0)
        l=&(*l)->sig;
    if(*l&&!comparar((void*)&(*l)->sig,(void*)d))
        return NO_ENCONTRADO;
    return ENCONTRADO;
}

int buscar_en_lista_desordenada(t_lista *l,const t_dato *d,t_cmp comparar)
{
    while(*l&&comparar((void*)&(*l)->sig,(void*)d))
        l=&(*l)->sig;
    if(*l)
        return NO_ENCONTRADO;
    return ENCONTRADO;
}

int eliminar_por_clave_en_lista_ordenada(t_lista *l,void *clave,t_cmp comparar)
{
    while(*l&&comparar((void*)&(*l)->dato,(void*)clave)<0)
        l=&(*l)->sig;
    if(*l&&comparar((void*)&(*l)->dato,(void*)clave))
        return NO_ENCONTRADO;
    t_nodo *aux=*l;
    *l=aux->sig;
    free(aux);
    return OK;
}

int eliminar_por_clave_en_lista_desordenada(t_lista *l,void *clave,t_cmp comparar)
{
    while(*l&&comparar((void*)&(*l)->dato,(void*)clave)!=0)
        l=&(*l)->sig;
    if(!*l)
        return NO_ENCONTRADO;
    t_nodo *aux=*l;
    *l=aux->sig;
    free(aux);
    return OK;
}

void eliminar_todas_ocurrencias_en_lista_ordenada(t_lista *l,void *clave,t_cmp comparar)
{
    t_nodo *aux;
    while(*l&&comparar((void*)&(*l)->dato,(void*)clave)<0)
    {
        if(!comparar((void*)&(*l)->dato,(void*)clave))
        {
            aux=*l;
            *l=aux->sig;
            free(aux);
        }
        l=&(*l)->sig;
    }
}

void eliminar_todas_ocurrencias_en_lista_desordenada(t_lista *l,void *clave,t_cmp comparar)
{
    t_nodo *aux;
    while(*l)
    {
        if(!comparar((void*)&(*l)->dato,(void*)clave))
        {
            aux=*l;
            *l=aux->sig;
            free(aux);
        }
        l=&(*l)->sig;
    }
}
