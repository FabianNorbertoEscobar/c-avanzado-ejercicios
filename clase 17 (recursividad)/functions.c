#include "header.h"

void cadena_encolumnada(char *s)
{
    if(*s)
    {
        printf("\n\t %c",*s);
        cadena_encolumnada(s+1);
    }
}

void cadena_encolumnada_al_reves(char *s)
{
    if(*s)
    {
        cadena_encolumnada_al_reves(s+1);
        printf("\n\t %c",*s);
    }
}

void cadena_encolumnada_doble_con_repeticion(char *s)
{
    if(*s)
    {
        printf("\n\t %c",*s);
        cadena_encolumnada_doble_con_repeticion(s+1);
        printf("\n\t %c",*s);
    }
}

void cadena_encolumnada_doble_sin_repeticion(char *s)
{
    if(*s)
    {
        printf("\n\t %c",*s);
        cadena_encolumnada_doble_sin_repeticion(s+1);
        if(*(s+1))
            printf("\n\t %c",*s);
    }
}

void cadena_en_triangulo_1(char *s)
{
    if(*s)
    {
        printf("\n\t %s",s);
        cadena_en_triangulo_1(s+1);
    }
}

void cadena_en_triangulo_2(char *s)
{
    if(*s)
    {
        cadena_en_triangulo_2(s+1);
        printf("\n\t %s",s);
    }
}

void cadena_en_triangulo_3(char *s)
{
    char *inicio=s;
    int i=0;
    while(*s)
    {
        i++;
        s++;
    }
    s=inicio;
    cadena_en_triangulo_3_recursiva(s,i);
}

void cadena_en_triangulo_3_recursiva(char *s,int i)
{
    char *inicio=s;
    if(*s&&i>0)
    {
        int j;
        printf("\n\t ");
        for(j=0;j<i;j++)
            {
                printf("%c",*s);
                s++;
            }
        s=inicio;
        cadena_en_triangulo_3_recursiva(s,i-1);
    }
}

void cadena_en_triangulo_4(char *s)
{
    char *inicio=s;
    int i=0;
    while(*s)
    {
        i++;
        s++;
    }
    s=inicio;
    cadena_en_triangulo_4_recursiva(s,i);
}

void cadena_en_triangulo_4_recursiva(char *s,int i)
{
    if(*s&&i>0)
    {
        cadena_en_triangulo_4_recursiva(s,i-1);
        int j;
        printf("\n\t ");
        for(j=0;j<i;j++)
            {
                printf("%c",*s);
                s++;
            }
    }
}

void numero_encolumnado(int n)
{
    if(n)
    {
        numero_encolumnado(n/10);
        printf("\n\t %d",n%10);
    }
}

void numero_encolumnado_al_reves(int n)
{
    if(n)
    {
        printf("\n\t %d",n%10);
        numero_encolumnado_al_reves(n/10);
    }
}

void numero_encolumnado_doble_con_repeticion(int n)
{
    if(n)
    {
        printf("\n\t %d",n%10);
        numero_encolumnado_doble_con_repeticion(n/10);
        printf("\n\t %d",n%10);
    }
}

void numero_encolumnado_doble_sin_repeticion(int n)
{
    if(n)
    {
        printf("\n\t %d",n%10);
        numero_encolumnado_doble_sin_repeticion(n/10);
        if(n/10)
            printf("\n\t %d",n%10);
    }
}

void numero_en_triangulo_1(int n)
{
    printf("\n\t %d",n);
    if(n/10)
        numero_en_triangulo_1(n/10);
}

void numero_en_triangulo_2(int n)
{
    if(n/10)
        numero_en_triangulo_2(n/10);
    printf("\n\t %d",n);
}

void cambio_de_base(int base,int n)
{
    if(n/base>0)
        cambio_de_base(base,n/base);
    printf("%d",n%base);
}

void caracter_en_triangulo(char c,int n)
{
    if(n>0)
    {
        printf("\n\t");
        int i;
        for(i=0;i<n;i++)
            printf("%c",c);
        caracter_en_triangulo(c,n-1);
    }
}

void caracter_en_triangulo_inverso(char c,int n)
{
    if(n>0)
    {
        caracter_en_triangulo_inverso(c,n-1);
        printf("\n\t");
        int i;
        for(i=0;i<n;i++)
            printf("%c",c);
    }
}

void caracter_en_doble_triangulo_con_repeticion(char c,int n)
{
    if(n>0)
    {
        int i;
        printf("\n\t");
        for(i=0;i<n;i++)
            printf("%c",c);
        caracter_en_doble_triangulo_con_repeticion(c,n-1);
        printf("\n\t");
        for(i=0;i<n;i++)
            printf("%c",c);
    }
}

void caracter_en_doble_triangulo_sin_repeticion(char c,int n)
{
    if(n>0)
    {
        int i;
        printf("\n\t");
        for(i=0;i<n;i++)
            printf("%c",c);
        caracter_en_doble_triangulo_sin_repeticion(c,n-1);
        if(n>1)
        {
            printf("\n\t");
            for(i=0;i<n;i++)
            printf("%c",c);
        }
    }
}

void mostrar_lista_ordenada(const t_lista *l)
{
    if(*l)
    {
        printf("\t %d",(*l)->dato.numero);
        mostrar_lista_ordenada(&(*l)->sig);
    }
}

void mostrar_en_reversa_lista_ordenada(const t_lista *l)
{
    if(*l)
    {
        mostrar_en_reversa_lista_ordenada(&(*l)->sig);
        printf("\t %d",(*l)->dato.numero);
    }
}
