#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena1[30];
    char cadena2[30];
    unsigned n;
    printf("\n\n MOVER CADENA EN UNA CIERTA CANTIDAD DE BYTES EN OTRA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena1);
    printf("\n Ingrese otra cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena2);
    printf("\n\n Ingrese la cantidad de bytes que desea mover: \n\n\t");
    fflush(stdin);
    scanf("%d",&n);
    mem_move(cadena1,cadena2,n);
    printf("\n Una cadena fue movida dentro de la otra \n");
    printf("\n Cadena 1: \t %s \n Cadena 2: \t %s \n\n",cadena1,cadena2);
    getch();
    return 0;
    }

