#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<locale.h>

#define CUADRADO(x)     ((x)*(x))

#define CUBO(x)     (CUADRADO(x)*(x))

#define MAYOR(x,y)  ((x)>(y)?(x):(y))

#define MENOR(x,y)  if((x)<(y))     \
                        menor=(x);      \
                    else        \
                        menor=(y)

#define ABS(x)     ((x)>0)?(x):(-(x))

#define PARTE_ENTERA(x)     ((int)(x))

#define PARTE_DECIMAL(x)    ((x)-PARTE_ENTERA(x))

#define FACTORIAL(x)    fact=1;    \
                        for(i=1;i<=(x);i++)   \
                            fact*=i

#define INTERCAMBIO(x,y)    aux=(x);    \
                            (x)=(y);    \
                            (y)=aux;

#define REDONDEO(x)     (((x)-(int)(x))>0.5?((int)(x)+1):((int)(x)))

#define REDONDEO_2(x)   ((int)((x) + 0.5))

#define ES_BISIESTO(x)  ((((x)%4==0&&(x)%100!=0)||((x)%400==0)))

#define ES_BLANCO(x)    ((x)==32)

#define ES_DIGITO(x)    (((x)>='0'&&(x)<='9'))

#define ES_LETRA(x)     ((x)>='A'&&(x)<='Z')||((x)>='a'&&(x)<='z')

#define ES_MAYUSCULA(x)     ((x)>='A'&&(x)<='Z')

#define ES_MINUSCULA(x)     ((x)>='a'&&(x)<='z')

#define A_MAYUSCULA(x)  (((x)>='a'&&(x)<='z')?((x)-32):(x))

#define A_MINUSCULA(x)  (((x)>='A'&&(x)<='Z')?((x)+32):(x))

#define REDONDEO_A_DOS_DECIMALES(x)     (int)(x*100)/100.0

#define REDONDEO_A_N_DECIMALES(x,n)     floor(x*(pow(10,n))+0.5)/pow(10,n)
