#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n \t GENERADOR DE NÚMEROS PSEUDO ALEATORIOS -- FUNCIÓN RAND \n");
    printf("\n Ingrese la cantidad de números pseudo aleatorios que desea generar: \n\n\t\t");
    int n,i;
    scanf("%d",&n);
    puts("\n\n\a\a");
    for(i=0;i<n;i++)
        printf("\t %d",rand()%100);
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
