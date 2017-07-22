#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

typedef struct
    {
    int d,
        m,
        a;
    }t_fecha;
typedef struct
    {
    int dni;
    char nomb[30];
    int edad;
    t_fecha f_nac;
    }t_persona;

void longitud_variable_a_binario(FILE*,FILE*);
void longitud_fija_a_binario(FILE*,FILE*);
void leer_archivo(FILE**);
