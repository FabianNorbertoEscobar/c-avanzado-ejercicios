#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n \t ANALIZANDO PALABRAS EN UN TXT DE PALABRAS \a\a");

    FILE *pf;
    pf=fopen("palabras.txt","rt");
    if(!pf)
        {
        printf("\n\n Error al leer el fichero de texto \n\n Programa evacuado \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    int cuenta_uniletras=0,cuenta_cant_par_letras=0,cuenta_empiezan_con_n=0,cuenta_comienzan_con_prefijo=0;
    int cuenta_con_mas_de_tres_vocales=0,cuenta_empiezan_y_terminan_con_vocal=0,cuenta_contienen_digitos=0;
    int cuenta_solo_formados_por_digitos=0,cuenta_palindromos=0;

    printf("\n\n Ingrese un prefijo (que se usará luego) (no más de 3 caracteres): \t");
    char prefijo[3];
    fflush(stdin);
    gets(prefijo);

    printf("\n\n Ingrese un caracter (que se usará luego): \t");
    char caracter;
    fflush(stdin);
    scanf("%c",&caracter);

    char cadena[6];

    while(!feof(pf))
        {
        str_cpy(cadena,leer_cadena(pf));

        if(es_uniletra(cadena))
            cuenta_uniletras++;
        if(es_de_cant_par_de_letras(cadena))
            cuenta_cant_par_letras++;
        if(empieza_con_n(cadena,caracter))
            cuenta_empiezan_con_n++;
        if(empieza_con_prefijo(cadena,prefijo))
            cuenta_comienzan_con_prefijo++;
        if(tiene_mas_de_3_vocales(cadena))
            cuenta_con_mas_de_tres_vocales++;
        if(empieza_y_termina_con_vocal(cadena))
            cuenta_empiezan_y_terminan_con_vocal++;
        if(contiene_digitos(cadena))
            cuenta_contienen_digitos++;
        if(tiene_solo_numeros(cadena))
            cuenta_solo_formados_por_digitos++;
        if(es_palindromo(cadena))
            cuenta_palindromos++;
        }

    printf("\n\n RESULTADOS DEL ANÁLISIS DE LAS CADENAS \n");

    printf("\n Formadas por solo una letra: \t %d",cuenta_uniletras);
    printf("\n Formadas por una cantidad par de letras: \t %d",cuenta_cant_par_letras);
    printf("\n Comienzan con el caracter %c: \t %d",caracter,cuenta_empiezan_con_n);
    printf("\n Comienzan con el prefijo %s: \t %d",prefijo,cuenta_comienzan_con_prefijo);
    printf("\n Tienen más de tres vocales: \t %d",cuenta_con_mas_de_tres_vocales);
    printf("\n Comienzan y terminan con vocal: \t %d",cuenta_empiezan_y_terminan_con_vocal);
    printf("\n Contienen algún dígito: \t %d",cuenta_contienen_digitos);
    printf("\n Solo formadas por dígitos: \t %d",cuenta_solo_formados_por_digitos);
    printf("\n Palíndromos: \t %d",cuenta_palindromos);

    fclose(pf);

    printf("\n\n \t\t\t\t\t  Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }

