#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int v[TAM],ce=0;
    printf("\n\n CARGAR VECTOR \n");
    if(cargar_vector(v,TAM,&ce))
        printf("\n Se cargaron nuevos elementos; el vector ahora tiene %d elementos \n\n",ce);
    else
        printf("\n No se cargaron elementos \n\n");
    getch();
    return 0;
    }
