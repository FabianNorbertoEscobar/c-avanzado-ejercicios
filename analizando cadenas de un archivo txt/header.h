#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define A_MAYUSCULA(x)  (((x)>='a'&&(x)<='z')?((x)-32):(x))
#define ES_VOCAL(x)    ((x)=='A'||(x)=='E'||(x)=='I'||(x)=='O'||(x)=='U'||(x)=='a'||(x)=='e'||(x)=='i'||(x)=='o'||(x)=='u')
#define ES_DIGITO(x)    (((x)>='0'&&(x)<='9'))
#define ES_BLANCO(x)    ((x)==' ')
#define ES_SIGNO(x)     ((x)=='+'||(x)=='-')

char *leer_cadena(FILE*);
char *str_cpy(char*,const char*);
size_t str_len(const char*);
int es_uniletra(char*);
int es_de_cant_par_de_letras(char*);
int empieza_con_n(char*,char);
int empieza_con_prefijo(char*,char*);
int tiene_mas_de_3_vocales(char*);
int empieza_y_termina_con_vocal(char*);
int contiene_digitos(char*);
int tiene_solo_numeros(char*);
int es_palindromo(char*);
