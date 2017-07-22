#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cadena[TOPE];
    printf("\n\n VALOR NUMÉRICO DE UNA CADENA DE CARACTERES \n");
    printf("\n Cada caracter de una cadena representa un número en código Ascii.\n");
    printf("\n El valor numérico de una cadena es la suma de los ascii de todos los caracteres\n\n");
    printf("\n Ingrese una cadena de caracteres: \n\n\t");
    gets(cadena);
    printf("\n El valor numérico de \"%s\" es %d \n\n",cadena,valor_numerico_cadena(cadena));
    getch();
    return 0;
    }
