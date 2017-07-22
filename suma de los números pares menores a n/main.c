#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,suma,par;
    suma=0;
    par=2;//primer número par
    printf("\n SUMA DE NÚMEROS PARES MENORES A N \n");
    do
        {
        printf("\n Ingrese un número mayor o igual a cero: \t");
        scanf("%d",&n);
        }
    while(n<0);
    while(par<n)// veo si corresponde sumar el par
        {
        suma+=par;//sumo el par
        par+=2;//paso al próximo número par
        }
    printf("\n La suma de los números pares menores a %d es %d \n\n",n,suma);
    getch();
    return 0;
    }
