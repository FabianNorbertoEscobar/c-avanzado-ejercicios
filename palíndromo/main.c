#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[TOPE];
    printf("\n\n PALÍNDROMO \n");
    printf("\n Una palabra o frase es un palíndromo si se lee \n de igual manera en ambos sentidos \n");
    printf("\n Ingrese una cadena de caracteres para ver si es palíndrome \n\n\t");
    gets(cadena);
    if(es_palindromo(cadena))
        printf("\n \"%s\" es un palíndromo",cadena);
    else
        printf("\n \"%s\" no es un palíndromo",cadena);
    printf("\n\n");
    getch();
    return 0;
    }
