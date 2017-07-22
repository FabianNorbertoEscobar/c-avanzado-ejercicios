#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float x,tol,sen;
    printf("\n\t\t FUNCIÓN SENO \n");
    printf("\n Aproximación mediante el polinomio de Taylor \n");
    printf("\n Ingrese un número real para calcular su seno: \n\n\t\t");
    scanf("%f",&x);
    do
        {
        printf("\n Ingrese la tolerancia de error permitida: \n\n\t\t");
        scanf("%f",&tol);
        }
    while(tol<=0);
    sen=seno(x,tol);
    printf("\n El seno de %f es %f \n\n",x,sen);
    getch();
    return 0;
    }
