#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define REDONDEO_1(x)     ((((x)-0.5)<(int)(x))?(int)(x):(int)((x)+1))

#define REDONDEO_2(x)     (((x)-(int)(x))>=0.5?((int)(x)+1):((int)(x)))

#define REDONDEO_3(x)   ((int)((x) + 0.5))

int menor(int*,int*);

#define MENOR(x,y)      ((*(x)<*(y))?*(x):*(y))

void intercambio(int*,int*);

#define INTERCAMBIO(x,y)    int aux;    \
                            aux=*x;     \
                            *x=*y;      \
                            *y=aux;
