#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    FILE *pf;
    printf("\n\n FUNCIÓN PARA ABRIR UN ARCHIVO \n");
    if(!abrir_archivo(&pf,"fichero.dat","rb",CON_MENSAJE))
        exit(EXIT_FAILURE);
    printf("\n\n El archivo fue abierto exitosamente \n\n");
    fclose(pf);
    printf("\n\n Fin del programa \n\n");
    getch();
    return 0;
    }
