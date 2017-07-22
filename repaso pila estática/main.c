#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n PILA ESTÁTICA \n\a\a");

    t_pila pila;
    t_dato dato;

    crear_pila(&pila);
    printf("\n\n Se ha creado una pila \n");

    if(pila_vacia(&pila))
        printf("\n\n La pila está vacía \n\n");

    printf("\n\n Apilar \n");
    while(!pila_llena(&pila))
    {
        cargar_dato(&dato);
        apilar(&pila,&dato);
    }
    printf("\n\n Se ha cargado la pila \n");

    printf("\n\n Ver tope \n");
    ver_tope(&pila,&dato);
    mostrar_dato(&dato);

    printf("\n\n Desapilar \n");
    while(!pila_vacia(&pila))
    {
        desapilar(&pila,&dato);
        mostrar_dato(&dato);
    }
    printf("\n\n Se ha desapilado todo \n");

    printf("\n\n Ingresar algo \n");
    cargar_dato(&dato);
    apilar(&pila,&dato);
    printf("\n\n Se ha cargado algo \n");

    vaciar_pila(&pila);
    printf("\n\n Se ha vaciado la pila \n");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
