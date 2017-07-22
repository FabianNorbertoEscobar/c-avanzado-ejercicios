#include "arbol.h"

void crear_arbol(t_arbol *a)
{
    *a=NULL;
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

int insertar_en_arbol_iterativa(t_arbol *a,const t_dato *d,t_cmp comparar)
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

    *a=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*a)
        return FALSO;

    (*a)->dato=*d;
    (*a)->izq=NULL;
    (*a)->der=NULL;

    return VERDADERO;
}

int calcular_altura(const t_arbol *a)
{
    if(*a)
    {
        int alt_izq=calcular_altura(&(*a)->izq);
        int alt_der=calcular_altura(&(*a)->der);

        return (alt_izq>=alt_der)?alt_izq+1:alt_der+1;
    }

    return 0;
}

int es_arbol_AVL(const t_arbol *a)
{
    if(*a)
    {
        int alt_izq=calcular_altura(&(*a)->izq);
        int alt_der=calcular_altura(&(*a)->der);

        return (ABS(alt_izq-alt_der)>1)?FALSO:es_arbol_AVL(&(*a)->izq)&&es_arbol_AVL(&(*a)->der);
    }

    return VERDADERO;
}

int es_arbol_balanceado(const t_arbol *a)
{
    int h=calcular_altura(a);
    return es_arbol_balanceado_interna(a,h);
}

int es_arbol_balanceado_interna(const t_arbol *a,int altura)
{
    if(*a)
        return es_arbol_balanceado_interna(&(*a)->izq,altura-1)&&es_arbol_balanceado_interna(&(*a)->der,altura-1);

    return altura<=1;
}

int es_arbol_completo(const t_arbol *a)
{
    return es_arbol_completo_interna(a,calcular_altura(a));
}

int es_arbol_completo_interna(const t_arbol *a,int altura)
{
    if(*a)
        return es_arbol_completo_interna(&(*a)->izq,altura-1)&&es_arbol_completo_interna(&(*a)->der,altura-1);

    return altura==0;
}

void graficar_arbol(const t_arbol *a,t_mst mostrar)
{
    graficar_arbol_interna(a,0,mostrar);
}

void graficar_arbol_interna(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        graficar_arbol_interna(&(*a)->der,nivel+1,mostrar);

        tab(nivel);
        mostrar((void*)&(*a)->dato);
        printf("\n\n");

        graficar_arbol_interna(&(*a)->izq,nivel+1,mostrar);
    }
}

void tab(int nivel)
{
    int i;

    for(i=0;i<nivel;i++)
        printf("\t");
}
