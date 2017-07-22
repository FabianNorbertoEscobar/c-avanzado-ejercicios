#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     DATO_VALIDO(x,li,ls)        ((x)>=(li)&&(x)<=(ls))

#define ES_DIGITO(x)    (((x)>='0'&&(x)<='9'))
#define ES_BLANCO(x)    ((x)==' ')
#define ES_SIGNO(x)     ((x)=='+'||(x)=='-')
#define A_NUMERO(x)     ((x)-48)
#define MAYOR(x,y)  ((x)>(y)?(x):(y))

char *leer_cadena_numerica(FILE*);
char *str_cpy(char*,const char*);
int mi_atoi(char*);
int es_numero(char*);
size_t str_len(const char*);
int es_capicua(char*);
int es_multiplo_de_5(char*);
int es_multiplo_de_6(char*);
int es_multiplo_de_11(char*);
int es_mayor(char*,char*);
void nueva_cadena_numerica(FILE*,char*);
