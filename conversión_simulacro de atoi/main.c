#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[TOPE];
    printf("\n\n ATOI \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena);
    printf("\n\n Cadena convertida a entero: \t %d \n\n",mi_atoi(cadena));
    getch();
    return 0;
    }
