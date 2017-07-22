#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float num;
    int redondeo;
    printf("\n\t PARTE ENTERA \n");
    printf("\n Ingrese un número real: \n\n\t\t");
    scanf("%f",&num);
    redondeo=parte_entera(num);
    printf("\n La parte entera de %.2f es %d \n\n",num,redondeo);
    getch();
    return 0;
    }
