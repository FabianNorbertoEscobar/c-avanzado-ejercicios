#include "header.h"
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
float angulo_entre_manecillas(int h,int m)
    {
    int beta,theta;
    float alfa,phi;
    beta=m*6;
    theta=h*30;
    alfa=m*0.5;
    phi=(theta+alfa)-beta;
    return fabs(phi);
    }
float sexagesimales_a_radianes(float sex)
    {
    float rad;
    rad=sex*0.017453;
    return fabs(rad);
    }

