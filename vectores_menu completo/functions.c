#include "header.h"
int cargar_vector(int *v,int tam,int *prim_libre)
    {
    int band,cant,*ult;
    printf("\n Ingrese la cantidad de elementos que desea cargar (máximo %d): \t",tam-(*prim_libre-1));
    band=0;
    do
        {
        if(band==1)
            printf("\n La cantidad ingresada no es correcta. Reingrésela: \t");
        scanf("%d",&cant);
        band=1;
        }
    while(!DATO_VALIDO(cant,0,tam-(*prim_libre-1)));
    if(cant==0)
        return 0;
    ult=v+*prim_libre-1+cant;
    for(v=v+*prim_libre-1;v<ult;v++)
        {
        printf("\n Ingrese elemento:\t ");
        scanf("%d",v);
        }
    *prim_libre+=cant;
    return 1;
    }
void vaciar_vector(int *v,int tam,int *prim_libre)
    {
    *prim_libre=1;
    }
int mostrar_vector(int *v,int tam,int prim_libre)
    {
    if(prim_libre==1)
        return 0;
    int *fin=v+prim_libre-1;
    printf("\n\n Elementos del vector \n\n\a\a");
    while(v<fin)
        {
        printf("\t %d",*v);
        v++;
        }
    return 1;
    }
void mostrar_informe_del_vector(int *v,int tam,int prim_libre)
    {
    printf("\n Tamaño del vector:\t %d",tam);
    printf("\n Cantidad de posiciones ocupadas:\t %d",prim_libre-1);
    printf("\n Cantidad de posiciones libres:\t %d",tam-(prim_libre-1));
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
int insertar_en_posicion(int *v,int *prim_lib,int tam,int nuevo,int pos)
    {
    if(*prim_lib>tam||pos>*prim_lib)
        return 0;
    int aux;
    int *fin=v+*prim_lib-1;
    v+=pos-1;
    do
        {
        aux=*v;
        *v=nuevo;
        nuevo=aux;
        v++;
        }
    while(v<=fin);
    *prim_lib+=1;
    return 1;
    }
int insertar_en_posicion_hacia_izquierda(int *v,int *prim_lib,int tam,int nuevo,int pos)
    {
    if(*prim_lib>tam||pos>=*prim_lib)
        return 0;
    if(pos==1)
        {
        *v=nuevo;
        return 1;
        }
    int *fin=v+pos-1;
    int *sig=v+1;
    do
        {
        *v=*sig;
        v++;
        sig++;
        }
    while(sig<=fin);
    *v=nuevo;
    return 1;
    }
int insertar_en_orden(int *v,int *prim_lib,int tam,int nuevo)
    {
    if(*prim_lib>tam)
        return 0;
    int aux;
    int *fin=v+*prim_lib-1;
    while(*v<nuevo&&v<fin)
        v++;
    do
        {
        aux=*v;
        *v=nuevo;
        nuevo=aux;
        v++;
        }
    while(v<=fin);
    *prim_lib+=1;
    return 1;
    }
int insertar_en_orden_hacia_izquierda(int *v,int *prim_lib,int tam,int nuevo)
    {
    if(*prim_lib>tam)
        return 0;
    int *inicio=v;
    v+=*prim_lib-2;
    while(*v>nuevo&&v>inicio)
        v--;
    if(v==inicio&&*v>=nuevo)
        return 0;
    int aux;
    do
        {
        aux=*v;
        *v=nuevo;
        nuevo=aux;
        v--;
        }
    while(v>=inicio);
    return 1;
    }
int eliminar_de_posicion(int *v,int *prim_lib,int tam,int pos)
    {
    if(*prim_lib==1||*prim_lib==pos)
        return 0;
    int *fin=v+*prim_lib-1;
    v+=pos-1;
    int *sig=v+1;
    do
        {
        *v=*sig;
        v++;
        sig++;
        }
    while(sig<fin);
    *prim_lib-=1;
    return 1;
    }
int eliminar_primera_aparicion(int *v,int *prim_lib,int tam,int num)
    {
    if(*prim_lib==1)
        return 0;
    int *fin=v+*prim_lib-1;
    while(*v!=num&&v<fin)
        v++;
    if(v==fin)
        return 0;
    int *sig=v+1;
    do
        {
        *v=*sig;
        v++;
        sig++;
        }
    while(sig<fin);
    *prim_lib-=1;
    return 1;
    }
int eliminar_todas_las_apariciones(int *v,int *prim_lib,int tam,int num)
    {
    if(*prim_lib==1)
        return 0;
    int *fin=v+*prim_lib-1;
    while(*v!=num&&v<fin)
        v++;
    if(v==fin)
        return 0;
    int *sig=v+1;
    do
        {
        while(*sig==num)
            {
            sig++;
            *prim_lib-=1;
            fin--;
            }
        *v=*sig;
        v++;
        sig++;
        }
    while(sig<fin);
    *prim_lib-=1;
    return 1;
    }

