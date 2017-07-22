#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double promedio(int i,...);

int main()
{
    // variables
    double w,x,y,z;
    w=37.5;
    x=22.5;
    y=1.7;
    z=10.2;
    printf("\n PROMEDIO_lista de argumentos de longitud variable \n");
    printf("\n\n w: %.2f    x: %.2f     y: %.2f     z: %.2f \n",w,x,y,z);

    // promedios
    printf("\n promedio(2,w,x): %.2f \n",promedio(2,w,x));
    printf("\n promedio(3,w,x,y): %.2f \n",promedio(3,w,x,y));
    printf("\n promedio(4,w,x,y,z): %.2f \n",promedio(4,w,x,y,z));

    return 0;
}

double promedio(int i,...)
{
    double suma=0; // inicializo la sumatoria de los argumentos
    int j;  // contador para seleccionar argumentos

    va_list puntero; // almacena la información necesaria para va_start y para va_end
    va_start(puntero,i); // inicializa el objeto de tipo va_list
    // va_start utiliza el objeto puntero del tipo va_list para saber dónde comienza la lista de argumentos de longitud variable

    //procesa la lista de argumentos de longitud variable
    for(j=1;j<=i;j++)
        suma+=va_arg(puntero,double);

    va_end(puntero); // limpia la lista de argumentos de longitud variable

    return suma/i; // retorna el promedio
}
