#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 0E");
    int v[TAM];
    int prim_libre=1;
    menu(v,TAM,&prim_libre);
    printf("\n\n\a\a Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }
