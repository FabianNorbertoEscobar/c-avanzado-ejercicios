#include "header.h"

int main()
{
    t_lista pila;
    t_dato dato;

    int i;

    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 5F");

    printf("\n\n \t\t PILA CIRCULAR \n\a\a");

    crear_pila(&pila);
    printf("\n\n Se ha creado una pila \n");

    if(pila_vacia(&pila))
        printf("\n\n La pila está vacía \n");

    printf("\n\n Carga de 5 datos \n");
    for(i=0;i<5;i++)
    {
        cargar_dato(&dato);
        apilar(&pila,&dato);
    }
    printf("\n\n Se han cargado 5 datos \n");

    if(!pila_llena(&pila))
        printf("\n\n La pila no está llena \n");

    printf("\n\n Tope de la pila \n");
    ver_tope_de_pila(&pila,&dato);
    mostrar_dato(&dato);

    printf("\n\n Desapilamos todo \n");
    while(!pila_vacia(&pila))
    {
        desapilar(&pila,&dato);
        mostrar_dato(&dato);
    }
    printf("\n\n Se ha desapilado todo \n");

    printf("\n\n Apilo algo \n");
    cargar_dato(&dato);
    apilar(&pila,&dato);
    printf("\n\n Se apiló algo");

    vaciar_pila(&pila);
    printf("\n\n Se ha desapilado todo \n");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
