#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n USO DE PRIMITIVAS DE COLA DINÁMICA \n");
    t_cola cola;
    t_dato dato;

    int i=0;

    crear_cola(&cola);
    printf("\n Se ha creado una cola \n");

    printf("\n Acolar \n");
    while(i<5)
        {
        cargar_dato(&dato);
        acolar(&cola,&dato);
        i++;
        }

    if(!cola_vacia(&cola))
        ver_primero_en_cola(&cola,&dato);
    printf("\n Primero de la cola: \t %d \n",dato.numero);

    if(!cola_vacia(&cola))
        ver_ultimo_en_cola(&cola,&dato);
    printf("\n Último de la cola: \t %d \n",dato.numero);

    printf("\n Desacolar \n");
    while(i>0)
        {
        desacolar(&cola,&dato);
        mostrar_dato(&dato);
        i--;
        }

    printf("\n Acolar algo \n");
    cargar_dato(&dato);
    acolar(&cola,&dato);

    printf("\n La cola se ha vaciado \n");
    vaciar_cola(&cola);

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
