#include "header.h"
void cargar_array(int *v,int ce)
    {
    int i;
    for(i=1;i<=ce;i++)
        {
        printf("\n Ingrese el número %d :\t",i);
        scanf("%d",v);
        v++;
        }
    printf("\n\n La carga del array ha finalizado \n");
    }
void mostrar_array(int *v,int ce)
    {
    int i;
    for(i=1;i<=ce;i++)
        {
        printf("\n Elemento número %d: \t %d",i,*v);
        v++;
        }
    }
float suma_y_promedio_main1(int *v,int ce,long int*suma)
    {
    int i;
    *suma=0;
    for(i=0;i<ce;i++)
        {
        *suma+=(long int)(*v);
        v++;
        }
    return (float)(*suma)/ce;
    }
t_calculos suma_y_promedio_main2(int *v,int ce)
    {
    int i;
    t_calculos salida;
    salida.suma=0;
    for(i=0;i<ce;i++)
        {
        salida.suma+=(long int)(*v);
        v++;
        }
    salida.promedio=(float)(salida.suma)/ce;
    return salida;
    }
