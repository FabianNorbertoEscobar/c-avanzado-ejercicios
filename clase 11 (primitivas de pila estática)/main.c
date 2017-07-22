#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n USO DE PRIMITIVAS DE PILA ESTÁTICA \n");
    t_pila pila;
    t_dato dato;

    crear_pila(&pila);
    printf("\n Se ha creado una pila \n");

    printf("\n Apilar \n");
    while(!pila_llena(&pila))
        {
        cargar_dato(&dato);
        apilar(&pila,&dato);
        }

    if(!pila_vacia(&pila))
        ver_tope(&pila,&dato);
    printf("\n Tope de la pila: \t %d \n",dato.numero);

    printf("\n Desapilar \n");
    while(!pila_vacia(&pila))
        {
        desapilar(&pila,&dato);
        mostrar_dato(&dato);
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
