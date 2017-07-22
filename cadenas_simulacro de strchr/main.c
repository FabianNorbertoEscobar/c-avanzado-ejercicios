#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char car;
    printf("\n\n PRIMERA OCURRENCIA DE UN CARACTER EN UNA CADENA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese un caracter para buscar su primera ocurrencia: \n\n\t");
    fflush(stdin);
    scanf("%c",&car);
    if(str_chr(cadena1,car)!=NULL)
        printf("\n Cadena a partir de la primera ocurrencia de %c: \n\n\t %s \n\n",car,strchr(cadena1,car));
    else
        printf("\n No se ha encontrado la ocurrencia del caracter %c \n\n",car);
    getch();
    return 0;
    }
