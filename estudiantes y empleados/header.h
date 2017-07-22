#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>

#define SIN_MENSAJE     0
#define CON_MENSAJE     1

#define VERDADERO   1
#define FALSO       0

#define MENOR   -1
#define IGUAL   0
#define MAYOR   1

typedef struct
    {
    int dni;
    char apellido[20];
    char nombre[30];
    double sueldo;
    }t_empleados;

typedef struct
    {
    int dni;
    char apellido[20];
    char nombre[30];
    float promedio;
    }t_estudiantes;

int abrir_archivo(FILE**,const char*,const char*,int);
void mostrar_archivo_empleados(FILE*);
void mostrar_archivo_estudiantes(FILE*);
void modificar_archivo_empleados(FILE*,FILE*);
int comparacion_de_registros(t_empleados*,t_estudiantes*);
int str_cmp(const char*,const char*);
