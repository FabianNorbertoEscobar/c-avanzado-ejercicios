#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,caras,secas;
    caras=secas=0;

    enum estados{CARA,SECA};

    printf("\n\n CARA O SECA \n");

    printf("\n Se arroja una moneda 100 veces y los resultados son: \n");

    srand(time(NULL));
    for(i=0;i<100;i++)
    {
        if(rand()%2==CARA)
            caras++;
        else
            secas++;
    }

    printf("\n CARAS: %d \t SECAS: %d \n",caras,secas);
    return 0;
}
