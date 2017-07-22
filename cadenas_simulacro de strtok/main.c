#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cad[100];
    char separador[4]=" \n\t";
    char *ptr;
    printf("\n\n QUEBRAR UNA CADENA DE CARACTERES \n");
    printf("\n Ingrese una oración (menos de 100 caracteres): \n\n\t");
    gets(cad);
    ptr=str_tok(cad,separador); // Primera llamada => Primer token
    printf("\n\n Cadena quebrada: \n\n");
    printf("%s\n",ptr);
    while((ptr=str_tok(NULL,separador))!=NULL ) // Posteriores llamadas
        printf("%s\n",ptr);
    getch();
    return 0;
    }
