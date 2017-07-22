#include "header.h"
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
int menu()
    {
    int op,band;
    band=0;
    printf("\n\n\t <<<MENÚ>>> \n");
    printf("\n\t 1-Llenar vector");
    printf("\n\t 2-Mostrar vector");
    printf("\n\t 3-Eliminar todas las apariciones de un elemento del vector");
    printf("\n\t 4-Salir");
    do
        {
        if(band==1)
            printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
        printf("\n\t\t\t Opción: \t\t");
        scanf("%d",&op);
        band=1;
        }
    while(!validadato(op,1,4));
    return op;
    }
void llenar_vector(int *v,int *prim_lib)
    {
    int i,op,band=0;
    if(*prim_lib!=0)
        {
        printf("\n El vector ya ha sido llenado. Si continúa se borrarán \n los datos del vector. ¿Desea continuar? \n\a\a");
        printf("\n\t 1-SI \n\t 2-NO \n");
        do
            {
            if(band==1)
                printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
            printf("\n\t\t Opción: \t\t");
            scanf("%d",&op);
            band=1;
            }
        while(!validadato(op,1,2));
        if(op==2)
            return;
        *prim_lib=0;
        printf("\n Se han borrado todos los datos del vector \n\n\a\a");
        }
    printf("\n Proceda a la carga del vector \n (cuenta con %d posiciones para almacenar números enteros)\n",TAM);
    for(i=0;i<TAM;i++)
        {
        printf("\n Ingrese el elemento de la posición %d: \n\n\t\t",i+1);
        scanf("%d",v+i);
        *prim_lib+=1;
        if(i!=TAM-1)
            {
            printf("\n ¿Desea seguir ingresando elementos? \n");
            printf("\n\t 1-SI \n\t 2-NO \n");
            band=0;
            do
                {
                if(band==1)
                    printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
                printf("\n\t\t Opción: \t\t");
                scanf("%d",&op);
                band=1;
                }
            while(!validadato(op,1,2));
            if(op==2)
                break;
            }
        }
    printf("\n El vector ha sido cargado exitosamente \n");
    printf("\n Cantidad de posiciones llenas: %d \n ",*prim_lib);
    printf("\n Cantidad de posiciones vacías: %d \n ",TAM-*prim_lib);
    }
void mostrar_vector(int *v,int prim_lib)
    {
    int i;
    if(prim_lib!=0)
        {
        printf("\n POSICIÓN \t CONTENIDO \n");
        for(i=0;i<prim_lib;i++)
            printf("\n %d \t\t %d",i+1,*(v+i));
        printf("\n\n Cantidad de posiciones llenas: %d \n ",prim_lib);
        printf("\n Cantidad de posiciones vacías: %d \n ",TAM-prim_lib);
        }
    else
        printf("\n El vector que quiere mostrar está vacío \n");
    }
void borrar_todas_las_apariciones_de_elemento(int *v,int *prim_lib)
    {
    int i,pos,op,x,band;
    if(*prim_lib==0)
        printf("\n El vector está vacío. No hay ningún elemento para borrar. \n");
    else
        {
        printf("\n Ingrese el elemento a eliminar: \n\n\t\t");
        scanf("%d",&x);
        pos=busqueda_secuencial(v,*prim_lib,x);
        if(pos==-1)
            printf("\n El elemento que quiere eliminar no aparece en el vector \n\n");
        else
            {
            while(pos!=-1)
                {
                for(i=pos;i<*prim_lib;i++)
                    *(v+i)=*(v+i+1);
                *prim_lib-=1;
                pos=busqueda_secuencial(v,*prim_lib,x);
                }
            printf("\n El elemento ha sido eliminado exitosamente \n\n");
            }
        }
    }
int busqueda_secuencial(int *v,int ce,int x)
    {
    int p,i;
    p=-1;
    i=0;
    while(i<ce&&p==-1)
        if(*(v+i)==x)
            p=i;
        else
            i++;
    return p;
    }

