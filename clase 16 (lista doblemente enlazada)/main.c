#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n LISTA DOBLEMENETE ENLAZADA \n\a\a");

    t_lista lista;
    t_dato dato;

    crear_lista(&lista);
    printf("\n\n Se ha creado una lista \n");

    int i;

    printf("\n\n Cargar la lista: \n");
    for(i=0;i<5;i++)
    {
        cargar_dato(&dato);
        insertar_en_lista_ordenada_sin_duplicado(&lista,&dato,comparar_enteros);
    }
    printf("\n\n Se ha cargado la lista \n");

    if(!lista_llena(&lista))
        printf("\n\n La lista no está llena \n");

    printf("\n\n Primero de la lista \n");
    ver_primero_de_lista(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n\n Último de la lista \n");
    ver_ultimo_de_lista(&lista,&dato);
    mostrar_dato(&dato);

    int clave;
    printf("\n\n Eliminar de la lista por clave \n");
    printf("\n Ingrese clave a eliminar: \n");
    ingresa_clave(&clave);

    if(eliminar_de_lista_ordenada_con_clave(&lista,&dato,&clave,comparar_claves))
    {
        printf("\n\n Se ha eliminado exitosamente este elemento de la lista \n");
        mostrar_dato(&dato);
    }
    else
        printf("\n\n No se ha encontrado un elemento con esa clave \n");

    printf("\n\n Esta es la lista que ha quedado: \n");
    mostrar_lista(&lista,mostrar_dato);

    printf("\n\n Vaciar la lista \n");
    vaciar_lista(&lista);

    if(lista_vacia(&lista))
        printf("\n\n La lista se ha vaciado exitosamente \ns");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
