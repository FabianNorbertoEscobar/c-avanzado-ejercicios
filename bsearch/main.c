#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n BSEARCH \n");
    int lista[5]={6,4,8,9,2};
    printf("\n\n Esta función de stdlib.h sirve para encontrar un elemento \n en un array de cualquier tipo. \n Espera que se le envíe por parámetro una función de comparación \n\n");
    puts("\n Especifique un número a encontrar dentro de un array de entero \n (o un número negativo para salir):" );
    int num,*elementoPtr;
    scanf("%d",&num);
    while(num>=0)
        {
        if((elementoPtr=bsearch(&num,lista,5,sizeof(int),comparar_int))!=NULL)
            printf( "\n\n Encontrado: \t %d\n",*elementoPtr);
        else
            printf( "\n\n No encontrado: \t %d\n",num);
        puts("\n Especifique un número a encontrar dentro de un array de entero \n (o un número negativo para salir):" );
        scanf("%d",&num);
        }
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
