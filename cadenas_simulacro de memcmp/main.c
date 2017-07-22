#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char cadena2[30];
    size_t n;
    printf("\n\n COMPARAR CADENAS HASTA CIERTA CANTIDAD DE BYTES \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n Ingrese la cantidad de bytes que desea comparar: \n\n\t");
    fflush(stdin);
    scanf("%d",&n);
    if(mem_cmp(cadena1,cadena2,n)>0)
        printf("\n La primera cadena es mayor a la segunda \n\n");
    else
        if(mem_cmp(cadena1,cadena2,n)<0)
            printf("\n La primera cadena es menor a la segunda \n\n");
        else
            printf("\n Las cadenas son iguales \n\n");
    getch();
    return 0;
    }

