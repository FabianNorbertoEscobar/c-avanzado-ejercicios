#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int op,v[TOPE],ce=0;
    printf("\n\n CARGAR Y MOSTRAR VECTOR \n");
    op=menu();
    while(op!=3)
        {
        switch(op)
            {
            case 1: ce=cargar_vector(v,TOPE,ce);
                    break;
            case 2: mostrar_vector(v,TOPE,ce);
                    break;
            }
        op=menu();
        }
    printf("\n\n\t\t\t\t\t Fin del programa.. \a\a\n\n");
    getch();
    return 0;
    }
