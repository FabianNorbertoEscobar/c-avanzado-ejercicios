#include "header.h"

void cargar_dato(t_dato *dato)
{
    printf("\n\n Ingrese dato (número): \t");
    scanf("%d",&dato->numero);
}

void mostrar_dato(t_dato *dato)
{
    printf("\n DATO: \t %d",dato->numero);
}

int comparar_enteros(const void *v1,const void *v2)
{
    int *e1=(int*)v1,*e2=(int*)v2;
    return *e1-*e2;
}
