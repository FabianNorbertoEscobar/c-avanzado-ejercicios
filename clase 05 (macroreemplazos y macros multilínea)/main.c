#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int x=5,y=3,fact,i,aux,blanco=' ';
    printf("\n MACROS \n\n");
    printf("\n El cuadrado de 3 es: %d \n",CUADRADO(2+1));
    printf("\n El cubo de 3 es: %d \n",CUBO(2+1));
    printf("\n El mayor entre 5 y 3 es: %d \n",MAYOR(x,y));
    int menor;
    MENOR(x,y);
    printf("\n El menor entre 5 y 3 es: %d \n",menor);
    printf("\n El valor absoluto de -2 es: %d \n",ABS(-2));
    printf("\n La parte entera de %f es: %d \n",2.35,PARTE_ENTERA(2.35));
    printf("\n La parte decimal de %f es: %f \n",2.35,PARTE_DECIMAL(2.35));   FACTORIAL(5);
    printf("\n El factorial de %d es: %d \n",5,fact);
    printf("\n Antes del intercambio: x=%d \t y=%d \n",x,y);
    INTERCAMBIO(x,y);
    printf("\n Después del intercambio: x=%d \t y=%d \n",x,y);
    printf("\n El redondeo de %f es: %d \n",3.75,REDONDEO(3.75));
    printf("\n El redondeo de %f es: %d \n",3.25,REDONDEO_2(3.25));
    printf("\n El año %d %s bisiesto \n",2016,ES_BISIESTO(2016)?"es":"no es");
    printf("\n El caracter \"%c\" %s blanco \n",blanco,ES_BLANCO(blanco)?"es":"no es");
    printf("\n El caracter \"%d\" %s dígito \n",9,ES_DIGITO('9')?"es":"no es");
    printf("\n El caracter \"%c\" %s letra \n",'f',ES_LETRA('f')?"es":"no es");
    printf("\n El caracter \"%c\" %s maýuscula \n",'m',ES_MAYUSCULA('m')?"es":"no es");
    printf("\n Entonces, paso %c a mayúscula: %c \n",'m',A_MAYUSCULA('m'));
    printf("\n El caracter \"%c\" %s maýuscula \n",'Y',ES_MINUSCULA('Y')?"es":"no es");
    printf("\n Entonces, paso %c a minúscula: %c \n",'Y',A_MINUSCULA('Y'));
    float a=5.666666;
    float b=a;
    printf("\n El número %f redondeado a 2 decimales es %f \n",a,REDONDEO_A_DOS_DECIMALES(a));
    printf("\n El número %f redondeado a %d decimales es %f \n",b,4,REDONDEO_A_N_DECIMALES(b,4));
    getch();
    return 0;
    }
