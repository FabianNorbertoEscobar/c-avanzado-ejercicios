#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n \t BUSCAR PALABRA EN UN TXT DE PALABRAS \a\a");

    FILE *pf;
    pf=fopen("palabras.txt","rt");
    if(!pf)
        {
        printf("\n\n Error al leer el fichero de texto \n\n Programa evacuado \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    printf("\n\n Ingrese una cadena (de hasta 6 caracteres, \n (el archivo tiene palabras de esa longitud) \n para ser buscada en el archivo de texto \"palabras.txt\" \n\n\t");
    printf("\n Si la cadena no está en mayúscula, será convertida, \n ya que las palabras del archivo están en mayúscula \n\n\t\t");
    char cadena[6];
    gets(cadena);
    printf("\n Cadena a buscar: %s \n",cadena);
    printf("\n\n Si la cadena es subcadena del archivo se le informará \n");
    printf("\n Comienzo de los resultados de la búsqueda \n\n");
    busqueda_de_palabra(pf,str_upr(cadena));

    printf("\n\n \t\t\t\t\t Fin de los resultados de la búsqueda \n");
    getch();
    printf("\n\n Se ha cerrado el archivo \"palabras.txt\" utilizado \"palabras.txt\"");
    fclose(pf);
    getch();

    printf("\n\n \t\t\t\t\t  Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }


