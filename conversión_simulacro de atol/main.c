#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[TOPE];
    printf("\n\n ATOL \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena);
    printf("\n\n Cadena convertida a entero largo: \t %ld \n\n",mi_atol(cadena));
    getch();
    return 0;
    }

