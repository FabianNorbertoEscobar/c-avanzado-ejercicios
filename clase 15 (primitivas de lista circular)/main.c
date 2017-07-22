#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n LISTA CIRCULAR \n");

    t_lista lista;
    t_dato dato;

    int i;

    crear_lista(&lista);
    printf("\n\n Se ha creado una lista \n");

    printf("\n\n Cargue la lista: \n");
    for(i=0;i<5;i++)
        {
        cargar_dato(&dato);
        poner_en_lista(&lista,&dato);
        }
    printf("\n\n Se ingresaron 5 elementos \n");

    if(!lista_llena(&lista))
        printf("\n\n La lista no está llena \n");

    printf("\n\n Ver primero: \n");
    ver_primero_de_lista(&lista,&dato);
    printf("\n\n El primero de la lista es: \n");
    mostrar_dato(&dato);

    printf("\n\n Sacar de la lista \n");
    while(!lista_vacia(&lista))
        {
        sacar_de_lista(&lista,&dato);
        mostrar_dato(&dato);
        }
    printf("\n\n La lista está vacía \n");

    printf("\n\n Cargar algo: \n");
    cargar_dato(&dato);
    poner_en_lista(&lista,&dato);
    printf("\n\n El dato fue cargado \n");

    vaciar_lista(&lista);
    printf("\n\n La lista fue vaciada exitosamente \n");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }

