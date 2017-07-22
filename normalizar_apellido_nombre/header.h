#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

#define ES_BLANCO(x)    ((x)==32)
#define ES_COMA(x)      ((x)==',')
#define ES_LETRA(x)     (((x)>='A'&&(x)<='Z')||((x)>='a'&&(x)<='z'))
#define ES_MAYUSCULA(x)     ((x)>='A'&&(x)<='Z')
#define ES_MINUSCULA(x)     ((x)>='a'&&(x)<='z')

#define A_MAYUSCULA(x)  (((x)>='a'&&(x)<='z')?((x)-32):(x))
#define A_MINUSCULA(x)  (((x)>='A'&&(x)<='Z')?((x)+32):(x))

char *str_cpy(char*,const char*);
void normalizar_apellido_nombre(char*);
