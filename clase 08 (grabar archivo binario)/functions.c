#include "header.h"
char *modo_de_apertura()
    {
    int op,band=0;
    char *modo;
    printf("\n Ingrese modo de apertura: \n 1- write \t 2- append \n\n\t Opción: \t");
    do
        {
        if(band==1)
            printf("\n\n La opción ingresada es incorrecta. Reingrésela: \t");
        scanf("%d",&op);
        band=1;
        }
    while(!DATO_VALIDO(op,1,2));
    if(op==1)
        modo="wb";
    else
        modo="ab";
        return modo;
    }
void cargar_archivo(FILE **pf)
    {
    t_persona per;
    ingresar_registro(&per);
    if(per.dni==0)
        return;
    fwrite(&per,sizeof(t_persona),1,*pf);
    printf("\n Registro grabado \n\n");
    cargar_archivo(pf);
    }
void ingresar_registro(t_persona *per)
    {
    int band;
    printf("\n\n CARGUE UN REGISTRO \n");
    printf("\n (para dejar de cargar registros, ingrese dni=0) \n");

    band=0;
    printf("\n Ingrese el DNI: \t");
    do
        {
        if(band==1)
            printf("\n El dato ingresado es inválido. Reingréselo: \n\n\t\a\a");
        scanf("%d",&per->dni);
        band=1;
        }
    while(per->dni<0);
    if(per->dni==0)
        return;

    band=0;
    printf("\n Ingrese el nombre y apellido: \n\n\t");
    do
        {
        if(band==1)
            printf("\n El campo ingresado está vacío. Reingréselo: \n\n\t\a\a");
        fflush(stdin);
        gets(per->nomb);
        fflush(stdin);
        band=1;
        }
    while(str_len(per->nomb)==0);

    band=0;
    printf("\n Ingrese la edad: \t");
    do
        {
        if(band==1)
            printf("\n La edad ingresada es inválida. Reingrésela: \n\n\t\a\a");
        scanf("%d",&per->edad);
        band=1;
        }
    while(per->edad<0);

    band=0;
    printf("\n Ingrese la fecha de nacimiento en formato dd/mm/aaaa: \n\n\t");
    do
        {
        if(band==1)
            printf("\n La fecha ingresada es inválida. Reingrésela: \n\n\t\a\a");
        scanf("%d/%d/%d",&per->f_nac.d,&per->f_nac.m,&per->f_nac.a);
        band=1;
        }
    while(!fecha_valida(per->f_nac));
    }
int fecha_valida(t_fecha f)
    {
    return (f.a>=1600&&f.m>=1&&f.m<=12&&f.d>=1&&f.d<=cant_dias_mes(f.m,f.a))?1:0;
    }
int cant_dias_mes(int m,int a)
    {
    int dias[]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (m==2)?28+bisiesto(a):dias[m-1];
    }
int bisiesto(int a)
    {
    return ((a%4==0&&a%100!=0)||a%400==0)?1:0;
    }
size_t str_len(const char *s)
    {
    size_t cont=0;
    while(*s)
        {
        cont++;
        s++;
        }
    return cont;
    }
char *str_cpy(char *destino,const char *origen)
    {
    char *s=destino;
    while(*origen)
        {
        *destino=*origen;
        destino++;
        origen++;
        }
    *destino='\0';
    return s;
    }
