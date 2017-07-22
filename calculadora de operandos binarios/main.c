#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char op;
    printf("\n\t\t *************************************");
    printf("\n\t\t * CALCULADORA DE OPERANDOS BINARIOS *");
    printf("\n\t\t *************************************");
    op=menu();
    while(op!='q')
        {
        switch(op)
            {
            case 's':sumar();
                     break;
            case 'r':restar();
                     break;
            case 'm':multiplicar();
                     break;
            case 'd':dividir();
                     break;
            }
        op=menu();
        }
    printf("\n\n\n\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
