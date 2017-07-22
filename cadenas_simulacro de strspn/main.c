#include "header.h"
int main()
    {
setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char cadena2[30];
    printf("\n\n CANTIDAD DE CARACTERES DE UNA CADENA QUE NO PERTENECEN A LA OTRA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n La cantidad de caracteres de la primera cadena en que no está \n algún caracter de la segunda cadena es de %d \n\n",str_spn(cadena1,cadena2));
    getch();
    return 0;
    }
