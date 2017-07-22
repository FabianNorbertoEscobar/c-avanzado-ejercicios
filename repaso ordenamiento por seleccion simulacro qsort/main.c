#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n ORDENAMIENTO POR SELECCIÓN \n\a\a");

    int vec1[TAM]={4,8,9,6,5,7,3,1,0,2};

    printf("\n\n Ordenando vector de enteros \n");
    printf("\n\n Antes \n\n");
    mostrar_vector_enteros(vec1,TAM);
    printf("\n\n Después \n\n");
    ordenamiento_por_seleccion(vec1,TAM,sizeof(int),comparar_enteros);
    mostrar_vector_enteros(vec1,TAM);

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
