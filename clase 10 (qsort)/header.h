#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define A_MAYUSCULA(x)  (((x)>='a'&&(x)<='z')?((x)-32):(x))

typedef struct
    {
    int dni;
    char apellido[20];
    char nombre[25];
    int edad;
    }t_persona;

typedef int(*t_cmp)(const void*,const void*);

int comparar_int(const void*,const void*);
int comparar_float(const void*,const void*);
int comparar_char(const void*,const void*);
int comparar_string(const void*,const void*);
int comparar_apellido_personas(const void*,const void*);
int comparar_nombre_personas(const void*,const void*);
int comparar_dni_personas(const void*,const void*);
int comparar_edad_personas(const void*,const void*);
int str_icmp(const char*,const char*);
