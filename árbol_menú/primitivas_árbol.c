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
        free(*a);
        *a=NULL;
    }
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

int buscar_en_arbol_recursiva(t_arbol *a,t_dato *d,t_cmp comparar)
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

int buscar_en_arbol_iterativa(t_arbol *a,t_dato *d,t_cmp comparar)
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

t_nodo **buscar_en_arbol_y_retornar_direccion_padre_recursiva(t_arbol *a,t_dato *d,t_cmp comparar)
{
    int cmp;
    t_nodo **padre=a;
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

t_nodo **buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(t_arbol *a,t_dato *d,t_cmp comparar,t_nodo **padre)
{
    int cmp;
    if(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return padre;
        *padre=*a;
        if(cmp>0)
            return buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(&(*a)->izq,d,comparar,padre);
        else
            return buscar_en_arbol_y_retornar_direccion_padre_recursiva_interna(&(*a)->der,d,comparar,padre);
    }
    return NULL;
}

t_nodo **buscar_en_arbol_y_retornar_direccion_padre_iterativa(t_arbol *a,t_dato *d,t_cmp comparar)
{
    int cmp;
    t_nodo **padre=a;
    while(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return (padre!=a)?padre:NULL;
        padre=a;
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
    fread(&dato,sizeof(t_dato),1,pf);
    while(!feof(pf))
    {
        if(!insertar_en_arbol_iterativa(a,&dato,comparar))
        {
            vaciar_arbol(a);
            return 0;
        }
        fread(&dato,sizeof(t_dato),1,pf);
    }
    return OK;
}

int cargar_arbol_en_posorden_desde_archivo_binario(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    t_pila pila;
    crear_pila(&pila);
    fread(&dato,sizeof(t_dato),1,pf);
    while(!feof(pf))
    {
        if(!apilar(&pila,&dato))
            return 0;
        fread(&dato,sizeof(t_dato),1,pf);
    }
    while(!pila_vacia(&pila))
    {
        desapilar(&pila,&dato);
        if(!insertar_en_arbol_iterativa(a,&dato,comparar))
        {
            vaciar_arbol(a);
            return 0;
        }
    }
    return OK;
}

int cargar_arbol_en_preorden_desde_archivo_de_texto(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    while(fscanf(pf,"%d|",&dato.numero)!=EOF)
        if(!insertar_en_arbol_iterativa(a,&dato,comparar))
        {
            vaciar_arbol(a);
            return 0;
        }
    return OK;
}

int cargar_arbol_en_posorden_desde_archivo_de_texto(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    t_pila pila;
    crear_pila(&pila);
    while(fscanf(pf,"%d|",&dato.numero)!=EOF)
        if(!apilar(&pila,&dato))
            return 0;
    while(!pila_vacia(&pila))
    {
        desapilar(&pila,&dato);
        if(!insertar_en_arbol_iterativa(a,&dato,comparar))
        {
            vaciar_arbol(a);
            return 0;
        }
    }
    return OK;
}

int contar_nodos(const t_arbol *a)
{
    if(*a)
        return contar_nodos(&(*a)->izq)+contar_nodos(&(*a)->der)+1;
    return 0;
}

int contar_hojas(const t_arbol *a)
{
    if(*a)
    {
        if(!(*a)->izq&&!(*a)->der)
            return 1;
        return contar_hojas(&(*a)->izq)+contar_hojas(&(*a)->der);
    }
    return 0;
}

int contar_no_hojas(const t_arbol *a)
{
    if(*a)
        if((*a)->izq||(*a)->der)
            return contar_no_hojas(&(*a)->izq)+contar_no_hojas(&(*a)->der)+1;
    return 0;
}

int contar_nodos_con_hijos_solo_por_izquierda(const t_arbol *a)
{
    if(*a)
    {
        if((*a)->izq&&!(*a)->der)
            return contar_nodos_con_hijos_solo_por_izquierda(&(*a)->izq)+1;
        return contar_nodos_con_hijos_solo_por_izquierda(&(*a)->izq)+contar_nodos_con_hijos_solo_por_izquierda(&(*a)->der);
    }
    return 0;
}

int contar_nodos_con_hijos_solo_por_derecha(const t_arbol *a)
{
    if(*a)
    {
        if(!(*a)->izq&&(*a)->der)
            return contar_nodos_con_hijos_solo_por_derecha(&(*a)->der)+1;
        return contar_nodos_con_hijos_solo_por_derecha(&(*a)->izq)+contar_nodos_con_hijos_solo_por_derecha(&(*a)->der);
    }
    return 0;
}

int contar_nodos_con_hijos_por_izquierda_o_por_derecha(const t_arbol *a)
{
    if(*a)
    {
        if((*a)->izq||(*a)->der)
            return contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->izq)+contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->der)+1;
        return contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->izq)+contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->der);
    }
    return 0;
}

int contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(const t_arbol *a)
{
    if(*a)
    {
        if(((*a)->izq||(*a)->der)&&(!((*a)->izq&&(*a)->der)))
            return contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->izq)+contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->der)+1;
        return contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->izq)+contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->der);
    }
    return 0;
}

int contar_nodos_con_hijos_por_izquierda_y_por_derecha(const t_arbol *a)
{
    if(*a)
    {
        if((*a)->izq&&(*a)->der)
            return contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->izq)+contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->der)+1;
        return contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->izq)+contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->der);
    }
    return 0;
}

int contar_nodos_de_un_nivel(const t_arbol *a,int nivel)
{
    if(*a)
    {
        if(nivel)
            return contar_nodos_de_un_nivel(&(*a)->izq,nivel-1)+contar_nodos_de_un_nivel(&(*a)->der,nivel-1);
        return 1;
    }
    return 0;
}

int contar_nodos_hasta_un_nivel(const t_arbol *a,int nivel)
{
    if(*a)
        if(nivel)
            return contar_nodos_hasta_un_nivel(&(*a)->izq,nivel-1)+contar_nodos_hasta_un_nivel(&(*a)->der,nivel-1)+1;
    return 0;
}

int contar_nodos_hasta_un_nivel_inclusive(const t_arbol *a,int nivel)
{
    if(*a)
    {
        if(nivel)
            return contar_nodos_hasta_un_nivel_inclusive(&(*a)->izq,nivel-1)+contar_nodos_hasta_un_nivel_inclusive(&(*a)->der,nivel-1)+1;
        return 1;
    }
    return 0;
}

int contar_nodos_desde_un_nivel(const t_arbol *a,int nivel)
{
    if(*a)
    {
        if(nivel>=0)
            return contar_nodos_desde_un_nivel(&(*a)->izq,nivel-1)+contar_nodos_desde_un_nivel(&(*a)->der,nivel-1);
        return contar_nodos_desde_un_nivel(&(*a)->izq,nivel-1)+contar_nodos_desde_un_nivel(&(*a)->der,nivel-1)+1;
    }
    return 0;
}

int contar_nodos_desde_un_nivel_inclusive(const t_arbol *a,int nivel)
{
    if(*a)
    {
        if(nivel>=1)
            return contar_nodos_desde_un_nivel_inclusive(&(*a)->izq,nivel-1)+contar_nodos_desde_un_nivel_inclusive(&(*a)->der,nivel-1);
        return contar_nodos_desde_un_nivel_inclusive(&(*a)->izq,nivel-1)+contar_nodos_desde_un_nivel_inclusive(&(*a)->der,nivel-1)+1;
    }
    return 0;
}

void mostrar_nodos(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        mostrar(&(*a)->dato);
        mostrar_nodos(&(*a)->izq,mostrar);
        mostrar_nodos(&(*a)->der,mostrar);
    }
}

void mostrar_hojas(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if(!(*a)->izq&&!(*a)->der)
            mostrar(&(*a)->dato);
        mostrar_hojas(&(*a)->izq,mostrar);
        mostrar_hojas(&(*a)->der,mostrar);
    }
}

void mostrar_no_hojas(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq||(*a)->der)
            mostrar(&(*a)->dato);
        mostrar_no_hojas(&(*a)->izq,mostrar);
        mostrar_no_hojas(&(*a)->der,mostrar);
    }
}

void mostrar_nodos_con_hijos_solo_por_izquierda(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq&&!(*a)->der)
            mostrar(&(*a)->dato);
        mostrar_nodos_con_hijos_solo_por_izquierda(&(*a)->izq,mostrar);
        mostrar_nodos_con_hijos_solo_por_izquierda(&(*a)->der,mostrar);
    }
}

void mostrar_nodos_con_hijos_solo_por_derecha(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if(!(*a)->izq&&(*a)->der)
            mostrar(&(*a)->dato);
        mostrar_nodos_con_hijos_solo_por_derecha(&(*a)->izq,mostrar);
        mostrar_nodos_con_hijos_solo_por_derecha(&(*a)->der,mostrar);
    }
}

void mostrar_nodos_con_hijos_por_izquierda_o_por_derecha(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq||(*a)->der)
            mostrar(&(*a)->dato);
        mostrar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->izq,mostrar);
        mostrar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->der,mostrar);
    }
}

void mostrar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if(((*a)->izq||(*a)->der)&&(!((*a)->izq&&(*a)->der)))
            mostrar(&(*a)->dato);
        mostrar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->izq,mostrar);
        mostrar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->der,mostrar);
    }
}

void mostrar_nodos_con_hijos_por_izquierda_y_por_derecha(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq&&(*a)->der)
            mostrar(&(*a)->dato);
        mostrar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->izq,mostrar);
        mostrar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->der,mostrar);
    }
}

void mostrar_nodos_de_un_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel)
        {
            mostrar_nodos_de_un_nivel(&(*a)->izq,nivel-1,mostrar);
            mostrar_nodos_de_un_nivel(&(*a)->der,nivel-1,mostrar);
        }
        else
            mostrar(&(*a)->dato);
    }
}

void mostrar_nodos_hasta_un_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel)
        {
            mostrar(&(*a)->dato);
            mostrar_nodos_hasta_un_nivel(&(*a)->izq,nivel-1,mostrar);
            mostrar_nodos_hasta_un_nivel(&(*a)->der,nivel-1,mostrar);
        }
    }
}

void mostrar_nodos_hasta_un_nivel_inclusive(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        mostrar(&(*a)->dato);
        if(nivel)
        {
            mostrar_nodos_hasta_un_nivel_inclusive(&(*a)->izq,nivel-1,mostrar);
            mostrar_nodos_hasta_un_nivel_inclusive(&(*a)->der,nivel-1,mostrar);
        }
    }
}

void mostrar_nodos_desde_un_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel<0)
            mostrar(&(*a)->dato);
        mostrar_nodos_desde_un_nivel(&(*a)->izq,nivel-1,mostrar);
        mostrar_nodos_desde_un_nivel(&(*a)->der,nivel-1,mostrar);
    }
}

void mostrar_nodos_desde_un_nivel_inclusive(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel<=0)
            mostrar(&(*a)->dato);
        mostrar_nodos_desde_un_nivel_inclusive(&(*a)->izq,nivel-1,mostrar);
        mostrar_nodos_desde_un_nivel_inclusive(&(*a)->der,nivel-1,mostrar);
    }
}

int mostrar_y_contar_nodos(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        mostrar(&(*a)->dato);
        return mostrar_y_contar_nodos(&(*a)->izq,mostrar)+mostrar_y_contar_nodos(&(*a)->der,mostrar)+1;
    }
    return 0;
}

int mostrar_y_contar_hojas(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if(!(*a)->izq&&!(*a)->der)
        {
            mostrar(&(*a)->dato);
            return 1;
        }
        return mostrar_y_contar_hojas(&(*a)->izq,mostrar)+mostrar_y_contar_hojas(&(*a)->der,mostrar);
    }
    return 0;
}

int mostrar_y_contar_no_hojas(const t_arbol *a,t_mst mostrar)
{
    if(*a)
        if((*a)->izq||(*a)->der)
        {
            mostrar(&(*a)->dato);
            return mostrar_y_contar_no_hojas(&(*a)->izq,mostrar)+mostrar_y_contar_no_hojas(&(*a)->der,mostrar)+1;
        }
    return 0;
}

int mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq&&!(*a)->der)
        {
            mostrar(&(*a)->dato);
            return mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(&(*a)->izq,mostrar)+1;
        }
        return mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(&(*a)->der,mostrar);
    }
    return 0;
}

int mostrar_y_contar_nodos_con_hijos_solo_por_derecha(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if(!(*a)->izq&&(*a)->der)
        {
            mostrar(&(*a)->dato);
            return mostrar_y_contar_nodos_con_hijos_solo_por_derecha(&(*a)->izq,mostrar)+1;
        }
        return mostrar_y_contar_nodos_con_hijos_solo_por_derecha(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_solo_por_derecha(&(*a)->der,mostrar);
    }
    return 0;
}

int mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq||(*a)->der)
        {
            mostrar(&(*a)->dato);
            return mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->der,mostrar)+1;
        }
        return mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(&(*a)->der,mostrar);
    }
    return 0;
}

int mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if(((*a)->izq||(*a)->der)&&(!((*a)->izq&&(*a)->der)))
        {
            mostrar(&(*a)->dato);
            return mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->der,mostrar)+1;
        }
        return mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&(*a)->der,mostrar);
    }
    return 0;
}


int mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq&&(*a)->der)
        {
            mostrar(&(*a)->dato);
            return mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->der,mostrar)+1;
        }
        return mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->izq,mostrar)+mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(&(*a)->der,mostrar);
    }
    return 0;
}

int mostrar_y_contar_nodos_de_un_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel)
            return mostrar_y_contar_nodos_de_un_nivel(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_nodos_de_un_nivel(&(*a)->der,nivel-1,mostrar);
        mostrar(&(*a)->dato);
        return 1;
    }
    return 0;
}

int mostrar_y_contar_nodos_hasta_un_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
        if(nivel)
        {
            mostrar(&(*a)->dato);
            return mostrar_y_contar_nodos_hasta_un_nivel(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_nodos_hasta_un_nivel(&(*a)->der,nivel-1,mostrar)+1;
        }
    return 0;
}

int mostrar_y_contar_nodos_hasta_un_nivel_inclusive(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        mostrar(&(*a)->dato);
        if(nivel)
            return mostrar_y_contar_nodos_hasta_un_nivel_inclusive(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_nodos_hasta_un_nivel_inclusive(&(*a)->der,nivel-1,mostrar)+1;
        return 1;
    }
    return 0;
}

int mostrar_y_contar_nodos_desde_un_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel>=0)
            return mostrar_y_contar_nodos_desde_un_nivel(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_nodos_desde_un_nivel(&(*a)->der,nivel-1,mostrar);
        mostrar(&(*a)->dato);
        return mostrar_y_contar_nodos_desde_un_nivel(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_nodos_desde_un_nivel(&(*a)->der,nivel-1,mostrar)+1;
    }
    return 0;
}

int mostrar_y_contar_nodos_desde_un_nivel_inclusive(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel>=1)
            return mostrar_y_contar_nodos_desde_un_nivel_inclusive(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_nodos_desde_un_nivel_inclusive(&(*a)->der,nivel-1,mostrar);
        mostrar(&(*a)->dato);
        return mostrar_y_contar_nodos_desde_un_nivel_inclusive(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_nodos_desde_un_nivel_inclusive(&(*a)->der,nivel-1,mostrar)+1;
    }
    return 0;
}

void talar_arbol(t_arbol *a)
{
    *a=NULL;
}

void podar_hojas(t_arbol *a)
{
    if(*a)
    {
        if(!(*a)->izq&&!(*a)->der)
        {
            free(*a);
            *a=NULL;
        }
        else
        {
            podar_hojas(&(*a)->izq);
            podar_hojas(&(*a)->der);
        }
    }
}

void podar_hasta_nivel(t_arbol *a,int nivel)
{
    if(*a)
    {
        podar_hasta_nivel(&(*a)->izq,nivel-1);
        podar_hasta_nivel(&(*a)->der,nivel-1);
        if(nivel<0)
        {
            free(*a);
            *a=NULL;
        }
    }
}

void podar_hasta_nivel_inclusive(t_arbol *a,int nivel)
{
    if(*a)
    {
        podar_hasta_nivel_inclusive(&(*a)->izq,nivel-1);
        podar_hasta_nivel_inclusive(&(*a)->der,nivel-1);
        if(!nivel)
        {
            free(*a);
            *a=NULL;
        }
    }
}

void podar_hasta_altura(t_arbol *a,int altura)
{
    if(*a)
    {
        podar_hasta_altura(&(*a)->izq,altura-1);
        podar_hasta_altura(&(*a)->der,altura-1);
        if(!altura)
        {
            free(*a);
            *a=NULL;
        }
    }
}

void podar_hasta_altura_inclusive(t_arbol *a,int altura)
{
    if(*a)
    {
        podar_hasta_altura_inclusive(&(*a)->izq,altura-1);
        podar_hasta_altura_inclusive(&(*a)->der,altura-1);
        if(altura<=1)
        {
            free(*a);
            *a=NULL;
        }
    }
}

int calcular_nivel(const t_arbol *a)
{
    if(*a)
    {
        int niv_izq=calcular_nivel(&(*a)->izq);
        int niv_der=calcular_nivel(&(*a)->der);
        return (niv_izq>=niv_der)?niv_izq+1:niv_der+1;
    }
    return -1;
}

int calcular_altura(const t_arbol *a)
{
    if(*a)
    {
        int alt_izq=calcular_altura(&(*a)->izq);
        int alt_der=calcular_altura(&(*a)->der);
        return (alt_izq>=alt_der)?alt_izq+1:alt_der+1;
    }
    return 0;
}

int arbol_semibalanceado(const t_arbol *a)
{
    if(*a)
    {
        int alt_izq=calcular_altura(&(*a)->izq);
        int alt_der=calcular_altura(&(*a)->der);
        return (ABS(alt_izq-alt_der)>1)?0:arbol_semibalanceado(&(*a)->izq)&&arbol_semibalanceado(&(*a)->der);
    }
    return 1;
}

int arbol_balanceado(const t_arbol *a)
{
    int h=calcular_altura(a);
    return arbol_balanceado_interna(a,h);
}

int arbol_balanceado_interna(const t_arbol *a,int altura)
{
    if(*a)
        return arbol_balanceado_interna(&(*a)->izq,altura-1)&&arbol_balanceado_interna(&(*a)->der,altura-1);
    return altura<=1;
}

int arbol_completo(const t_arbol *a)
{
    int h=calcular_altura(a);
    return arbol_completo_interno(a,h);
}

int arbol_completo_interno(const t_arbol *a,int altura)
{
    if(*a)
        return arbol_completo_interno(&(*a)->izq,altura-1)&&arbol_completo_interno(&(*a)->der,altura-1);
    return altura==0;
}

int cargar_arbol_en_inorden_desde_archivo_binario_lo_mas_balanceado_posible(t_arbol *a,FILE *pf,t_cmp comparar)
{
    fseek(pf,0L,SEEK_END);
    return cargar_arbol_en_inorden_desde_archivo_binario_lo_mas_balanceado_posible_interna(a,pf,1,ftell(pf)/sizeof(t_dato),comparar);
}

int cargar_arbol_en_inorden_desde_archivo_binario_lo_mas_balanceado_posible_interna(t_arbol *a,FILE *pf,int pri,int ult,t_cmp comparar)
{
    t_dato dato;
    if(pri<=ult)
    {
        int medio=(pri+ult)/2;
        fseek(pf,(medio-1)*sizeof(t_dato),SEEK_SET);
        fread(&dato,sizeof(t_dato),1,pf);
        if(!feof(pf))
        {
            if(!insertar_en_arbol_iterativa(a,&dato,comparar))
            {
                vaciar_arbol(a);
                return 0;
            }
            cargar_arbol_en_inorden_desde_archivo_binario_lo_mas_balanceado_posible_interna(a,pf,pri,medio-1,comparar);
            cargar_arbol_en_inorden_desde_archivo_binario_lo_mas_balanceado_posible_interna(a,pf,medio+1,ult,comparar);
        }
    }
    return OK;
}

int hoja(const t_arbol *a)
{
    return *a&&!(*a)->izq&&!(*a)->der;
}

t_nodo **buscar_nodo_menor(t_arbol *a)
{
    if(!*a)
        return NULL;
    while((*a)->izq)
        a=&(*a)->izq;
    return a;
}

t_nodo **buscar_nodo_mayor(t_arbol *a)
{
    if(!*a)
        return NULL;
    while((*a)->der)
        a=&(*a)->der;
    return a;
}

int eliminar_nodo_y_acomodar_ramas_iterativa(t_arbol *a,t_dato *d,t_cmp comparar)
{
    t_arbol *sub_arbol;
    a=buscar_en_arbol_y_retornar_direccion_padre_iterativa(a,d,comparar);
    if(!a)
        return NO_ENCONTRADO;
    while((*a)->izq||(*a)->der)
    {
        int alt_izq=calcular_altura(&(*a)->izq);
        int alt_der=calcular_altura(&(*a)->der);
        sub_arbol=(alt_izq<=alt_der)?buscar_nodo_menor(&(*a)->izq):buscar_nodo_mayor(&(*a)->der);
        (*a)->dato=(*sub_arbol)->dato;
        a=sub_arbol;
    }
    free(*a);
    *a=NULL;
    return OK;
}

int eliminar_nodo_y_acomodar_ramas_recursiva(t_arbol *a,t_dato *d,t_cmp comparar)
{
    a=buscar_en_arbol_y_retornar_direccion_padre_iterativa(a,d,comparar);
    if(!a)
        return NO_ENCONTRADO;
    return eliminar_nodo_y_acomodar_ramas_recursiva_interna(a,d);
}

int eliminar_nodo_y_acomodar_ramas_recursiva_interna(t_arbol *a,t_dato *d)
{
    if((*a)->izq||(*a)->der)
    {
        int alt_izq=calcular_altura(&(*a)->izq);
        int alt_der=calcular_altura(&(*a)->der);
        t_arbol *sub_arbol=(alt_izq<=alt_der)?buscar_nodo_menor(&(*a)->izq):buscar_nodo_mayor(&(*a)->der);
        (*a)->dato=(*sub_arbol)->dato;
        a=sub_arbol;
        return eliminar_nodo_y_acomodar_ramas_recursiva_interna(a,d);
    }
    free(*a);
    *a=NULL;
    return OK;
}

void arbol_grafico(const t_arbol *a,t_mst mostrar)
{
    arbol_grafico_interna(a,mostrar,0);
}

void arbol_grafico_interna(const t_arbol *a,t_mst mostrar,int nivel)
{
    if(*a)
    {
        if((*a)->der)
            arbol_grafico_interna(&(*a)->der,mostrar,nivel+1);

        tab(nivel);
        mostrar((void*)&(*a)->dato);
        printf("\n\n");

        if((*a)->izq)
            arbol_grafico_interna(&(*a)->izq,mostrar,nivel+1);
    }
}

void tab(int x)
{
    int i;
    for(i=0;i<x;i++)
        printf("\t");
}
