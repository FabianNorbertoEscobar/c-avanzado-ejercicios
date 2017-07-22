#include "header.h"

int main()
{
    char texto[TAM];
    FILE *archivo;

    setlocale(LC_CTYPE,"Spanish");

    archivo=fopen("texto.txt","wt");
    if(!archivo)
    {
        printf("\n\n Sin memoria para archivo. Ejecucuión de programa detenida. \n\n\a\a");
        exit(EXIT_FAILURE);
    }

    printf("\n Convertir cada caracter de un texto a su caracter inmediato posterior: \n");

    printf("\n Ingrese el texto: \n\n");
    ingresar_texto(texto);

    system("cls");

    printf("\n Texto ingresado: \n\n");
    mostrar_texto(texto);

    printf("\n Texto convertido: \n\n");
    mostrar_texto_convertido(texto);

    grabar_archivo(texto,archivo);
    printf("\n\n Se ha grabado exitosamente el archivo texto.txt \n");

    getch();
    return 0;
}
