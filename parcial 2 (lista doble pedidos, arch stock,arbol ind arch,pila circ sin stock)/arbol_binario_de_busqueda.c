#include "arbol_binario_de_busqueda.h"

void crear_arbol(t_arbol *a)
{
    *a=NULL;
}

int arbol_vacio(const t_arbol *a)
{
    return *a==NULL;
}

int arbol_lleno(const t_arbol *a)
{
    void *aux=malloc(sizeof(t_nodo_arbol));
    free(aux);
    return aux==NULL;
}

int insertar_en_arbol(t_arbol *a,const t_dato_arbol *d,t_cmp comparar)
{
    int cmp;

    while(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
           return DUPLICADO;
        if(cmp>0)
            a=&(*a)->izq;
        else
            a=&(*a)->der;
    }

    *a=(t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
    if(!*a)
        return MEMORIA_LLENA;
    (*a)->dato=*d;
    (*a)->izq=NULL;
    (*a)->der=NULL;
    return OK;
}

int buscar_en_arbol_y_retornar_dato(const t_arbol *a,t_dato_arbol *d,void *clave,t_cmp comparar)
{
    int cmp;
    while(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,clave)))
        {
            *d=(*a)->dato;
            return OK;
        }
        if(cmp>0)
            a=&(*a)->izq;
        else
            a=&(*a)->der;
    }
    return NO_ENCONTRADO;
}

void vaciar_arbol(t_arbol *a)
{
    if(*a)
    {
        vaciar_arbol(&(*a)->izq);
        vaciar_arbol(&(*a)->der);
        free(*a);
        *a=NULL;
    }
}
