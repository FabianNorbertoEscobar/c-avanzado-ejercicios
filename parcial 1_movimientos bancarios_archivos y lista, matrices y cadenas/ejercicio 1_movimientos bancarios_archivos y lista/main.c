#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n\t\t  ***** MOVIMIENTOS BANCARIOS ***** \n");

    t_registro registro;
    float saldo;
    char cuenta[9];

    FILE *pf_movimientos,*pf_saldo_menor,*pf_saldo_mayor,*pf_errores;

    pf_movimientos=fopen("movimientos.dat","wb");
    if(!pf_movimientos)
    {
        printf("\n\n No se ha podido crear el archivo lote de prueba \n\n\t Programa evacuado \n\n\a\a");
        exit(EXIT_FAILURE);
    }

    t_registro registros[17]={  {"999999-9",'D',1500},
                                {"999999-9",'D',3000},
                                {"999999-9",'E',2500},
                                {"999999-9",'D',7500},
                                {"111111-6",'D',1000},
                                {"111111-6",'E',2000},
                                {"333333-3",'E',1500},
                                {"121212-9",'D',3000},
                                {"242421-9",'E',2000},
                                {"242521-9",'D',1000},
                                {"222222-3",'D',3500},
                                {"222222-2",'E',4000},
                                {"222222-2",'E',5000},
                                {"789787-6",'D',1000},
                                {"147147-6",'E',9000},
                                {"147147-6",'E',2500},
                                {"111112-3",'E',1000}   };

    fwrite(registros,sizeof(t_registro),17,pf_movimientos);

    fclose(pf_movimientos);
    printf("\n\n El lote de prueba \"movimientos.dat\" ha sido generado exitosamente \n");

    //-----------------------------------------------------------------------------------------------------------------------------------------------

    pf_movimientos=fopen("movimientos.dat","rb");
    if(!pf_movimientos)
    {
        printf("\n\n No se ha podido leer el archivo lote de prueba \n\n\t Programa evacuado \n\n\a\a");
        exit(EXIT_FAILURE);
    }

    pf_saldo_menor=fopen("cuentas con saldo menor a 1000.dat","wb");
    if(!pf_saldo_menor)
    {
        printf("\n\n No se ha podido crear el archivo de cuentas con saldo menor a 1000 \n\n\t Programa evacuado \n\n\a\a");
        fclose(pf_movimientos);
        exit(EXIT_FAILURE);
    }

    pf_saldo_mayor=fopen("cuentas con saldo mayor a 1000.dat","wb");
    if(!pf_saldo_mayor)
    {
        printf("\n\n No se ha podido crear el archivo de cuentas con saldo mayor a 1000 \n\n\t Programa evacuado \n\n\a\a");
        fclose(pf_movimientos);
        fclose(pf_saldo_menor);
        exit(EXIT_FAILURE);
    }

    pf_errores=fopen("ERRORES.txt","wt");
    if(!pf_errores)
    {
        printf("\n\n No se ha pododo crear el archivo de errores \n\n\t Programa evacuado \n\n\a\a");
        fclose(pf_movimientos);
        fclose(pf_saldo_menor);
        fclose(pf_saldo_mayor);
        exit(EXIT_FAILURE);
    }

    //--------------------------------------------------------------------------------------------------------------------------------------------------

    t_lista lista;
    crear_lista(&lista);

    fread(&registro,sizeof(t_registro),1,pf_movimientos);

    while(!feof(pf_movimientos))
    {
        if(cuenta_valida(registro.cuenta))
        {
            saldo=0;
            str_cpy(cuenta,registro.cuenta);
            while(!feof(pf_movimientos)&&!str_cmp(cuenta,registro.cuenta))
            {
                if(registro.movimiento=='D')
                    saldo+=registro.importe;
                else
                    saldo-=registro.importe;

                insertar_en_lista_ordenado_con_duplicado(&lista,(t_dato*)&registro,comparar_movimiento_e_importe);

                if(saldo<0)
                {
                    while(!lista_vacia(&lista))
                    {
                        sacar_de_lista_primero(&lista,(t_dato*)&registro);
                        fprintf(pf_errores,"%-8s %c %.2f\n",registro.cuenta,registro.movimiento,registro.importe);
                    }

                    fread(&registro,sizeof(t_registro),1,pf_movimientos);
                    break;
                }


                fread(&registro,sizeof(t_registro),1,pf_movimientos);
            }
            if(str_cmp(cuenta,registro.cuenta))
            {
                if(saldo<1000)
                    while(!lista_vacia(&lista))
                    {
                        sacar_de_lista_primero(&lista,(t_dato*)&registro);
                        fwrite(&registro,sizeof(t_registro),1,pf_saldo_menor);
                    }
                else
                    while(!lista_vacia(&lista))
                    {
                        sacar_de_lista_primero(&lista,(t_dato*)&registro);
                        fwrite(&registro,sizeof(t_registro),1,pf_saldo_mayor);
                    }
            }
        }
        else
        {
            fprintf(pf_errores,"%-8s %c %.2f\n",registro.cuenta,registro.movimiento,registro.importe);
            fread(&registro,sizeof(t_registro),1,pf_movimientos);
        }
        str_cpy(cuenta,registro.cuenta);
    }

    printf("\n\n Se han generado exitosamente los archivos binarios \n \"cuentas con saldo mayor a 1000.dat\" y \"cuentas con saldo menor a 1000.dat\"");
    printf("\n y el archivo de texto \"ERRORES.txt\" \n\n");

    fclose(pf_movimientos);
    fclose(pf_saldo_menor);
    fclose(pf_saldo_mayor);
    fclose(pf_errores);

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n \a\a");
    getch();
    return 0;
}
