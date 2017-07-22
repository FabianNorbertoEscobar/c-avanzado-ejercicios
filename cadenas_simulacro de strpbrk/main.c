#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char cadena2[30];
    printf("\n\n PRIMERA OCURRENCIA DE CUALQUIER CARACTER \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    if(str_pbrk(cadena1,cadena2)!=NULL)
        printf("\n Primera cadena a partir de la primera ocurrencia \n de un caracter de la segunda cadena: \n\n\t %s \n\n",str_pbrk(cadena1,cadena2));
    else
        printf("\n No se ha encontrado la ocurrencia de ningún caracter \n de la segunda cadena \n\n");
    getch();
    return 0;
    }
