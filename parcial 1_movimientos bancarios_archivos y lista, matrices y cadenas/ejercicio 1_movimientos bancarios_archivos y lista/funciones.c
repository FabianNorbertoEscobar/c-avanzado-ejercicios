#include "header.h"

int cuenta_valida(const char *s)
{
    unsigned acum=0;

    while(*s&&*s!='-')
    {
        acum+=A_NUMERO(*s);
        s++;
    }
    s++;

    while(acum/10!=0)
        acum=acum%10+acum/10;

    return acum==A_NUMERO(*s);
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

int str_cmp(const char *s1,const char *s2)
{
    while(*s1&&*s2&&*s1==*s2)
    {
        s1++;
        s2++;
    }
    return *s1-*s2;
}

int comparar_movimiento_e_importe(const void *v1,const void *v2)
{
    t_registro *e1=(t_registro*)v1,*e2=(t_registro*)v2;
    if(e1->movimiento==e2->movimiento)
        return e1->importe-e2->importe;
    return e1->movimiento-e2->movimiento;
}
