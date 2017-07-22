#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    FILE*pf;
    printf("\n\n GRABAR FICHERO BINARIO \n\n");
    pf=fopen("personas.dat",modo_de_apertura());
    if(!pf)
        {
        printf("\n El fichero no pudo ser grabado \n\n\a\a");
        exit(0);
        }
    cargar_archivo(&pf);
    fclose(pf);
    printf("\n\n El archivo \"personas.dat\" fue grabado exitosamente \n\n");
    printf("\n\n\t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
