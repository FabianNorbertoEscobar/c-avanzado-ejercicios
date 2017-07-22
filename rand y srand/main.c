#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n \t RAND Y SRAND \n");
    printf("\n Estas funciones de stdlib.h generan números pseudo aleatorios \n (srand cambia la semilla, porque sino rand siempre genera la misma secuencia de números) \n");

    int i;
    printf("\n\n Con la semilla por defecto \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand());

    srand(2);
    printf("\n\n Con semilla 2 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand());

    srand(50);
    printf("\n\n Con semilla 5 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand());

    srand(200);
    printf("\n\n Con semilla 500 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand());

    srand(1000);
    printf("\n\n Con semilla 1000 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand());

    srand(0);

    printf("\n\n Solo números entre 0 y 6 \n");//siempre se genera a partir del cero
    for(i=0;i<50;i++)
        printf("%d  ",rand()%7);

    printf("\n\n Solo números entre 1 y 7 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand()%7+1);

    printf("\n\n Solo números entre 1 y 100 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand()%100+1);

    printf("\n\n Solo números entre -100 y 0 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand()%100-100);

    printf("\n\n Solo números entre 0 y 999 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand()%1000);

    printf("\n\n Solo números entre 1000 y 1999 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand()%1000+1000);

    printf("\n\n Solo números entre -128 y 805 \n");
    for(i=0;i<50;i++)
        printf("%d  ",rand()%928-123);//se suman 128 y 805 para saber cuántos númerps deseo generar y luego los acomodo en el rango que desee

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
