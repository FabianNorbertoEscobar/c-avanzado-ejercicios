#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n Normalización de cadena tipo \"apellido, nombre/s\" \n\a\a");
    printf("\n Ingrese la cadena de caracteres a normalizar: \n\n\t");

    char cadena[50];
    fflush(stdin);

    gets(cadena);
    printf("\n\n Cadena ingresada: \t \"%s\"",cadena);

    normalizar_apellido_nombre(cadena);
    printf("\n\n Cadena normalizada: \t \"%s\"",cadena);

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
