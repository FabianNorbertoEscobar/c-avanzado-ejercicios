#include "header.h"
int cargar_array_float(float *v,int ce)
    {
    int band,n,i;
    printf("\n\n Proceda a la carga del vector. Usted cuenta con %d posiciones \n",ce);
    printf("\n\n Ingrese la cantidad de elementos que desea cargar: \t ");
    band=0;
    do
        {
        if(band==1)
            printf("\n\n El número ingresado es incorrecto. Reingréselo: \t");
        scanf("%d",&n);
        band=1;
        }
    while(!DATO_VALIDO(n,0,ce));
    for(i=1;i<=n;i++)
        {
        printf("\n Ingrese el flotante número %d :\t",i);
        scanf("%f",v);
        v++;
        }
    printf("\n\n La carga del array ha finalizado \n");
    return n;
    }
void mostrar_array_float(float *v,int ce)
    {
    int i;
    for(i=1;i<=ce;i++)
        {
        printf("\n Elemento número %d: \t %.4f",i,*v);
        v++;
        }
    }
int menu(void)
    {
    int band,op;
    printf("\n\n --------------------MENU-------------------- \n");
    printf("\n\n Seleccione alguna de las siguientes opciones \n");
    printf("\n 1- Buscar el mínimo elemento");
    printf("\n 2- Calcular el promedio de los valores de las posiciones pares");
    printf("\n 3- Mostrarlo en orden inverso");
    printf("\n 4- Salir");
    printf("\n\n \t\t\t\t\t Opción: \t");
    band=0;
    do
        {
        if(band==1)
            printf("\n\n La opción ingresada es incorrecta!!! Ingrese una opción: \t\a\a");
        scanf("%d",&op);
        band=1;
        }
    while(!DATO_VALIDO(op,1,4));
    printf("\n\n -------------------------------------------- \n");
    return op;
    }
void minimo(float *v,int ce)
    {
    float *min=v,*fin=v+ce;
    v++;
    while(v<fin)
        {
        if(*v<*min)
            min=v;
        v++;
        }
    printf("\n\n El mínimo elemento del array es: \t %.4f \n\n",*min);
    }
void promedio_valores_posiciones_pares(float *v,int ce)
    {
    float acum=0,*fin=v+ce;
    int cont=0;
    v++;
    while(v<fin)
        {
        acum+=*v;
        v+=2;
        cont++;
        }
    printf("\n\n El promedio de los valores de las posiciones pares del array es: \t %.4f \n\n",acum/cont);
    }
void mostrar_orden_inverso(float *v,int ce)
    {
    int i;
    v=v+ce-1;
    printf("\n\n ARRAY EN ORDEN INVERSO \n");
    for(i=ce;i>=1;i--)
        {
        printf("\n Elemento número %d: \t %.4f",i,*v);
        v--;
        }
    }
void grabar_en_archivo_binario(float *v,int ce,FILE *pf)
    {
    int i;
    t_registro reg;
    for(i=0;i<ce;i++)
        {
        reg.num=*v;
        fwrite(&reg,sizeof(t_registro),1,pf);
        v++;
        }
    }
void grabar_en_archivo_de_texto(float *v,int ce,FILE *pf)
    {
    int i;
    t_registro reg;
    for(i=0;i<ce;i++)
        {
        reg.num=*v;
        fprintf(pf,"%f\n",reg.num);
        v++;
        }
    }
