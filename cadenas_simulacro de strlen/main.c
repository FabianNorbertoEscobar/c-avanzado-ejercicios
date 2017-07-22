#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[30];
    printf("\n\n LONGITUD DE UNA CADENA \n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    fflush(stdin);
    gets(cadena);
    printf("\n\n La longitud de la cadena \"%s\" es %d \n",cadena,str_len(cadena));
    getch();
    return 0;
    }
