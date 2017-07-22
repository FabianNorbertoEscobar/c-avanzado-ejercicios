#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 7C");

    printf("\n\n SUMAR NÚMEROS CARGADOS EN PILAS \n");

    t_pila pila1,pila2,pila3;
    t_dato aux;

    crear_pila(&pila1);
    crear_pila(&pila2);
    crear_pila(&pila3);

    printf("\n Números que sumo \n");
    //cargados de forma casera
    int numero1[8]={7,5,1,4,9,8,6,3};
    int numero2[8]={6,3,5,4,7,9,0,5};
    printf("\n Número 1: \t 75149863");
    printf("\n Número 2: \t 63547905");

    //los cargo en las pilas
    int i;
    for(i=0;i<8;i++)
        {
        aux.numero=numero1[i];
        apilar(&pila1,&aux);
        }
    for(i=0;i<8;i++)
        {
        aux.numero=numero2[i];
        apilar(&pila2,&aux);
        }

    sumar_pilas(&pila1,&pila2,&pila3);

    //muestro el resultado desapilando
    printf("\n Suma: \t\t");
    while(!pila_vacia(&pila3))
        {
        desapilar(&pila3,&aux);
        printf("%d",aux.numero);
        }

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }

