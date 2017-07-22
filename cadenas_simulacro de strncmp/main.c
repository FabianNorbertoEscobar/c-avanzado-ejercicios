#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    size_t x;
    char cadena1[30];
    char cadena2[30];
    printf("\n\n COMPARAR CADENAS HASTA N CARACTERES \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n Ingrese la cantidad de caracteres que desea comparar: \n\n\t");
    scanf("%d",&x);
    if(str_ncmp(cadena1,cadena2,x)>0)
        printf("\n La primera cadena es mayor a la segunda \n\n");
    else
        if(str_ncmp(cadena1,cadena2,x)<0)
            printf("\n La primera cadena es menor a la segunda \n\n");
        else
            printf("\n Las cadenas son iguales \n\n");
    getch();
    return 0;
    }
