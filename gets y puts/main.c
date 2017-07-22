#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char entrada[81];
    char salida[81]="Fui escrito en pantalla por puts";

    printf("\n\n GETS \n");
    printf("\n Escribe una oración: \n");
    printf("\n La oración que escribiste fue \"%s\" \n",gets(entrada));

    printf("\n\n PUTS \n\n");
    if(puts(salida)==0)
        printf("\n Puts funcionó correctamente \n");
    else
        printf("\n Puts no ha funcionado como se esperaba \n");

    printf("\n\n \t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
