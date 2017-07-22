#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char car;
    unsigned n;
    printf("\n\n PRIMERA OCURRENCIA DE UN CARACTER \n EN CIERTA CANTIDAD DE BYTES DE UNA CADENA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese un caracter para buscar su primera ocurrencia: \n\n\t");
    fflush(stdin);
    scanf("%c",&car);
    printf("\n\n Ingrese la cantidad de bytes en las que desea buscar: \n\n\t");
    fflush(stdin);
    scanf("%d",&n);
    if(mem_chr(cadena1,car,n)!=NULL)
        printf("\n Cadena a partir de la primera ocurrencia de %c: \n\n\t %s \n\n",car,(char*)mem_chr(cadena1,car,n));
    else
        printf("\n No se ha encontrado la ocurrencia del caracter %c \n\n",car);
    getch();
    return 0;
    }
