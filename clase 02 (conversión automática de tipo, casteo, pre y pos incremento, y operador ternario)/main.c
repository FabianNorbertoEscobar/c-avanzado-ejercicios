#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int x=5,y=2,r;
    float z;
    //la división entre dos números enteros siempre da un número entero
    //realizando esta división queda
    r=x/y;//2
    z=x/y;//2.00
    printf("\n división de enteros: r=%d \t z=%.2f \n",r,z);
    z=(float)x/y;//realizando este casteo sí va a quedar almacenado 2.5 porque se está convirtiendo el tipo
    printf("\n con casteo: \t z=%.2f \n",z);
    //------------------------------------------------------------------------------------------------------
    x=2.5;
    printf("\n conversión automática de tipo:\t x=%d",x);// conversión automática de tipo-------->>>>>2
    printf("\n visualización con máscara: \t x=%f",x);//------->>>>2.5     esto quiere decir que en algún lado en memoria quedaron almacenados los decimales
    //------------------------------------------------------------------------------------------------------
    x=5;
    y=5;
    int r1,r2;
    r1=++x;//preincremento: primero incrementa, luego asigna
    r2=y++;//posincremento: primero asigna y luego incrementa
    printf("\n\n preincremento y posincremento");
    printf("\n esto queda almacenado: x=%d \t y=%d \t r1=%d \t r2=%d \n",x,y,r1,r2);;
    //-------------------------------------------------------------------------------------------------------
    x=5;
    y=3;
    printf("\n operador ternario");//puede meterse dentro de cualquier instrucción
    //x>y?printf("\n x>y"):printf("\n x<y"); puedo usarlo de esta manera
    //oero es más óptimo escribir la siguiente sentencia:
    printf("\n x=5, y=3, mayor: %d \n",x>y?x:y);//me ahorro una impresión en oantalla
    getch();
    return 0;
    }
