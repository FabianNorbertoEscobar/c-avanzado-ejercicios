#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n PILA CIRCULAR \n");

    t_lista pila;
    t_dato dato;

    crear_pila(&pila);
    printf("\n\n Se ha creado una pila \n");

    printf("\n Carga de 5 elementos \n");
    int i;
    for(i=0;i<5;i++)
    {
        cargar_dato(&dato);
        apilar(&pila,&dato);
    }
    printf("\n La pila fue cargada \n");

    if(!pila_llena(&pila))
        printf("\n La pila no está llena \n");

    ver_tope(&pila,&dato);
    printf("\n El tope de la pila es: \t %d \n",dato.numero);

    printf("\n Desapilar todo \n");
    while(!pila_vacia(&pila))
    {
        desapilar(&pila,&dato);
        mostrar_dato(&dato);
    }
    printf("\n Se desapiló todo \n");

    printf("\n Apila algo \n");
    cargar_dato(&dato);
    apilar(&pila,&dato);

    vaciar_pila(&pila);
    printf("\n La pila fue vaciada \n");

    printf("\n\n\t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
