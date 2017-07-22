#include "header.h"

int main()
{
    t_lista lista;
    t_dato dato;

    int i;
    int clave;

    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 5F");

    printf("\n\n \t\t LISTA DOBLEMENTE ENLAZADA \n\a\a");

    crear_lista(&lista);
    printf("\n\n Se ha creado una lista \n");

    if(lista_vacia(&lista))
        printf("\n\n La lista está vacía \n");

    printf("\n\n Carga de algunos elementos \n");
    for(i=0;i<7;i++)
    {
        cargar_dato(&dato);
        insertar_en_lista_ordenada_sin_duplicados(&lista,&dato,comparar_enteros);
    }
    printf("\n\n Se han cargado algunos elementos \n");

    if(!lista_llena(&lista))
        printf("\n\n La lista no está llena \n");

    printf("\n\n Primero de la lista \n");
    ver_primero_de_lista(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n\n Último de la lista \n");
    ver_ultimo_de_lista(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n\n Eliminar por clave (tres eliminaciones) \n");
    for(i=0;i<3;i++)
    {
        printf("\n\n Ingrese clave a eliminar: \t");
        scanf("%d",&clave);
        if(eliminar_de_lista_ordenada_con_clave(&lista,&dato,(void*)&clave,comparar_enteros))
            printf("\n\n Se ha eliminado el nodo exitosamente \n");
        else
            printf("\n\n No se ha encontrado un dato con esa clave \n");
    }

    printf("\n\n Lista en orden ascendente \n\n");
    mostrar_lista_orden_ascendente(&lista,mostrar_nodo);

    printf("\n\n Lista en orden descendente \n\n");
    mostrar_lista_orden_descendente(&lista,mostrar_nodo);

    vaciar_lista(&lista);
    printf("\n\n La lista se ha vaciado \n");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n \a\a");
    getch();
    return 0;
}
