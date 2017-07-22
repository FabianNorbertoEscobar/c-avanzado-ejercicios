#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int x;
    float tol,exp;
    printf("\n\t\t FUNCIÓN EXPONENCIAL \n\n");
    printf("\n Aproximación mediante el polinomio de Taylor \n");
    printf("\n Ingrese un número entero para calcular su exponencial: \n\n\t\t");
    scanf("%d",&x);
    do
        {
        printf("\n Ingrese la tolerancia de error permitida: \n\n\t\t");
        scanf("%f",&tol);
        }
    while(tol<=0);//no es lógico que sea negativa y cero tampoco porque no habría error y estoy aproximando
    exp=exponencial(x,tol);
    printf("\n La exponencial de %d es %f \n\n",x,exp);
    getch();
    return 0;
    }
