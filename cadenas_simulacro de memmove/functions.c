#include "header.h"
void *mem_move(void *destino,const void *origen,size_t n)
    {
    void *s=destino;
    if(origen>=destino)
        while(n--)
            {
            *(char*)destino=*(char *)origen;
            (char*)destino++;
            (char*)origen++;
            }
    else
        {
        (char*)destino+(n-1);
        (char*)origen+(n-1);
        while(n--)
            {
            *(char*)destino=*(char *)origen;
            (char*)destino--;
            (char*)origen--;
            }
        }
    *(char*)destino='\0';
    return s;
    }
