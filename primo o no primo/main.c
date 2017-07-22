#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n;
    printf("\n PRIMO O NO PRIMO \n");
    do
        {
        printf("\n\n Ingrese un número natural:\n\n\t\t");
        scanf("%d",&n);
        }
    while(n<1);
    if(primo_o_no_primo(n))
        printf("\n\n El número es primo \n\n");
    else
        printf("\n\n El número no es primo \n\n");
    getch();
    return 0;
    }
