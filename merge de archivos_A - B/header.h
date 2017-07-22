#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     MENOR       -1
#define     IGUAL       0
#define     MAYOR       1

typedef struct
    {
    int dni;
    char apellido[25];
    char nombre[30];
    int edad;
    double sueldo;
    }t_persona;

void A_menos_B_de_archivos_binarios(FILE*,FILE*,FILE*);
int comparacion_de_registros(t_persona*,t_persona*);
int str_cmp(const char*,const char*);
void mostrar_archivo_binario(FILE*);

