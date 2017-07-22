#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n COLA ESTÁTICA \n\a\a");

    t_cola cola;
    t_dato dato;

    crear_cola(&cola);
    printf("\n\n Se ha creado una cola \n");

    if(cola_vacia(&cola))
        printf("\n\n La cola está vacía \n\n");

    printf("\n\n Acolar \n");
    while(!cola_llena(&cola))
    {
        cargar_dato(&dato);
        acolar(&cola,&dato);
    }
    printf("\n\n Se ha cargado la cola \n");

    printf("\n\n Ver primero en cola \n");
    ver_primero(&cola,&dato);
    mostrar_dato(&dato);

    printf("\n\n Ver último en cola \n");
    ver_ultimo(&cola,&dato);
    mostrar_dato(&dato);

    printf("\n\n Desacolar \n");
    while(!cola_vacia(&cola))
    {
        desacolar(&cola,&dato);
        mostrar_dato(&dato);
    }
    printf("\n\n Se ha desacolado todo \n");

    printf("\n\n Ingresar algo \n");
    cargar_dato(&dato);
    acolar(&cola,&dato);
    printf("\n\n Se ha cargado algo \n");

    vaciar_cola(&cola);
    printf("\n\n Se ha vaciado la cola \n");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}

