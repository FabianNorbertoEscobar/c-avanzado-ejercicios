#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,suma,i;
    printf("\n SUMA DE LOS N PRIMEROS NÚMEROS NATURALES \n");
    do
        {
        printf("\n Ingrese un número entero positivo:\t");
        scanf("%d",&n);
        }
    while(n<1);
    suma=0;
    for(i=0;i<=n;i++)//genero los naturales
        suma+=i;//acumulo
    printf("\n\n La suma de los primeros %d números naturales es %d \n\n",n,suma);
    getch();
    return 0;
    }
