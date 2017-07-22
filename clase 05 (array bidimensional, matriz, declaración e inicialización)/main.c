#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n MATRICES \n");
    //las matrices se almacenan de forma contigua en la memoria, como si fuese un vector
    //de hecho, se las interpreta como un vector de punteros
    int mat[3][2];//de esta manera se reserva memoria
    mat[0][0]=1;//así se le da un valor a la matriz en esa posición
    int mat1[3][2]={1,2,3,4,5,6};//tira warning: faltan las llaves delimitadoras de las columnas
    int mat2[3][2]={{1,2},{3,4},{5,6}};//esta es la forma ideal para inicializar las matrices
    int mat3[3][]={1,2,3,4,5,6};//error: no sabe cuando termina cada fila--->>>>>> necesita las columnas
    int mat4[3][]={{1,2},{3,4},{5,6}};//ídem caso anterior---->>>>> necesita las columnas
    int mat5[][2]={1,2,3,4,5,6}; //cada 2 elementos, 1 fila. determina la cantidad de filas en funcion de la cantidad de columnas
    int mat6[3][2]={1,2};//correcto.. da esos dos primeros valores y luego completa con ceros las demás posiciones
    //tira warnimg por la falta de los braces
    int mat7[][]={{1,2},{3,4}};
    int mat8[][]={1,2,3,4,5,6};//está muy mal
    int mat9[][]={1,,3};//no se pueden dejar espacios vacíos cuando se comienza a inicializar
    int mat10[3][2]={1,2,3,4,5,6,7,8};//los últimos dos valores los descarta, el resto los almacena correctamente
    //además tira warning porque faltan los braces
    //int mat11[3][2]={1};//warning: faltan los delimitadores de columnas
    int mat11[3][2]={{1}};//el compilador se contenta con esto.. asigna el uno a la primera posición y luego completa con ceros
    int mat12[][2] = {{1,2,3},{4,5,6},{8,9}};//no almacena y el valor 3 ni el 6 ya que no caben en la definición de las dimensiones
    //el resto de los números los almacena de manera correcta
    getch();
    return 0;
    }
