#include "header.h"

void cargar_dato(t_dato *d)
{
    printf("\n\n Ingrese dato (número): \t");
    scanf("%d",&d->numero);
}

void mostrar_dato(const t_dato *d)
{
    printf("\n\n DATO: \t %d",d->numero);
}

void ingresa_clave(int *clave)
{
    printf("\n\n Ingrese clave: \t");
    scanf("%d",clave);
}

int comparar_enteros(const void *v1,const void *v2)
{
    int *e1=(int*)v1,*e2=(int*)v2;
    return *e1-*e2;
}

int comparar_claves(const void *v1,const void *v2)
{
    t_dato *e1=(t_dato*)v1;
    int *e2=(int*)v2;
    return e1->numero-*e2;
}

