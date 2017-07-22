#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n CADENAS DE CARACTERES \n");

    char cadena1[]="hola";
    char cadena2[20]="mundo";

    char copia[20];
    str_cpy(copia,cadena1);
    puts("\n Cadena copiada \n\t");
    puts(copia);

    printf("\n Longitud cadena copiada: \t %d",str_len(copia));

    puts("\n\n Cadenas concatenadas \n");
    char concatenacion[40]="";
    str_cat(concatenacion,cadena1);
    str_cat(concatenacion,cadena2);
    puts(concatenacion);

    printf("\n Comparación: \t %d \n",str_cmp(cadena1,cadena2));
    if(str_cmp(cadena1,cadena2)>0)
        printf("\n La cadena 1 es mayor \n");
    else
        printf("\n La cadena 2 es mayor \n");

    char c='a';
    char C='A';
    printf("\n %c --- a mayúscula ---> %c \n",c,A_MAYUSCULA(c));
    printf("\n %c --- a minúscula ---> %c \n",C,A_MINUSCULA(C));

    char copia_cortada[20];
    puts("\n Cadena copiada en 3 caracteres \n");
    puts(str_ncpy(copia_cortada,cadena2,3));

    puts("\n\n Cadenas concatenadas en 3 caracteres \n");
    char concatenacion_2[40]="";
    str_ncat(concatenacion_2,cadena1,3);
    puts(concatenacion_2);

    puts("\n Cadena 1 a partir de la primera ocurrencia del caracter l \n");
    puts(str_chr(cadena1,'l'));

    puts("\n Cadena 2 a partir de la última ocurrencia del caracter n \n");
    puts(str_rchr(cadena2,'n'));

    puts("\n Cadena 1 a partir de la ocurrencia de la cadena 2 \n");
    puts(str_str(cadena1,cadena2));

    printf("\n Cadena 1: \t %s",cadena1);
    printf("\n --- a mayúscula ---> %s \n",str_upr(cadena1));
    printf("\n --- a minúscula ---> %s \n",str_lwr(cadena1));

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
