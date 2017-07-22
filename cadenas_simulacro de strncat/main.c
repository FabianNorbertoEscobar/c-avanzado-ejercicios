#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    size_t x;
    char cadena1[30];
    char cadena2[30];
    printf("\n\n CONCATENAR N CARACTERES DE UNA CADENA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n Ingrese la cantidad de caracteres que desea copiar: \n\n\t");
    scanf("%d",&x);
    printf("\n\n Cadenas concatenadas: %s \n\n",str_ncat(cadena1,cadena2,x));
    getch();
    return 0;
    }
