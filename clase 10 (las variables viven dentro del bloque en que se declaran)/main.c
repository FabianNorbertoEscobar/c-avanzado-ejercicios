#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("\n\n Las variables solo viven dentro del bloque en que se declaran \n\n");
    int x=4,i=4;
    for(i=0;i<10;i++)
    {
        int x,j;
        x=i;
        for(j=9;j>0;j--)
        {
            int x;
            x=j;
            printf("\n x= %d \t (dentro del segundo for, interno al primer for)",x);
        }
        printf("\n\n x= %d \t (dentro del primer for) \n",x);
    }
    printf("\n\n x= %d \t (fuera de ambos for) \n\n",x);

    system("pause");
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    return 0;
}
