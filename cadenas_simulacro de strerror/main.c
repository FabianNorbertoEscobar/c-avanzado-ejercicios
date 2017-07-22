#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int errnum;
    printf("\n\n MENSAJES DE ERROR \n\n");
    for(errnum=0;errnum<44;errnum++)
        printf("\n ERROR %d = %s\n",errnum,str_error(errnum));
    printf("\n ERRORES en adelante ídem error 43 \n\n");
    getch();
    return 0;
    }
