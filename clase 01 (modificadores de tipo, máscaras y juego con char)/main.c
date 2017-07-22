#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");

    //el espacio reservado para una variable de un determinado tipo depende de la arquitectura de la computadora
    int x=2;//entero común
    short int sx=4;//usa la mitad de espacio en memoria
    long int lx=2;//usa el doble de espacio en memoria
    unsigned int ux=8;//el rango del entero se traslada a partir del cero para que se aproveche para positivos

    printf("\n\n MODIFICADORES DE TIPO Y MÁSCARAS \n");
    //las mascaras se anteceden por porcentaje y son las que indican la interpretacion de cada uno de los datos
    printf("\n Entero: %d \t Tamaño: %d \t Octal: %o \t Hexadecimal: %x",x,sizeof(x),x,x);
    printf("\n Short: %d \t Tamaño: %d \t Octal: %o \t Hexadecimal: %x",sx,sizeof(sx),sx,sx);
    printf("\n Long: %d \t Tamaño: %d \t Octal: %o \t Hexadecimal: %x",lx,sizeof(lx),lx,lx);
    printf("\n Unsigned: %d \t Tamaño: %d \t Octal: %o \t Hexadecimal: %x",ux,sizeof(ux),ux,ux);

    char c1,c2,c3,c4;
    //c1="a"; da warning porque no se puede guardar un string en un char---->>>>> reemplazo por la siguiente sentencia
    //las comillas simples indica un caracter, y las dobles un string
    c1='a';//caracter
    c2='A';//caracter
    c3='3';//caracter
    c4=3;//número-------->>>> su ascii es un corazón

    printf("\n\n JUEGOS CON CHAR \n");
    //los ca¿har guardan números enteros------>>>>>>>>>>> entonces pueden ser manipulados matemáticamente
    printf("\n Número \t\t Valor en Ascii \t\t Hexadecimal \n");
    printf("\n %d \t\t\t %c \t\t\t\t %x",c1,c1,c1);
    printf("\n %d \t\t\t %c \t\t\t\t %x",c2,c2,c2);
    printf("\n %d \t\t\t %c \t\t\t\t %x",c3,c3,c3);
    printf("\n %d \t\t\t %c \t\t\t\t %x",c4,c4,c4);

    int r;
    printf("\n\n Sumando dos char \n");
    r=c3+c4;//sumo dos char
    printf("\n c3=%d \t c4=%d \t Suma: x=c3+c4=%d",c3,c4,r);

    int s;
    printf("\n\n CONVERTIR CARACTER A NÚMERO \n");
    //s=c3-48; se debe restar 48 porque en el 48 comienzan a almacenarse los números
    s=c3-'0';// para no recordar el número 48, lo que se hace es restar el número ascii en que se almacena el cero-->>>>> ojo! no es el caracter nulo
    printf("\n c3=%d \t Convertido a: %d",c3,s);

    printf("\n\n");
    getch();
    }
