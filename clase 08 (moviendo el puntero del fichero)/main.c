#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    FILE *pf;
    t_persona per;
    printf("\n\n MOVIENDO EL PUNTERO DEL FICHERO \n");
    pf=fopen("personas.dat","rb");
    if(!pf)
        {
        printf("\n\n El archivo está corrupto \n\n\a\a");
        exit(1);
        }

    printf("\n\n Tercer registro del archivo \"personas.dat\": \n\n");
    fseek(pf,sizeof(t_persona)*2L,SEEK_CUR);
    fread(&per,sizeof(t_persona),1,pf);
    printf("\n\n DNI: \t %d \t Nombre y apellido: \t %s \n Edad: \t %d \t Fecha de nacimiento: \t %d/%d/%d \n",per.dni,per.nomb,per.edad,per.f_nac.d,per.f_nac.m,per.f_nac.a);

    printf("\n\n Rebobino el fichero \n");
    rewind(pf);
    //     fseek(pf,0L,SEEK_SET);       es lo mismo que hacer esto
    printf("\n\n Primer registro del archivo \"personas.dat\": \n\n");
    fread(&per,sizeof(t_persona),1,pf);
    printf("\n\n DNI: \t %d \t Nombre y apellido: \t %s \n Edad: \t %d \t Fecha de nacimiento: \t %d/%d/%d \n",per.dni,per.nomb,per.edad,per.f_nac.d,per.f_nac.m,per.f_nac.a);

    printf("\n\n Tamaño de un registro en bytes: \t %d \n",ftell(pf));
    fseek(pf,0L,SEEK_END);
    printf("\n\n Tamaño del fichero medido en bytes: \t %d \n",ftell(pf));
    printf("\n\n Cantidad de registros grabados en el fichero: \t %d \n",ftell(pf)/sizeof(t_persona));
    fclose(pf);
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
