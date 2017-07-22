#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define TAM     500

#define A_MAYUSCULA(x)  (((x)>='a'&&(x)<='z')?((x)-32):(x))

size_t str_len(const char*);
int str_icmp(const char*,const char*);
char *str_cpy(char*,const char*);
