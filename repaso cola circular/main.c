#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n COLA CIRCULAR \n");

    t_lista cola;
    t_dato dato;

    crear_cola(&cola);
    printf("\n Se ha creado una cola \n");

    printf("\n Carga de 5 elementos \n");
    int i;
    for(i=0;i<5;i++)
    {
        cargar_dato(&dato);
        acolar(&cola,&dato);
    }
    printf("\n Se ha cargado algo \n");

    if(!cola_llena(&cola))
        printf("\n La cola no está llena \n");

    ver_primero_en_cola(&cola,&dato);
    printf("\n\n El primero de la cola es: \t %d \n",dato.numero);
    ver_ultimo_en_cola(&cola,&dato);
    printf("\n\n El último de la cola es: \t %d \n",dato.numero);

    printf("\n Desacolar todo \n");
    while(!cola_vacia(&cola))
    {
        desacolar(&cola,&dato);
        mostrar_dato(&dato);
    }
    printf("\n Se ha desacolado todo \n");

    printf("\n Ingreso algo \n");
    cargar_dato(&dato);
    acolar(&cola,&dato);

    vaciar_cola(&cola);
    printf("\n La cola fue vaciada \n");

    printf("\n\n\t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
