#include "header.h"

int comparar_int(const void *arg1,const void *arg2)
    {
    int *e1=(int*)arg1,*e2=(int*)arg2;
    return *e1-*e2;
    }
