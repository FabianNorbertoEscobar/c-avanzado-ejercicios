#include "header.h"
void cargar_vector(int *pv,int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        {
        printf("\n Ingrese v%d=\t",i);
        scanf("%d",pv);
        pv++;
        }
    }
void copiar_vector(int *origen,int *destino,int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        {
        *destino=*origen;
        origen++;
        destino++;
        }
    }
void mostrar_vector(int *pv,int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        {
        printf("   %d",*pv);
        pv++;
        }
    }
void burbujeo_orden_ascendente(int *pv,int ce)
    {
    int i,j,*comp,hubo_cambio,aux;
    j=0;
    do
        {
        comp=pv;
        hubo_cambio=0;
        for(i=0;i<ce-j;i++)
            {
            if(*comp<*pv)
                {
                aux=*pv;
                *pv=*comp;
                *comp=aux;
                hubo_cambio=1;
                }
            comp++;
            }
        j++;
        pv++;
        }
    while(hubo_cambio==1);
    }

void burbujeo_orden_descendente(int *pv,int ce)
    {
    int i,j,*comp,hubo_cambio,aux;
    j=0;
    do
        {
        comp=pv;
        hubo_cambio=0;
        for(i=0;i<ce-j;i++)
            {
            if(*comp>*pv)
                {
                aux=*pv;
                *pv=*comp;
                *comp=aux;
                hubo_cambio=1;
                }
            comp++;
            }
        j++;
        pv++;
        }
    while(hubo_cambio==1);
    }
void seleccion_orden_ascendente(int *pv,int ce)
    {
    int j,i,*comp,*min,aux;
    for(j=0;j<ce-1;j++)
        {
        min=pv;
        comp=pv;
        for(i=j;i<ce;i++)
            {
            if(*comp<*min)
                min=comp;
            comp++;
            }
        if(min!=pv)
            {
            aux=*pv;
            *pv=*min;
            *min=aux;
            }
        pv++;
        }
    }
void seleccion_orden_descendente(int *pv,int ce)
    {
    int j,i,*comp,*max,aux;
    for(j=0;j<ce-1;j++)
        {
        max=pv;
        comp=pv;
        for(i=j;i<ce;i++)
            {
            if(*comp>*max)
                max=comp;
            comp++;
            }
        if(max!=pv)
            {
            aux=*pv;
            *pv=*max;
            *max=aux;
            }
        pv++;
        }
    }
