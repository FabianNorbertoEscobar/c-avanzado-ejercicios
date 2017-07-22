#include "header.h"

void generar_lista_de_conceptos_por_empleado(t_lista *l)
{
    t_dato_lista datos[50]=
    {
        {"20364851654",123456},
        {"12625841417",234567},
        {"14782365955",123456},
        {"95959545285",123456},
        {"65568684848",234567},
        {"85282963962",345678},
        {"14782142452",345678},
        {"12165484145",345678},
        {"12625841417",234567},
        {"96358414785",234567},
        {"20364851654",456789},
        {"85282963962",456789},
        {"14782365955",456789},
        {"78958858928",456789},
        {"95959545285",567899},
        {"12165484145",567899},
        {"14782142452",567899},
        {"74125885236",567899},
        {"65568684848",987654},
        {"95959545285",987654},
        {"12625841417",987654},
        {"14782365955",987654},
        {"78958858928",876543},
        {"85282963962",876543},
        {"65568684848",876543},
        {"14782365955",654321},
        {"96358414785",654321},
        {"74125885236",654321},
        {"20364851654",654321},
        {"12165484145",147852},
        {"12625841417",147852},
        {"96358414785",147852},
        {"74185296385",147852},
        {"74125885236",147852},
        {"95959545285",963258},
        {"14782142452",963258},
        {"14782365955",963258},
        {"20364851654",963258},
        {"12165484145",963258},
        {"74185296385",321456},
        {"96358414785",321456},
        {"65568684848",321456},
        {"85282963962",321456},
        {"20364851654",747485},
        {"14782142452",747485},
        {"74125885236",747485},
        {"78958858928",653298},
        {"74185296385",653298},
        {"85282963962",653298},
        {"65568684848",653298}
    };

    int i;
    for(i=0; i<50; i++)
    {
        if(!insertar_en_lista_ordenada_con_duplicados(l,&datos[i],comparar_cuit))
        {
            printf("\n\n Sin memoria para cargar la lista de conceptos por empleado \n\n\a\a");
            exit(EXIT_FAILURE);
        }
    }
}

void generar_arbol_de_importes_de_conceptos(t_arbol *a)
{
    t_dato_arbol datos[12]=
    {
        {123456,7500},
        {234567,5900},
        {345678,7400},
        {456789,6300},
        {567899,8100},
        {987654,6900},
        {876543,7900},
        {147852,4600},
        {963258,5600},
        {321456,6700},
        {747485,9800},
        {653298,8800}
    };

    int i;
    for(i=0; i<12; i++)
    {
        if(!insertar_en_arbol_iterativa(a,&datos[i],comparar_codigo_concepto))
        {
            printf("\n\n Sin memoria para cargar el árbol de conceptos \n\n\a\a");
            exit(EXIT_FAILURE);
        }
    }
}

void generar_archivo_de_impuestos(t_lista *l,t_arbol *a,FILE *pf)
{
    t_dato_lista dato_lista;
    t_dato_lista anterior;

    t_dato_arbol dato_arbol;
    t_registro registro;

    float sueldo=0;
    int bandera;

    ver_primero_de_lista(l,&anterior);

    while(!lista_vacia(l))
    {
        sacar_primero_de_lista(l,&dato_lista);

        if(comparar_cuit(&anterior,&dato_lista)==FALSO)
        {
            buscar_en_arbol_iterativa_y_retornar_dato(a,&dato_arbol,(void*)&dato_lista.codigo_concepto,comparar_codigo_concepto);

            if(dato_arbol.importe_concepto!=0)
                sueldo+=dato_arbol.importe_concepto;
            else
            {
                printf("\n\n No se registra el importe de un concepto \a\a");
                printf("\n\n Ingrese importe de concepto %d: \t",dato_arbol.codigo_concepto);

                bandera=0;
                do
                {
                    if(bandera==1)
                        printf("\n\n El importe de concepto ingresado es inválido. \n\n Reingresar: \t");

                    fflush(stdin);
                    scanf("%f",&dato_arbol.importe_concepto);

                    bandera=1;
                }
                while(dato_arbol.importe_concepto<=0);

                sueldo+=dato_arbol.importe_concepto;
                buscar_en_arbol_iterativa_y_actualizar_dato(a,&dato_arbol,(void*)&dato_lista.codigo_concepto,comparar_codigo_concepto);
            }
        }
        else
        {
            str_cpy(registro.cuit,dato_lista.cuit);
            registro.sueldo_total=sueldo;
            registro.importe_impuesto=calcular_impuesto(sueldo);
            fwrite(&registro,sizeof(t_registro),1,pf);
            anterior=dato_lista;
            sueldo=0;
        }
    }

    str_cpy(registro.cuit,dato_lista.cuit);
    registro.sueldo_total=sueldo;
    registro.importe_impuesto=calcular_impuesto(sueldo);
    fwrite(&registro,sizeof(t_registro),1,pf);

    fclose(pf);
}

float calcular_impuesto(float sueldo)
{
    if(sueldo<10000)
        return 0;
    if(sueldo<15000)
        return 5*sueldo/100;
    if(sueldo<20000)
        return 10*sueldo/100;
    if(sueldo<25000)
        return 15*sueldo/100;
    if(sueldo<50000)
        return 20*sueldo/100;
    return 25*sueldo/100;
}
