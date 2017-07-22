#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float x,tol,cos;
    printf("\n\t\t FUNCIÓN COSENO \n");
    printf("\n Aproximación mediante el polinomio de Taylor \n");
    printf("\n Ingrese un número real para calcular su coseno: \n\n\t\t");
    scanf("%f",&x);
    do
        {
        printf("\n Ingrese la tolerancia de error permitida: \n\n\t\t");
        scanf("%f",&tol);
        }
    while(tol<=0);
    cos=coseno(x,tol);
    printf("\n El coseno de %f es %f \n\n",x,cos);
    getch();
    return 0;
    }
