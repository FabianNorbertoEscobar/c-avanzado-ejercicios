#include "header.h"

void *mem_cpy(void *destino,const void *origen,size_t tam_memb)
{
    void *inicio=destino;
    while(tam_memb--)
    {
        *(char*)destino=*(char*)origen;
        destino++;
        origen++;
    }
    return inicio;
}

void intercambio(void *v1,void *v2,size_t tam_memb)
{
    void *aux=malloc(tam_memb);
    if(!aux)
        exit(EXIT_FAILURE);
    mem_cpy(aux,v1,tam_memb);
    mem_cpy(v1,v2,tam_memb);
    mem_cpy(v2,aux,tam_memb);
    free(aux);
}

void ordenamiento_por_seleccion(void *v,size_t n_memb,size_t tam_memb,t_cmp comparar)
{
    void *lector,*menor,*ult=v+(n_memb-1)*tam_memb;
    while(v<ult)
    {
        menor=v;
        lector=v+tam_memb;
        while(lector<=ult)
        {
            if(comparar(lector,menor)<0)
                menor=lector;
            lector+=tam_memb;
        }
        if(v!=menor)
            intercambio(v,menor,tam_memb);
        v+=tam_memb;
    }
}

void mostrar_vector_enteros(int v[],int ce)
{
    int i;
    for(i=0;i<ce;i++)
        printf("   %d",v[i]);
}

int comparar_enteros(const void *v1,const void *v2)
{
    int *e1=(int*)v1,*e2=(int*)v2;
    return *e1-*e2;
}
