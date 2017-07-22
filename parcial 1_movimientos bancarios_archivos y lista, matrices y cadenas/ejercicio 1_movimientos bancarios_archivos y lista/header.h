#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#include "lista_simplemente_enlazada.h"

#define         A_NUMERO(x)         ((x)-'0')

typedef struct
    {
    char cuenta[9];
    char movimiento;
    float importe;
    }t_registro;

int cuenta_valida(const char*);
char *str_cpy(char*,const char*);
int str_cmp(const char*,const char*);
int comparar_movimiento_e_importe(const void*,const void*);
