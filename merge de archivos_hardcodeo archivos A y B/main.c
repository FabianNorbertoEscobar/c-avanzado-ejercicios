#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n MERGE DE ARCHIVOS: HARDCODEO ARCHIVOS A Y B \n\n");

    t_persona personas_A[TAM]={ {25648754,"Ascacibar","Andrea Julieta",35,32000.00},
                                {16514142,"Borrato","Jorge Esteban",54,24000.00},
                                {36916554,"Cancarro","Matías Ignacio",25,37870.00},
                                {26489494,"Echegaray","Malena Romina",33,17470.00},
                                {18564966,"Gutierrez","Enrique Luis",50,16640.00},
                                {28946356,"Oberto","Jorge Ignacio",35,17000.00},
                                {32659449,"Ortúzar","Oriana Lucía",27,32000.00},
                                {25648754,"Roberto","Sergio",31,14500.00},
                                {13648754,"Torres Rojas","Gilberto Pancracio",56,29850.00},
                                {25648754,"Ulisotta","Juan Edgardo",34,16200.00}  };

    t_persona personas_B[TAM]={ {30135949,"Aranibar","Johanna Luna",29,26450.00},
                                {26489494,"Echegaray","Malena Romina",33,17470.00},
                                {18564966,"Gutierrez","Enrique Luis",50,16640.00},
                                {23487487,"Montero","Patricio Humberto",26,23350.00},
                                {19648754,"Pereyra","Oscar Darío",43,34656.00},
                                {25648754,"Roberto","Sergio",31,14500.00},
                                {26496135,"Sánchez","Tamara",25,16700.00},
                                {20161131,"Serrano","Omar Ricardo",35,16400.00},
                                {25648754,"Ulisotta","Juan Edgardo",34,16200.00},
                                {23648754,"Zuñiga","Pedro Iván",42,147500}  };

    grabar_en_binario("personas_A.bin",personas_A,TAM);
    grabar_en_binario("personas_B.bin",personas_B,TAM);

    //----------------------------------------------------------------------------------------------------

    FILE *pf_A,*pf_B;
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

    printf("\n\n ARCHIVO A \n\n");
    mostrar_archivo_binario(pf_A);
    printf("\n\n ARCHIVO B \n\n");
    mostrar_archivo_binario(pf_B);

    fclose(pf_A);
    fclose(pf_B);

    printf("\n\n Se han generado los archivos \"personas_A.bin\" y \"personas_B.bin\" \n\a\a");
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
