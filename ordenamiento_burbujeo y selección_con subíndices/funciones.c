#include "header.h"
void cargar_vector(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        {
        printf("\n Ingrese v[%d]=\t",i);
        scanf("%d",&v[i]);
        }
    }
void copiar_vector(int origen[],int destino[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        destino[i]=origen[i];
    }
void mostrar_vector(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("   %d",v[i]);
    }
void burbujeo_orden_ascendente(int v[],int ce)
    {
    int i,j,hubo_cambio,aux;
    j=0;
    do
        {
        hubo_cambio=0;
        j++;
        for(i=0;i<ce-j;i++)
            if(v[i]>v[i+1])
                {
                aux=v[i+1];
                v[i+1]=v[i];
                v[i]=aux;
                hubo_cambio=1;
                }
        }
    while(hubo_cambio==1);
    }
void burbujeo_orden_descendente(int v[],int ce)
    {
    int i,j,hubo_cambio,aux;
    j=0;
    do
        {
        hubo_cambio=0;
        j++;
        for(i=0;i<ce-j;i++)
            if(v[i]<v[i+1])
                {
                aux=v[i+1];
                v[i+1]=v[i];
                v[i]=aux;
                hubo_cambio=1;
                }
        }
    while(hubo_cambio==1);
    }
void seleccion_orden_ascendente(int v[],int ce)
    {
    int j,i,pos_menor,aux;
    for(j=1;j<ce;j++)
        {
        pos_menor=j-1;
        for(i=j;i<ce;i++)
            {
            if(v[i]<v[pos_menor])
            pos_menor=i;
            }
        aux=v[pos_menor];
        v[pos_menor]=v[j-1];
        v[j-1]=aux;
        }
    }
void seleccion_orden_descendente(int v[],int ce)
    {
    int j,i,pos_mayor,aux;
    for(j=1;j<ce;j++)
        {
        pos_mayor=j-1;
        for(i=j;i<ce;i++)
            {
            if(v[i]>v[pos_mayor])
            pos_mayor=i;
            }
        aux=v[pos_mayor];
        v[pos_mayor]=v[j-1];
        v[j-1]=aux;
        }
    }
