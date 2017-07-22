#include "header.h"

void cargar_dato(t_dato *d)
{
    printf("\n Ingrese dato (número): \t");
    scanf("%d",&d->numero);
}

void mostrar_dato(const t_dato *d)
{
    printf("\n DATO: \t %d \n",d->numero);
}

int comparar_dato(const void *v1,const void *v2)
{
    int *e1=(int*)v1,*e2=(int*)v2;
    return *e1-*e2;
}

int comparar_clave(const void *v,const void *c)
{
    t_dato *e=(t_dato*)v;
    int *clave=(int*)c;
    return e->numero-*clave;
}

void mostrar_nodo(const void *v)
{
    t_dato *e=(t_dato*)v;
    printf("\n NODO: %d \n",e->numero);
}
