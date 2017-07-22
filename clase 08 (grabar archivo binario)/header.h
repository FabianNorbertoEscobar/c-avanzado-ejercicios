#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#define DATO_VALIDO(x,li,ls)    ((x)>=(ls)&&(x)<=(ls))
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
char *modo_de_apertura();
void cargar_archivo(FILE**);
void ingresar_registro(t_persona*);
int fecha_valida(t_fecha);
int cant_dias_mes(int,int);
int bisiesto(int);
size_t str_len(const char*);
char *str_cpy(char*,const char*);
