#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n FUNCIÓN ATEXIT \n");
    printf("\n Esta función de stdlib.h sirve para ejecutar una función void sin parámetros \n que se le manda por parámetro, antes de cerrar la ejecución del programa.. \n\n");
    atexit(antes_de_salir);
    getch();
    return 0;
    }
