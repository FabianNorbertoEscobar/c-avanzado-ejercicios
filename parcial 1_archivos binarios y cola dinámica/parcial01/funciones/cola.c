#include <stdio.h>
#include <stdlib.h>
#include <cola.h>

void crearCola(t_cola *cola)
{
    cola->frente=NULL;
    cola->fondo=NULL;
}

int colaVacia(const t_cola *cola)
{
    if(cola->frente!=NULL)
        return 0;
    return 1;
}

int colaLLena(const t_cola *cola)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    if(aux==NULL)
        return 0;
    return 1;
}

int ponerEnCola(t_cola *cola, const t_info *info)
{
    t_nodo *nuevo=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nuevo)
        return 0;
    nuevo->info=*info;
    nuevo->sig=NULL;
    if(cola->fondo==NULL)
        cola->frente=nuevo;
    else
        cola->fondo->sig=nuevo;
    cola->fondo=nuevo;
    return 1;
}

int sacarDeCola(t_cola *cola, t_info *info)
{
    if(cola->frente==NULL)
        return 0;
    t_nodo *aux=cola->frente;
    *info=aux->info;
    cola->frente=aux->sig;
    if(cola->frente==NULL)
        cola->fondo==NULL;
    free(aux);
    return 1;
}

int primeroEnCola(const t_cola *cola, t_info *info)
{
    if(cola->frente==NULL)
        return 0;
    *info=cola->frente->info;
    return 1;
}

void vaciarCola(t_cola *cola)
{
    t_nodo *aux;
    while(cola->frente!=NULL)
        {
        aux=cola->frente;
        cola->frente=aux->sig;
        free(aux);
        }
    cola->fondo=NULL;
}

