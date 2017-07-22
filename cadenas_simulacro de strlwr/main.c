#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    printf("\n\n CADENA A MINÚSCULA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    str_lwr(cadena1);
    printf("\n Cadena en minúscula: \t %s \n\n",cadena1);
    getch();
    return 0;
    }
