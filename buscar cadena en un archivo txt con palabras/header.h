#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#define A_MAYUSCULA(x)  (((x)>='a'&&(x)<='z')?((x)-32):(x))

void busqueda_de_palabra(FILE*,char*);
char *leer_cadena(FILE*);
char *str_upr(char*);
char *str_cpy(char*,const char*);
size_t str_len(const char*);
int str_ncmp(const char*,const char*,size_t);
char *str_str(const char*,const char*);
