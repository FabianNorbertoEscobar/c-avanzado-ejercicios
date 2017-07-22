#include "header.h"
void *mem_ccpy(void *destino,const void *origen,int c,size_t cant)
    {
    int marca=0;
    while(cant--&&!marca)
        {
        *(char*)destino=*(char *)origen;
        if(*(char*)destino==(char)c)
            marca++;
        else
            (char*)destino++;
            (char*)origen++;
        }
    *(char*)destino='\0';
    return (*(char*)destino==(char)c&&marca)?(char*)destino+1:NULL;
    }
