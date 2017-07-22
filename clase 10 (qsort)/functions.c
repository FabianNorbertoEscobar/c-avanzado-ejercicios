#include "header.h"

int comparar_int(const void *arg1,const void *arg2)
    {
    int *e1=(int*)arg1,*e2=(int*)arg2;
    return *e1-*e2;
    }

/*
int comparar_int(const void *arg1,const void *arg2)
    {
    if(*(int*)arg1<*(int*)arg2)
        return -1;
    else
        if(*(int*)arg1>*(int*)arg2)
            return 1;
        else
            return 0;
    }
*/

int comparar_float(const void *arg1,const void *arg2)
    {
    if(*(float*)arg1<*(float*)arg2)
        return -1;
    else
        if(*(float*)arg1>*(float*)arg2)
            return 1;
        else
            return 0;
    }

int comparar_char(const void *arg1,const void *arg2)
    {
    if(*(char*)arg1<*(char*)arg2)
        return -1;
    else
        if(*(char*)arg1>*(char*)arg2)
            return 1;
        else
            return 0;
    }

int comparar_string(const void *arg1,const void *arg2)
    {
    return str_icmp((char*)arg1,(char*)arg2);
    }

int comparar_apellido_personas(const void *arg1,const void *arg2)
    {
    return str_icmp(((t_persona*)arg1)->apellido,((t_persona*)arg2)->apellido);
    }

int comparar_nombre_personas(const void *arg1,const void *arg2)
    {
    return str_icmp(((t_persona*)arg1)->nombre,((t_persona*)arg2)->nombre);
    }

int comparar_dni_personas(const void *arg1,const void *arg2)
    {
    return ((t_persona*)arg1)->dni-((t_persona*)arg2)->dni;
    }

int comparar_edad_personas(const void *arg1,const void *arg2)
    {
    return ((t_persona*)arg1)->edad-((t_persona*)arg2)->edad;
    }

int str_icmp(const char *s1,const char *s2)
    {
    while(A_MAYUSCULA(*s1)==A_MAYUSCULA(*s2)&&*s1&&*s2)
        {
        s1++;
        s2++;
        }
    return A_MAYUSCULA(*s1)-A_MAYUSCULA(*s2);
    }
