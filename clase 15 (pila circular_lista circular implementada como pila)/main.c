#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n PILA CIRCULAR - LISTA CIRCULAR IMPLEMENTADA COMO PILA \n");
    t_lista pila;
    t_dato dato;

    int i=0;

    crear_pila(&pila);
    printf("\n Se ha creado una pila \n");

    printf("\n Apilar \n");
    while(i<5)
        {
        cargar_dato(&dato);
        apilar(&pila,&dato);
        i++;
        }

    if(!pila_vacia(&pila))
        ver_tope(&pila,&dato);
    printf("\n Tope de la pila: \t %d \n",dato.numero);

    printf("\n Desapilar \n");
    while(i>0)
        {
        desapilar(&pila,&dato);
        mostrar_dato(&dato);
        i--;
        }

    printf("\n Apilar algo \n");
    cargar_dato(&dato);
    apilar(&pila,&dato);

    printf("\n La pila se ha vaciado \n");
    vaciar_pila(&pila);

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }

