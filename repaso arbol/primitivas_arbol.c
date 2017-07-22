#include "primitivas_arbol.h"

void crear_arbol(t_arbol *a)
{
    *a=NULL;
}

void talar_arbol(t_arbol *a)
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

int ver_raiz(const t_arbol *a,t_dato *d)
{
    if(!*a)
        return ARBOL_VACIO;
    *d=(*a)->dato;
    return OK;
}

int es_hoja(const t_arbol *a)
{
    return *a&&!(*a)->izq&&!(*a)->der;
}

void recorrer_arbol_en_inorden(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        recorrer_arbol_en_inorden(&(*a)->izq,mostrar);
        mostrar((void*)&(*a)->dato);
        recorrer_arbol_en_inorden(&(*a)->der,mostrar);
    }
}

void recorrer_arbol_en_preorden(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        mostrar((void*)&(*a)->dato);
        recorrer_arbol_en_preorden(&(*a)->izq,mostrar);
        recorrer_arbol_en_preorden(&(*a)->der,mostrar);
    }
}

void recorrer_arbol_en_posorden(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        recorrer_arbol_en_posorden(&(*a)->izq,mostrar);
        recorrer_arbol_en_posorden(&(*a)->der,mostrar);
        mostrar((void*)&(*a)->dato);
    }
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

int buscar_en_arbol_recursiva(const t_arbol *a,const t_dato *d,t_cmp comparar)
{
    int cmp;
    if(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return OK;
        if(cmp>0)
            return buscar_en_arbol_recursiva(&(*a)->izq,d,comparar);
        else
            return buscar_en_arbol_recursiva(&(*a)->der,d,comparar);
    }
    return NO_ENCONTRADO;
}

int buscar_en_arbol_iterativa(const t_arbol *a,const t_dato *d,t_cmp comparar)
{
    int cmp;
    while(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return OK;
        if(cmp>0)
            a=&(*a)->izq;
        else
            a=&(*a)->der;
    }
    return NO_ENCONTRADO;
}

t_nodo **buscar_en_arbol_y_retornar_direccion_del_padre_recursiva(t_arbol *a,const t_dato *d,t_cmp comparar)
{
    int cmp;
    t_nodo **padre=a;
    if(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return NULL;
        if(cmp>0)
            return buscar_en_arbol_y_retornar_direccion_del_padre_recursiva_interna(&(*a)->izq,d,comparar,padre);
        else
            return buscar_en_arbol_y_retornar_direccion_del_padre_recursiva_interna(&(*a)->der,d,comparar,padre);
    }
    return NULL;
}

t_nodo **buscar_en_arbol_y_retornar_direccion_del_padre_recursiva_interna(t_arbol *a,const t_dato *d,t_cmp comparar,t_arbol *padre)
{
    int cmp;
    if(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return padre;
        *padre=*a;
        if(cmp>0)
            return buscar_en_arbol_y_retornar_direccion_del_padre_recursiva_interna(&(*a)->izq,d,comparar,padre);
        else
            return buscar_en_arbol_y_retornar_direccion_del_padre_recursiva_interna(&(*a)->der,d,comparar,padre);
    }
    return NULL;
}

t_nodo **buscar_en_arbol_y_retornar_direccion_del_padre_iterativa(t_arbol *a,const t_dato *d,t_cmp comparar)
{
    int cmp;
    t_nodo **padre=a;
    while(*a)
    {
        if(!(cmp=comparar((void*)&(*a)->dato,(void*)d)))
            return (a==padre)?NULL:padre;
        *padre=*a;
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

int cargar_arbol_con_archivo_binario_en_preorden(t_arbol *a,FILE *pf,t_cmp comparar)
{
    t_dato dato;
    fread(&dato,sizeof(t_dato),1,pf);
    while(!feof(pf))
    {
        if(!insertar_en_arbol_iterativa(a,&dato,comparar))
            return 0;
        fread(&dato,sizeof(t_dato),1,pf);
    }
    return OK;
}

int cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible(t_arbol *a,FILE *pf,t_cmp comparar)
{
    fseek(pf,0L,SEEK_END);
    return cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible_interna(a,pf,comparar,1,ftell(pf)/sizeof(t_dato));
}

int cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible_interna(t_arbol *a,FILE *pf,t_cmp comparar,int pri,int ult)
{
    t_dato dato;
    if(pri<=ult)
    {
        int medio=(ult-pri)/2;
        fseek(pf,(medio-1)*sizeof(t_dato),SEEK_SET);
        fread(&dato,sizeof(t_dato),1,pf);
        if(!feof(pf))
        {
            if(!insertar_en_arbol_iterativa(a,&dato,comparar))
            {
                vaciar_arbol(a);
                return 0;
            }
            cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible_interna(a,pf,comparar,pri,medio-1);
            cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible_interna(a,pf,comparar,medio+1,ult);
        }
    }
    return OK;
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

int calcular_nivel(const t_arbol *a)
{
    if(*a)
    {
        int niv_izq=calcular_altura(&(*a)->izq);
        int niv_der=calcular_altura(&(*a)->der);
        return (niv_izq>=niv_der)?niv_izq+1:niv_der+1;
    }
    return -1;
}

int arbol_balanceado(const t_arbol *a)
{
    if(*a)
    {
        int alt_izq=calcular_altura(&(*a)->izq);
        int alt_der=calcular_altura(&(*a)->der);
        return (alt_izq!=alt_der)?0:arbol_balanceado(&(*a)->izq)&&arbol_balanceado(&(*a)->der);
    }
    return 1;
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

int mostrar_y_contar_nodos(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        mostrar((void*)&(*a)->dato);
        return mostrar_y_contar_nodos(&(*a)->izq,mostrar)+mostrar_y_contar_nodos(&(*a)->der,mostrar)+1;
    }
    return 0;
}

int mostrar_y_contar_hojas(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if(es_hoja(a))
        {
            mostrar((void*)&(*a)->dato);
            return 1;
        }
        return mostrar_y_contar_hojas(&(*a)->izq,mostrar)+mostrar_y_contar_nodos(&(*a)->der,mostrar);
    }
    return 0;
}

int mostrar_y_contar_no_hojas(const t_arbol *a,t_mst mostrar)
{
    if(*a)
        if(!es_hoja(a))
        {
            mostrar((void*)&(*a)->dato);
            return mostrar_y_contar_hojas(&(*a)->izq,mostrar)+mostrar_y_contar_nodos(&(*a)->der,mostrar)+1;
        }
    return 0;
}

int mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(const t_arbol *a,t_mst mostrar)
{
    if(*a)
    {
        if((*a)->izq&&!(*a)->der)
        {
            mostrar((void*)&(*a)->dato);
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
            mostrar((void*)&(*a)->dato);
            return mostrar_y_contar_nodos_con_hijos_solo_por_derecha(&(*a)->der,mostrar)+1;
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
            mostrar((void*)&(*a)->dato);
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
        if(((*a)->izq||(*a)->der)&&!((*a)->izq&&(*a)->der))
        {
            mostrar((void*)&(*a)->dato);
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
            mostrar((void*)&(*a)->dato);
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
        mostrar((void*)&(*a)->dato);
        return 1;
    }
    return 0;
}

int mostrar_y_contar_hasta_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
        if(nivel)
        {
            mostrar((void*)&(*a)->dato);
            return mostrar_y_contar_hasta_nivel(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_hasta_nivel(&(*a)->der,nivel-1,mostrar)+1;
        }
    return 0;
}

int mostrar_y_contar_hasta_nivel_inclusive(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        mostrar((void*)&(*a)->dato);
        if(nivel>=0)
            return mostrar_y_contar_hasta_nivel_inclusive(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_hasta_nivel_inclusive(&(*a)->der,nivel-1,mostrar);
        return 1;
    }
    return 0;
}

int mostrar_y_contar_desde_nivel(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel>=0)
            return mostrar_y_contar_desde_nivel(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_desde_nivel(&(*a)->der,nivel-1,mostrar);
        mostrar((void*)&(*a)->dato);
        return mostrar_y_contar_desde_nivel(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_desde_nivel(&(*a)->der,nivel-1,mostrar)+1;
    }
    return 0;
}

int mostrar_y_contar_desde_nivel_inclusive(const t_arbol *a,int nivel,t_mst mostrar)
{
    if(*a)
    {
        if(nivel>=1)
            return mostrar_y_contar_desde_nivel_inclusive(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_desde_nivel_inclusive(&(*a)->der,nivel-1,mostrar);
        mostrar((void*)&(*a)->dato);
        return mostrar_y_contar_desde_nivel_inclusive(&(*a)->izq,nivel-1,mostrar)+mostrar_y_contar_desde_nivel_inclusive(&(*a)->der,nivel-1,mostrar)+1;
    }
    return 0;
}

void podar_hojas(t_arbol *a)
{
    if(*a)
    {
        if(es_hoja(a))
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

int eliminar_nodo_y_acomodar_ramas(t_arbol *a,const t_dato *d,t_cmp comparar)
{
    t_arbol *sub_arbol;
    a=buscar_en_arbol_y_retornar_direccion_del_padre_iterativa(a,d,comparar);
    if(!a)
        return NO_ENCONTRADO;
    while(!es_hoja(a))
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
