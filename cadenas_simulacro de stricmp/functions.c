#include "header.h"
int str_icmp(const char *s1,const char *s2)
    {
    while(A_MAYUSCULA(*s1)==A_MAYUSCULA(*s2)&&*s1&&*s2)
        {
        s1++;
        s2++;
        }
    return A_MAYUSCULA(*s1)-A_MAYUSCULA(*s2);
    }
