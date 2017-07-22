#include "header.h"
int cargar_vector(int *v,int tam,int *ce)
    {
    unsigned cant;
    int *ult;
    printf("\n Ingrese cantidad de elementos a cargar:\t");
    fflush(stdin);
    scanf("%d",&cant);
    if((*ce+cant)>tam)
        return 0;//no cargué
    ult=v+*ce+cant;//me voy a la última posición a la que puedo cargar
    for(v=v+*ce;v<ult;v++)//pongo el vector en la ultima posicion libre
        {
        printf("\n Ingrese dato para guardar en el vector:\t ");
        fflush(stdin);
        scanf("%d",v);
        }
    *ce+=cant;
    return 1;//cargué
    }
