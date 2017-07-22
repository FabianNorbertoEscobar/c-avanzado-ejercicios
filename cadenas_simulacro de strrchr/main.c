#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char car;
    printf("\n\n ÚLTIMA OCURRENCIA DE UN CARACTER \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese un caracter para buscar su primera ocurrencia: \n\n\t");
    fflush(stdin);
    scanf("%c",&car);
    if(str_rchr(cadena1,car)!=NULL)
        printf("\n Cadena a partir de la última ocurrencia de %c: \n\n\t %s \n\n",car,strrchr(cadena1,car));
    else
        printf("\n No se ha encontrado la ocurrencia del caracter %c \n\n",car);
    getch();
    return 0;
    }
