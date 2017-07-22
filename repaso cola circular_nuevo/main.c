#include "header.h"

int main()
{
    t_lista cola;
    t_dato dato;

    int i;

    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 5F");

    printf("\n\n \t\t COLA CIRCULAR \n");

    crear_cola(&cola);
    printf("\n\n Se ha creado una cola \n");

    if(cola_vacia(&cola))
        printf("\n\n La cola está vacía \n");

    printf("\n\n Carga de 5 datos \n");
    for(i=0;i<5;i++)
    {
        cargar_dato(&dato);
        acolar(&cola,&dato);
    }
    printf("\n\n Se han cargado 5 datos \n");

    if(!cola_llena(&cola))
        printf("\n\n La cola no está llena \n");

    printf("\n\n Primero de la cola \n");
    ver_primero_de_cola(&cola,&dato);
    mostrar_dato(&dato);

    printf("\n\n Último de la cola \n");
    ver_ultimo_de_cola(&cola,&dato);
    mostrar_dato(&dato);

    printf("\n\n Desacolamos todo \n");
    while(!cola_vacia(&cola))
    {
        desacolar(&cola,&dato);
        mostrar_dato(&dato);
    }
    printf("\n\n Se ha desacolado todo \n");

    printf("\n\n Acolar algo \n");
    cargar_dato(&dato);
    acolar(&cola,&dato);
    printf("\n\n Se acoló algo \n");

    vaciar_cola(&cola);
    printf("\n\n Se ha vaciado la cola \n");

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
}
