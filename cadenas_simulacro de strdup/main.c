#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[20];
    char *copia;
    printf("\n\n DUPLICAR CADENA \n");
    printf("\n Ingrese una cadena de caracteres (menos de 20 caracteres):\n\n\t");
    fflush(stdin);
    gets(cadena);
    if(copia=str_dup(cadena))
        printf("\n Se ha duplicado la cadena --->>> copia: %s \n\n",copia);
    else
        printf("\n No se ha generado la cadena \n\n");
    getch();
    return 0;
    }
