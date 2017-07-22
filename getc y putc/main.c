#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    char c;
    printf("\n\n GETC Y PUTC \n");
    printf("\n\n GETC toma un entero desde un stream y retorna su ascii \n");
    printf("\n PUTC pone un caracter en un stream y retorna su ascii \n");
    printf("\n\n Tomaremos un caracter desde stdin, usando getc: \n\t ");
    c=(char)getc(stdin);
    printf("\n\n Y lo retornamos por stdout, usando putc: \n\t");
    putc(c,stdout);
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
