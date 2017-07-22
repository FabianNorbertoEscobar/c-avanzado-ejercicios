#include "header.h"

int main()
{
    int mat1[FIL][COL] = {{2,5,7,1},{3,4,1,7},{6,1,4,5},{1,6,3,2}};
    /*
    int mat2[FIL2][COL2] = {{1,2,3},{4,5,6}};
    int matRes[FIL][COL2] = {{0,0,0},{0,0,0},{0,0,0}};

    trianguloSuperiorDerecho(mat,FIL,COL);
    trianguloSuperiorIzquierdo(mat,FIL,COL);
    trianguloInferiorIzquierdo(mat,FIL,COL);
    trianguloInferiorDerecho(mat,FIL,COL);

    trianguloSuperiorDerechoSD(mat,FIL,COL);
    trianguloSuperiorIzquierdoSD(mat,FIL,COL);
    trianguloInferiorIzquierdoSD(mat,FIL,COL);
    trianguloInferiorDerechoSD(mat,FIL,COL);
    */

    if(esSimetrica2(mat1,FIL,COL))
        printf("\n  Es simetrica");
    else
        printf("\n  No es simetrica");

    printf("\n");
    return 0;
}
