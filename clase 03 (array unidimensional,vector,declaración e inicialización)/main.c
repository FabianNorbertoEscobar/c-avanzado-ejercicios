#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int x[10];
    int i;
    x[23]=3;//C deja que se guarde el valor pero está sobreescribiendo en memoria y podría llegar a borrar algo importante
    //x[23]={3};//da error ya que no coinciden las dimensiones del tamaño y del vector y la declaración del mismo
    int v1[5]={1,55,3,4,5};//reserva y asigna memoria para las 5 variables
    int v2[]={1,9,3,4,5};//inicializado-->>>el complilador reserva el espacio mínimo necesario para almacenar esas variables
    //int v3[5]={1,2,,4,5};//error:--->>>si empiezo a dar valores, tengo que hacerlo para todas las posiciones
    int v4[5]={11,12,13,14,15,60,70};// C no hace control de overflow.. el 60 y el 70 no los almacena..
    //en este caso, el compilador de Borland tira error porque no sabe si descartar los valores que no caben...
    //... en esa dimensión, o si guardarlos en las posiciones necesarias
    //por eso da error, y que lo decida el programador
    //en cambio el compilador de CodeBlocks no da error ni warning, y te lo acepta.. guarda hasta donde se lo indicaste
    //y el resto lo descarta.. no se hace responsable de los errores del programador
    //*******>>>>> el compilador asigna memoria de manera inversa.. desde lo último que fue declarado hasta lo primero
    //por eso, cuando nosotros mostramos posiciones de vectores que no son válidas nos está mostrando lo que continuá, que será
    //contenido de cualquier otra variable, en este caso vectores
    //por ejemplo, la primera posición afuera de v2 es la primera posición adentro de v1
    //también, la primera posición afuera de v4 es la primera posición adentro de v2
    // además, la primera posición antes del vector 2, es la última posición adentro del vector 4
    int v5[5]={};//rellena todo con cero
    int v6[5]={1,'b',3,'d'};//en la segunda y la cuarta posición guarda los ascii de los caracteres declarados y..
    //.. la quinta posición la rellena con cero
    int v7[5]={1,2};//guarda el 1 y el 2 en las dos primeras posiciones, y el resto rellena con cero
    //int v21[];//error!!!--->>> falta el tamaño
    v2[5] = 88;//por prueba nomás
    printf("\n VECTORES \n");
    printf("\n\n vector x \n");
    for(i=0;i<23;i++)
        {
        printf("%d \t", x[i]);
        }
    printf("\n tamaño del vector x: %d",sizeof(x));
    printf("\n contenido en posición no válida de x: %d",x[23]);
    printf("\n\n vector v1 \n");
    for(i=0;i<5;i++)
        {
        printf("%d \t", v1[i]);
        }
    printf("\n tamaño del vector v1: %d",sizeof(v1));
    printf("\n\n vector v2 \n");
    for(i=0;i<5;i++)
        {
        printf("%d \t", v2[i]);
        }
    printf("\n tamaño del vector v2: %d",sizeof(v2));
    printf("\n\n vector v4 \n");
    for(i=0;i<7;i++)
        {
        printf("%d \t", v4[i]);
        }
    printf("\n tamaño del vector v4: %d",sizeof(v4));//reservó 20 bytes, 4 para cada una de las 5 variables
    printf("\n\n vector v5 \n");
    for(i=0;i<5;i++)
        {
        printf("%d \t", v5[i]);
        }
    printf("\n tamaño del vector v5: %d",sizeof(v5));
    printf("\n\n vector v6 \n");
    for(i=0;i<5;i++)
        {
        printf("%d \t", v6[i]);
        }
    printf("\n tamaño del vector v6: %d",sizeof(v6));
    printf("\n\n vector v7 \n");
    for(i=0;i<5;i++)
        {
        printf("%d \t", v7[i]);
        }
    printf("\n tamaño del vector v7: %d \n\n",sizeof(v7));
    //printf("\n %d",v4[5]);
    //printf("\n %d",v4[6]);
    getch();
    return 0;
    }
