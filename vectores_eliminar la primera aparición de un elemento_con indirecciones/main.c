#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int op,vec[TAM],prim_lib=0;
    printf("\n\t\t\a\a ***VECTORES***");
    op=menu();
    while(op!=4)
        {
        switch(op)
            {
            case 1: llenar_vector(vec,&prim_lib);
                    break;
            case 2: mostrar_vector(vec,prim_lib);
                    break;
            case 3: borrar_primera_aparicion_de_elemento(vec,&prim_lib);
                    break;
            }
        op=menu();
        }
    printf("\n\t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return;
    }
