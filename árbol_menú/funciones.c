#include "header.h"

void cargar_dato(t_dato *d)
{
    printf("\n\n Ingrese dato (número): \t");
    scanf("%d",&d->numero);
}

void mostrar_dato(const t_dato *d)
{
    printf("\n\n DATO: \t %d \n",d->numero);
}

void mostrar_nodo(const void *v)
{
    t_dato *d=(t_dato*)v;
    printf("\t %d",d->numero);
}

int comparar_enteros(const void *v1,const void *v2)
{
    int *e1=(int*)v1,*e2=(int*)v2;
    return *e1-*e2;
}

int ingresa_nivel(void)
{
    int nivel,band=0;
    printf("\n\n Ingrese nivel (mayor o igual a -1): \n\n\t\a\a");
    do
    {
        if(band==1)
            printf("\n\n El nivel ingresado no es válido. Ingrese el nivel: \n\n\t");
        fflush(stdin);
        scanf("%d",&nivel);
        band=1;
    }
    while(nivel<-1);
    system("cls");
    return nivel;
}

int ingresa_altura(void)
{
    int altura,band=0;
    printf("\n\n Ingrese altura (mayor o igual a 0): \n\n\t\a\a");
    do
    {
        if(band==1)
            printf("\n\n La altura ingresada no es válida. Ingrese la altura: \n\n\t");
        fflush(stdin);
        scanf("%d",&altura);
        band=1;
    }
    while(altura<0);
    system("cls");
    return altura;
}
