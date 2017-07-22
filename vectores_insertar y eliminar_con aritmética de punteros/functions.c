#include "header.h"
int mostrar_vector(int *v,int prim_lib,int tam)
    {
    if(prim_lib==1)
        return 0;
    int *fin=v+prim_lib-1;
    while(v<fin)
        {
        printf("\t %d",*v);
        v++;
        }
    return 1;
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
