#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int x,y;
    printf("\n INTERCAMBIO DE ELEMENTOS USANDO PUNTEROS \n");
    printf("\n Ingrese un número entero: \n\n\t\t");
    scanf("%d",&x);
    printf("\n Ingrese un número entero: \n\n\t\t");
    scanf("%d",&y);
    mostrar(x,y);
    printf("\n Los elementos son intercambiados \n");
    intercambiar(&x,&y);//mando las direcciones de memoria para retocar los valores en memoria principal y no en la memoria local
    mostrar(x,y);
    getch();
    return 0;
    }

