#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n LISTA CIRCULAR \n\a\a");

    t_lista lista;
    t_dato dato;

    crear_lista(&lista);
    printf("\n Se ha creado una lista \n");

    printf("\n Carga de 5 datos \n");
    int i;
    for(i=0;i<5;i++)
    {
        cargar_dato(&dato);
        poner_en_lista(&lista,&dato);
    }
    printf("\n\n Se han cargado 5 números en la lista \n");

    if(!lista_llena(&lista))
        printf("\n\n La lista no está llena \n\n");

    ver_primero_de_lista(&lista,&dato);
    printf("\n\n El primero de la lista es: %d \n",dato.numero);

    printf("\n\n Sacar todo de la lista \n");
    while(!lista_vacia(&lista))
    {
        sacar_de_lista(&lista,&dato);
        mostrar_dato(&dato);
    }
    printf("\n\n Se ha desalistado todo \n");

    printf("\n Carga de un dato \n");
    cargar_dato(&dato);
    poner_en_lista(&lista,&dato);

    vaciar_lista(&lista);
    printf("\n La lista fue vaciada \n");

    printf("\n\n\t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
}
