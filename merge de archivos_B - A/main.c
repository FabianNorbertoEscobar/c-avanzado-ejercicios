#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 80");

    FILE *pf_A,*pf_B;

    printf("\n\n\t\t B - A DE ARCHIVOS");
    printf("\n\t\t ================= \n\n\a\a");

    printf("\n El archivo resultante B - A contendrá los registros \n que aparezcan en B pero no en A \n\n");
    getch();

    pf_A=fopen("personas_A.bin","rb");
    if(!pf_A)
        {
        printf("\n\n No se pudo leer el archivo \"personas_A.bin\" \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    pf_B=fopen("personas_B.bin","rb");
    if(!pf_B)
        {
        printf("\n\n No se pudo leer el archivo \"personas_B.bin\" \n\n\a\a");
        fclose(pf_A);
        exit(EXIT_FAILURE);
        }

    printf("\n\n\t\t ARCHIVO A \a\a");
    printf("\n\t\t ========= \n\n");
    mostrar_archivo_binario(pf_A);
    getch();

    printf("\n\n\t\t ARCHIVO B \a\a");
    printf("\n\t\t ========= \n\n");
    mostrar_archivo_binario(pf_B);
    getch();

    FILE *pf_B_menos_A;
    pf_B_menos_A=fopen("B - A.bin","wb");
    if(!pf_B_menos_A)
        {
        printf("\n\n No se pudo crear el archivo \"B - A.bin\" \n\n\a\a");
        fclose(pf_A);
        fclose(pf_B);
        exit(EXIT_FAILURE);
        }
    B_menos_A_de_archivos_binarios(pf_A,pf_B,pf_B_menos_A);
    printf("\n\n Se he generado el archivo \"B - A.bin\" \n\n\a\a");
    getch();

    fclose(pf_A);
    fclose(pf_B);
    fclose(pf_B_menos_A);

    pf_B_menos_A=fopen("B - A.bin","rb");
    if(!pf_B_menos_A)
        {
        printf("\n\n No se pudo abrir el archivo \"B - A.bin\" \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    printf("\n\n\t\t ARCHIVO B - A \a\a");
    printf("\n\t\t ============= \n\n");
    mostrar_archivo_binario(pf_B_menos_A);
    fclose(pf_B_menos_A);
    getch();

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }

