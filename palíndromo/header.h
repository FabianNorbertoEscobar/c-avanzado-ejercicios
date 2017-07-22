#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define TOPE 50
#define ES_MAYUSCULA(x)     ((x)>='A'&&(x)<='Z')
#define A_MINUSCULA(x)  (((x)>='A'&&(x)<='Z')?((x)+32):(x))
size_t str_len(const char*);
int es_palindromo(char*);

