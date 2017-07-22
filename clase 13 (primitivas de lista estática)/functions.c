#include "header.h"

void cargar_dato(t_dato *d)
    {
    printf("\n\n Ingrese dato (número): \t");
    scanf("%d",&d->numero);
    }

void mostrar_dato(const t_dato *d)
    {
    printf("\n DATO: \t %d \n",d->numero);
    }

int comparar(const void *v1,const void *v2)
    {
    int *e1=(int*)v1,*e2=(int*)v2;
    return *e1-*e2;
    }
