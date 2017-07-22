#include "header.h"
void *mem_cpy(void *destino,const void *origen,size_t n)
    {
    void *s=destino;
    while(n--)
        {
        *(char*)destino=*(char *)origen;
        destino++;
        origen++;
        }
    *(char*)destino='\0';
    return s;
    }
