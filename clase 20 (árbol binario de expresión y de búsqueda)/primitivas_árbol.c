#include "primitivas_árbol.h"

void crear_arbol(t_arbol *a)
{
    *a=NULL;
}

void vaciar_arbol(t_arbol *a)
{
    if(*a)
    {
        vaciar_arbol(&(*a)->izq);
        vaciar_arbol(&(*a)->der);
    }
    free((t_nodo*)*a);
    *a=NULL;
}

int arbol_vacio(const t_arbol *a)
{
    return *a==NULL;
}

int arbol_lleno(const t_arbol *a)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    return aux==NULL;
}

void recorrer_arbol_inorden_recursiva(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        recorrer_arbol_inorden_recursiva(&(*a)->izq,mostrar);
        mostrar(&(*a)->dato);
        recorrer_arbol_inorden_recursiva(&(*a)->der,mostrar);
    }
}

void recorrer_arbol_preorden_recursiva(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        mostrar(&(*a)->dato);
        recorrer_arbol_preorden_recursiva(&(*a)->izq,mostrar);
        recorrer_arbol_preorden_recursiva(&(*a)->der,mostrar);
    }
}

void recorrer_arbol_posorden_recursiva(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        recorrer_arbol_posorden_recursiva(&(*a)->izq,mostrar);
        recorrer_arbol_posorden_recursiva(&(*a)->der,mostrar);
        mostrar(&(*a)->dato);
    }
}

void recorrer_arbol_inorden_iterativa(const t_arbol *a,t_mst mostrar)
{

}

void recorrer_arbol_preorden_iterativa(const t_arbol *a,t_mst mostrar)
{

}

void recorrer_arbol_posorden_iterativa(const t_arbol *a,t_mst mostrar)
{

}

int insertar_en_arbol_recursiva(t_arbol *a,const t_dato *d,t_cmp comparar)
{
    if(*a)
    {
        if(comparar((void*)&(*a)->dato,(void*)d)>0)
            return insertar_en_arbol_recursiva(&(*a)->izq,d,comparar);
        if(comparar((void*)&(*a)->dato,(void*)d)<0)
            return insertar_en_arbol_recursiva(&(*a)->der,d,comparar);
        return DUPLICADO;
    }
    *a=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*a)
        return MEMORIA_LLENA;
    (*a)->dato=*d;
    (*a)->izq=NULL;
    (*a)->der=NULL;
    return OK;
}

int insertar_en_arbol_iterativa(t_arbol *a,const t_dato *d,t_cmp comparar)
{
    while(*a)
    {
        if(comparar((void*)&(*a)->dato,(void*)d)>0)
            a=&(*a)->izq;
        else
            if(comparar((void*)&(*a)->dato,(void*)d)<0)
                a=&(*a)->der;
            else
                return DUPLICADO;
    }
    *a=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*a)
        return MEMORIA_LLENA;
    (*a)->dato=*d;
    (*a)->izq=NULL;
    (*a)->der=NULL;
    return OK;
}

int buscar_en_arbol_recursiva(const t_arbol *a,t_dato *d,t_cmp comparar)
{
    int cmp;
    if(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
        {
            *d=(*a)->dato;
            return OK;
        }
        if(cmp>0)
            return buscar_en_arbol_recursiva(&(*a)->izq,d,comparar);
        else
            return buscar_en_arbol_recursiva(&(*a)->der,d,comparar);
    }
    return NO_ENCONTRADO;
}

int buscar_en_arbol_iterativa(const t_arbol *a,t_dato *d,t_cmp comparar)
{
    int cmp;
    while(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
        {
            *d=(*a)->dato;
            return OK;
        }
        if(cmp>0)
            a=&(*a)->izq;
        else
            a=&(*a)->der;
    }
    return NO_ENCONTRADO;
}

t_nodo *buscar_en_arbol_y_retornar_direccion_padre_recursiva(const t_arbol *a,t_dato *d,t_cmp comparar)
{
    int cmp;
    t_nodo *padre=*a;
    if(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return NULL;
        if(cmp>0)
            return buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(&(*a)->izq,d,comparar,padre);
        else
            return buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(&(*a)->der,d,comparar,padre);
    }
    return NULL;
}

t_nodo *buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(const t_arbol *a,t_dato *d,t_cmp comparar,t_nodo *padre)
{
    int cmp;
    if(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return padre;
        padre=*a;
        if(cmp>0)
            return buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(&(*a)->izq,d,comparar,padre);
        else
            return buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(&(*a)->der,d,comparar,padre);
    }
    return NULL;
}

t_nodo *buscar_en_arbol_y_retornar_direccion_padre_iterativa(const t_arbol *a,t_dato *d,t_cmp comparar)
{
    int cmp;
    t_nodo *padre=*a;
    while(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return (padre!=*a)?padre:NULL;
        padre=*a;
        if(cmp>0)
            a=&(*a)->izq;
        else
            a=&(*a)->der;
    }
    return NULL;
}

void grabar_arbol_en_inorden_en_archivo_binario(const t_arbol *a,FILE *pf)
{
    if(*a)
    {
        grabar_arbol_en_inorden_en_archivo_binario(&(*a)->izq,pf);
        fwrite(&(*a)->dato,sizeof(t_dato),1,pf);
        grabar_arbol_en_inorden_en_archivo_binario(&(*a)->der,pf);
    }
}

void grabar_arbol_en_preorden_en_archivo_binario(const t_arbol *a,FILE *pf)
{
    if(*a)
    {
        fwrite(&(*a)->dato,sizeof(t_dato),1,pf);
        grabar_arbol_en_preorden_en_archivo_binario(&(*a)->izq,pf);
        grabar_arbol_en_preorden_en_archivo_binario(&(*a)->der,pf);
    }
}

void grabar_arbol_en_posorden_en_archivo_binario(const t_arbol *a,FILE *pf)
{
    if(*a)
    {
        grabar_arbol_en_posorden_en_archivo_binario(&(*a)->izq,pf);
        grabar_arbol_en_posorden_en_archivo_binario(&(*a)->der,pf);
        fwrite(&(*a)->dato,sizeof(t_dato),1,pf);
    }
}

void grabar_arbol_en_inorden_en_archivo_de_texto(const t_arbol *a,FILE *pf)
{
    if(*a)
    {
        grabar_arbol_en_inorden_en_archivo_de_texto(&(*a)->izq,pf);
        fprintf(pf,"%d|",(*a)->dato.numero);
        grabar_arbol_en_inorden_en_archivo_de_texto(&(*a)->der,pf);
    }
}

void grabar_arbol_en_preorden_en_archivo_de_texto(const t_arbol *a,FILE *pf)
{
    if(*a)
    {
        fprintf(pf,"%d|",(*a)->dato.numero);
        grabar_arbol_en_preorden_en_archivo_de_texto(&(*a)->izq,pf);
        grabar_arbol_en_preorden_en_archivo_de_texto(&(*a)->der,pf);
    }
}

void grabar_arbol_en_posorden_en_archivo_de_texto(const t_arbol *a,FILE *pf)
{
    if(*a)
    {
        grabar_arbol_en_posorden_en_archivo_de_texto(&(*a)->izq,pf);
        grabar_arbol_en_posorden_en_archivo_de_texto(&(*a)->der,pf);
        fprintf(pf,"%d|",(*a)->dato.numero);
    }
}

int cargar_arbol_en_preorden_desde_archivo_binario(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    t_nodo *raiz=*a;
    fread(&dato,sizeof(t_nodo),1,pf);
    while(!feof(pf))
    {
        while(*a)
        {
            if(comparar((void*)&(*a)->dato,(void*)&dato)>0)
                a=&(*a)->izq;
            else
                a=&(*a)->der;
        }
        *a=(t_nodo*)malloc(sizeof(t_nodo));
        if(!*a)
            return MEMORIA_LLENA;
        (*a)->dato=dato;
        (*a)->izq=NULL;
        (*a)->der=NULL;
        *a=raiz;
        fread(&dato,sizeof(t_nodo),1,pf);
    }
    return OK;
}

int cargar_arbol_en_posorden_desde_archivo_binario(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    t_nodo *raiz=*a;
    int cant_reg=ftell(pf)/sizeof(t_dato);
    while(cant_reg)
    {
        fseek(pf,(cant_reg-1)*sizeof(t_dato),SEEK_SET);
        cant_reg--;
        fread(&dato,sizeof(t_dato),1,pf);
        while(*a)
        {
            if(comparar((void*)&(*a)->dato,(void*)&dato)>0)
                a=&(*a)->izq;
            else
                a=&(*a)->der;
        }
        *a=(t_nodo*)malloc(sizeof(t_nodo));
        if(!*a)
            return MEMORIA_LLENA;
        (*a)->dato=dato;
        (*a)->izq=NULL;
        (*a)->der=NULL;
        *a=raiz;
    }
    return OK;
}

int cargar_arbol_en_preorden_desde_archivo_de_texto(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    t_nodo *raiz=*a;
    while(fscanf(pf,"%d|",&dato.numero)!=EOF)
    {
        while(*a)
        {
            if(comparar((void*)&(*a)->dato,(void*)&dato)>0)
                a=&(*a)->izq;
            else
                a=&(*a)->der;
        }
        *a=(t_nodo*)malloc(sizeof(t_nodo));
        if(!*a)
            return MEMORIA_LLENA;
        (*a)->dato=dato;
        (*a)->izq=NULL;
        (*a)->der=NULL;
        *a=raiz;
    }
    return OK;
}

int cargar_arbol_en_posorden_desde_archivo_de_texto(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    t_nodo *raiz=*a;
    t_pila pila;
    crear_pila(&pila);
    while(fscanf(pf,"%d|",&dato.numero)!=EOF)
        apilar(&pila,&dato);
    while(!pila_vacia(&pila))
    {
        desapilar(&pila,&dato);
        while(*a)
        {
            if(comparar((void*)&(*a)->dato,(void*)&dato)>0)
                a=&(*a)->izq;
            else
                a=&(*a)->der;
        }
        *a=(t_nodo*)malloc(sizeof(t_nodo));
        if(!*a)
            return MEMORIA_LLENA;
        (*a)->dato=dato;
        (*a)->izq=NULL;
        (*a)->der=NULL;
        *a=raiz;
    }
    return OK;
}
