#include "header.h"
void cargar_vector(int *v,int ce)
    {
    int *fin=v+ce;
    while(v<fin)
        {
        printf("\n Ingrese elemento: \t");
        scanf("%d",v);
        v++;
        }
    }
void copiar_vector(int *origen,int *destino,int ce)
    {
    int *fin=origen+ce;
    while(origen<fin)
        {
        *destino=*origen;
        origen++;
        destino++;
        }
    }
void mostrar_vector(int *v,int ce)
    {
    int *fin=v+ce;
    while(v<fin)
        {
        printf("   %d",*v);
        v++;
        }
    }
void burbujeo_orden_ascendente(int *v,int ce)
    {
    if(ce==1||ce==0)
        return;
    int aux,hubo_cambio=0,*inicio=v,*fin=v+ce,*sig=v+1;
    do
        {
        while(sig<fin)
            {
            if(*v>*sig)
                {
                aux=*v;
                *v=*sig;
                *sig=aux;
                hubo_cambio=1;
                }
            v++;
            sig++;
            }
        v=inicio;
        sig=v+1;
        fin--;
        }
    while(hubo_cambio==1&&sig<fin);
    }
void burbujeo_orden_descendente(int *v,int ce)
    {
    if(ce==1||ce==0)
        return;
    int aux,hubo_cambio=0,*inicio=v,*fin=v+ce,*sig=v+1;
    do
        {
        while(sig<fin)
            {
            if(*v<*sig)
                {
                aux=*v;
                *v=*sig;
                *sig=aux;
                hubo_cambio=1;
                }
            v++;
            sig++;
            }
        v=inicio;
        sig=v+1;
        fin--;
        }
    while(hubo_cambio==1&&sig<fin);
    }
void seleccion_orden_ascendente(int *v,int ce)
    {
    if(ce==1||ce==0)
        return;
    int aux,band=0,*fin=v+ce,*menor,*comp=v;
    while(v<fin)
        {
        band=0;
        menor=v;
        comp=v+1;
        while(comp<fin)
            {
            if(*menor>*comp)
                {
                menor=comp;
                band=1;
                }
            comp++;
            }
        if(band==1)
            {
            aux=*v;
            *v=*menor;
            *menor=aux;
            }
        v++;
        }
    }
void seleccion_orden_descendente(int *v,int ce)
    {
    if(ce==1||ce==0)
        return;
    int aux,band=0,*fin=v+ce,*mayor,*comp=v;
    while(v<fin)
        {
        band=0;
        mayor=v;
        comp=v+1;
        while(comp<fin)
            {
            if(*mayor<*comp)
                {
                mayor=comp;
                band=1;
                }
            comp++;
            }
        if(band==1)
            {
            aux=*v;
            *v=*mayor;
            *mayor=aux;
            }
        v++;
        }
    }
