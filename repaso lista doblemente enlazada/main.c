#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n LISTA DOBLEMENTE ENLAZADA \n\a\a");

    t_lista lista;
    t_dato dato;

    crear_lista(&lista);
    printf("\n Se ha creado una lista \n");

    if(lista_vacia(&lista))
        printf("\n La lista está vacía \n");

    printf("\n\n Cargue algunos elementos a la lista \n");
    int i;
    for(i=0;i<7;i++)
    {
        cargar_dato(&dato);
        if(!insertar_en_lista_ordenada_sin_duplicado(&lista,&dato,comparar_dato))
            printf("\n Duplicado \n");
    }
    printf("\n La lista ya tiene elementos \n\n");

    if(!lista_llena(&lista))
        printf("\n La lista no está llena \n");

    printf("\n Lista en orden ascendente \n");
    mostrar_lista_orden_ascendente(&lista,mostrar_nodo);

    printf("\n Eliminar el primero de la lista \n");
    if(eliminar_primero_de_lista(&lista,&dato))
    {
        printf("\n Nodo eliminado: \n");
        mostrar_dato(&dato);
    }

    printf("\n Eliminar el último de la lista \n");
    if(eliminar_ultimo_de_lista(&lista,&dato))
    {
        printf("\n Nodo eliminado: \n");
        mostrar_dato(&dato);
    }

    printf("\n\n Lista en orden descendente \n");
    mostrar_lista_orden_descendente(&lista,mostrar_nodo);

    printf("\n Eliminar un nodo \n");
    printf("\n Cargue una clave a eliminar: \n");
    int clave;
    printf("\n Ingrese clave (número): \t");
    scanf("%d",&clave);
    if(eliminar_de_lista_ordenada_por_clave(&lista,&dato,(void*)&clave,comparar_clave))
    {
        printf("\n Nodo eliminado: \n");
        mostrar_dato(&dato);
    }
    else
        printf("\n El nodo no fue encontrado \n");

    printf("\n Ver nodo actual de la lista \n");
    ver_nodo_actual_de_lista(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n Ver primero de la lista \n");
    ver_primero_de_lista(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n Ver último de la lista \n");
    ver_ultimo_de_lista(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n Cantidad de nodos: \t %d \n",contar_nodos_de_lista(&lista));

    vaciar_lista(&lista);
    printf("\n La lista fue vaciada \n");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
