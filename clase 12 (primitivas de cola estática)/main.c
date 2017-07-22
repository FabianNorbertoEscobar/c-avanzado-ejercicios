#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n USO DE PRIMITIVAS DE COLA ESTÁTICA \n");
    t_cola cola;
    t_dato dato;

    crear_cola(&cola);
    printf("\n Se ha creado una cola \n");

    printf("\n Acolar \n");
    while(!cola_llena(&cola))
        {
        cargar_dato(&dato);
        acolar(&cola,&dato);
        }

    if(!cola_vacia(&cola))
        ver_primero_en_cola(&cola,&dato);
    printf("\n Primero de la cola: \t %d \n",dato.numero);

    if(!cola_vacia(&cola))
        ver_ultimo_en_cola(&cola,&dato);
    printf("\n Último de la cola: \t %d \n",dato.numero);

    printf("\n Desacolar \n");
    while(!cola_vacia(&cola))
        {
        desacolar(&cola,&dato);
        mostrar_dato(&dato);
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

