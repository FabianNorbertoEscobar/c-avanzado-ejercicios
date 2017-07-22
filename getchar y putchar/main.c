#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n GETCHAR \n");
    printf("\n Ingrese un caracter: \t");
    printf("\n El caracter que usted ingresó fue: %c \n",getchar());

    printf("\n\n PUTCHAR \n");
    char nombre[30];
    int i;
    printf("\n Ahora escribe tu nombre: \t");
    fflush(stdin);
    gets(nombre);
    printf("\n Tu nombre escrito al revés es: \t");
    for(i=strlen(nombre)-1;i>=0;i--)
        putchar(nombre[i]);

    printf("\n\n\n\n \t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
