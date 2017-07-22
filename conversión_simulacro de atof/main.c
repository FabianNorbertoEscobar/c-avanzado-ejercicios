#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[TOPE];
    printf("\n\n ATOF \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena);
    printf("\n\n Cadena convertida a flotante: \t %f \n\n",mi_atof(cadena));
    getch();
    return 0;
    }
