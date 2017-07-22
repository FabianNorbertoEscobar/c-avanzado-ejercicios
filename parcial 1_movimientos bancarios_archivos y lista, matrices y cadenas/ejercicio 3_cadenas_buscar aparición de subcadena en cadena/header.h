#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define A_MINUSCULA(x)  (((x)>='A'&&(x)<='Z')?((x)+' '):(x))

size_t str_len(const char*);
int str_ncmpi(const char*,const char*,size_t);
int ocurrencia_de_subcadena_en_cadena(const char*,const char*);
int ocurrencia_de_subcadena_en_cadena_optimizada(const char*,const char*);
