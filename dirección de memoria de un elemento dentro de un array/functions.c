#include "header.h"
void cargar_array(int *v,int ce)
    {
    int i;
    for(i=1;i<=ce;i++)
        {
        printf("\n Ingrese el elemento número %d del array: \t",i);
        scanf("%d",v);
        v++;
        }
    }
void mostrar_array(int *v,int ce)
    {
    int *fin=v+ce;
    while(v<fin)
        {
        printf("   %d",*v);
        v++;
        }
    }
int *buscar_direccion(int *v,int ce,int x)
    {
    int *fin=v+ce;
    while(v<fin)
        {
        if(*v==x)
            return v;
        v++;
        }
    return NULL;
    }
