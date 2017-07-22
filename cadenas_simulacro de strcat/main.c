#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char cadena2[30];
    printf("\n\n CONCATENAR CADENAS \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n Cadenas concatenadas: %s \n\n",str_cat(cadena1,cadena2));
    getch();
    return 0;
    }
