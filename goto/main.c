#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    goto msj;

    return 0;

    msj: printf("Bye world!\n");
    return 0;
}
