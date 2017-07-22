#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 80");

    FILE *pf_A,*pf_B;

    printf("\n\n\t\t DIFERENCIA SIMÉTRICA DE ARCHIVOS");
    printf("\n\t\t ================================ \n\n\a\a");

    printf("\n El archivo resultante A diferencia simétrica B contendrá los registros \n que aparezcan en A o en B, pero no en ambos \n\n");
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

    FILE *pf_dif_sim;
    pf_dif_sim=fopen("A diferencia simétrica B.bin","wb");
    if(!pf_dif_sim)
        {
        printf("\n\n No se pudo crear el archivo \"A diferencia simétrica B.bin\" \n\n\a\a");
        fclose(pf_A);
        fclose(pf_B);
        exit(EXIT_FAILURE);
        }
    diferencia_simetrica_de_archivos_binarios(pf_A,pf_B,pf_dif_sim);
    printf("\n\n Se he generado el archivo \"A diferencia simétrica B.bin\" \n\n\a\a");
    getch();

    fclose(pf_A);
    fclose(pf_B);
    fclose(pf_dif_sim);

    pf_dif_sim=fopen("A diferencia simétrica B.bin","rb");
    if(!pf_dif_sim)
        {
        printf("\n\n No se pudo abrir el archivo \"A diferencia simétrica B.bin\" \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    printf("\n\n\t\t ARCHIVO A DIFERENCIA SIMÉTRICA B \a\a");
    printf("\n\t\t ================= \n\n");
    mostrar_archivo_binario(pf_dif_sim);
    fclose(pf_dif_sim);
    getch();

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }

