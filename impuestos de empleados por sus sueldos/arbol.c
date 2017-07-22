#include "arbol.h"

void crear_arbol(t_arbol *a)
{
    *a=NULL;
}

int insertar_en_arbol_iterativa(t_arbol *a,const t_dato_arbol *d,t_cmp comparar)
{
    while(*a)
    {
        if(comparar((void*)&(*a)->dato,(void*)d)>0)
            a=&(*a)->izq;
        else
            if(comparar((void*)&(*a)->dato,(void*)d)<0)
                a=&(*a)->der;
            else
                return FALSO;
    }

    *a=(t_nodo_arbol*)malloc(sizeof(t_nodo_arbol));
    if(!*a)
        return MEMORIA_LLENA;

    (*a)->dato=*d;
    (*a)->izq=NULL;
    (*a)->der=NULL;

    return VERDADERO;
}

int buscar_en_arbol_iterativa_y_retornar_dato(t_arbol *a,t_dato_arbol *d,void *clave,t_cmp comparar)
{
    int cmp;

    while(*a)
    {
        if((cmp=comparar((void*)&(*a)->dato,clave))==0)
        {
            *d=(*a)->dato;
            return VERDADERO;
        }

        if(cmp>0)
            a=&(*a)->izq;
        else
            a=&(*a)->der;
    }

    return FALSO;
}

int buscar_en_arbol_iterativa_y_actualizar_dato(t_arbol *a,const t_dato_arbol *d,void *clave,t_cmp comparar)
{
    int cmp;

    while(*a)
    {
        if((cmp=comparar((void*)&(*a)->dato,clave))==0)
        {
            (*a)->dato=*d;
            return VERDADERO;
        }

        if(cmp>0)
            a=&(*a)->izq;
        else
            a=&(*a)->der;
    }

    return FALSO;
}
