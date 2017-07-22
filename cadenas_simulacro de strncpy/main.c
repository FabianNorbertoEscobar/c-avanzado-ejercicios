#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    size_t x;
    char cadena1[30];
    char cadena2[30];
    printf("\n\n COPIAR N CARACTERES DE UNA CADENA A OTRA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n Ingrese la cantidad de caracteres que desea copiar \n desde la cadena 2 hacia la cadena 1: \n\n\t");
    scanf("%d",&x);
    str_ncpy(cadena1,cadena2,x);
    printf("\n Las cadenas fueron copiadas \n");
    printf("\n Cadena 1: \t %s \n Cadena 2: \t %s \n\n",cadena1,cadena2);
    getch();
    return 0;
    }
