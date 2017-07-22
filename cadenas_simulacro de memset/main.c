#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[30];
    char car;
    unsigned n;
    printf("\n\n SETEAR UN CARACTER A UNA CADENA EN UNA CIERTA CANTIDAD DE BYTES \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena);
    printf("\n Ingrese un caracter para setearlo a la cadena: \n\n\t");
    fflush(stdin);
    scanf("%c",&car);
    printf("\n\n Ingrese la cantidad de bytes que desea setear: \n\n\t");
    fflush(stdin);
    scanf("%d",&n);
    mem_set(cadena,car,n);
    printf("\n La cadena fue seteada exitosamente \n");
    printf("\n Cadena : \t %s \n\n",cadena);
    getch();
    return 0;
    }


