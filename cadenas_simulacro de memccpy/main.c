#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char cadena2[30];
    char car;
    unsigned n;
    printf("\n\n COPIAR CADENAS EN UNA CIERTA CANTIDAD DE BYTES DE OTRA \n O HASTA COPIAR CIERTO CARACTER \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n Ingrese la cantidad de bytes que desea copiar: \n\n\t");
    fflush(stdin);
    scanf("%d",&n);
    printf("\n\n Ingrese el caracter de corte: \n\n\t");
    fflush(stdin);
    scanf("%c",&car);
    mem_ccpy(cadena1,cadena2,car,n);
    printf("\n Las cadenas fueron copiadas \n");
    printf("\n Cadena 1: \t %s \n Cadena 2: \t %s \n\n",cadena1,cadena2);
    getch();
    return 0;
    }

