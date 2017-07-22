#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<math.h>
#define TOPE 50
#define ES_NUMERO(x) ((x)>='0'&&(x)<='9')
#define A_MINUSCULA(x)  (((x)>='A'&&(x)<='Z')?((x)+32):(x))

double mi_atof(char*);
int mi_atoi(char*);
