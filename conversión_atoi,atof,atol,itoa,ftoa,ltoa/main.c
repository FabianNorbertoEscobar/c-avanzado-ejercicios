#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cad[5];
    printf("\n\n Conversiones de tipo");
    printf("\n -------------------- \n\n");

    printf("\n Cadena: \t %s \t---ATOI--->> \t Entero: \t %d \n","-67489jknf",atoi("-67489"));
    printf("\n Cadena: \t %s \t---ATOF--->> \t Flotante: \t %f \n","-5.0326e5",atof("-5.0326e5"));
    printf("\n Cadena: \t %s \t---ATOL--->> \t Entero largo: \t %li \n","+76454865fsg",atol("+76454865"));

    printf("\n Entero: \t %d \t---ITOA--->> \t Cadena: \t %s \n",6545,itoa(6545,cad,10));
    printf("\n Entero: \t %d \t---ITOA--->> \t Cadena (en binario): \t %s \n",6545,itoa(6545,cad,2));
    printf("\n Entero: \t %d \t---ITOA--->> \t Cadena (en hexadecimal): \t %s \n",3578,itoa(3578,cad,16));
    //printf("\n Flotante: \t %f \t---FTOA--->> \t Cadena: \t %s \n",0.1455454e7,ftoa(0.1455454e7,cad,10));
    printf("\n Entero largo: \t %f \t---LTOA--->> \t Cadena: \t %s \n",+0.1455454e7,ltoa(+0.1455454e7,cad,10));

    getch();
    return 0;
    }
