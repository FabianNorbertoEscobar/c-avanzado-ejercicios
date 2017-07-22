#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    FILE *pf;
    printf("\n\n LEER ARCHIVO BINARIO \n\n");

    //no comentar el que quiera leer
    //pf=fopen("personas.dat","rb");
    pf=fopen("personas_hardcodeado.dat","rb");

    if(!pf)
        {
        printf("\n\n No se pudo abrir el archivo \n\n\a\a");
        return 0;
        }
    leer_archivo(&pf);
    printf("\n\n El archivo fue leído correctamente \n\n");
    fclose(pf);
    printf("\n\n\t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
