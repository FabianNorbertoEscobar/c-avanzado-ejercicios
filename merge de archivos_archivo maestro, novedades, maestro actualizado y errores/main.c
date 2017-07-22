#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 5E");

    printf("\n\t\t\t *********************");
    printf("\n\t\t\t * MERGE DE ARCHIVOS * \a\a");
    printf("\n\t\t\t *********************\n");

    printf("\n El archivo maestro contiene un campo de estado que indica \n si sus registros están dados de alta o de baja. \n");
    printf("\n Este archivo no se modifica permanentemente, sino que es actualizado \n cada cierto tiempo, para no manosearlo tan a menudo, ya que");
    printf("\n contiene datos importantes. Lo que se hace es actualizar lo que sea \n necesario a partir de un archivo que contiene las novedades. ");
    printf("\n Este archivo de novedades cuenta con los registros intervinientes y un \n código de operación en el que figura lo que debe hacerse en cada caso. \n");
    getch();
    printf("\n Luego de hacer las modificaciones correspondientes, el archivo de novedades \n vuelve a cero para seguir siendo cargado cuando sea necesario.\n");
    printf("\n El archivo maestro es descartado ya que es obsoleto cuando rige el archivo \n maestro actualizado, quien luego se convierte en el archivo maestro. \n");
    printf("\n Los registros con errores que pudiera haber traído el archivo de novedades \n serán volcados en un archivo de errores");
    printf("\n para poder ser revisados luego. Por supuesto que no son tenidos en cuenta \n a la hora de actualizar el archivo maestro. \n\n");
    getch();

    t_maestro personas_maestro[TAM_MAESTRO]= {  {30135949,"Aranibar","Johanna Luna",29,26450.00,'A'},
                                                {25648754,"Ascacibar","Andrea Julieta",35,32000.00,'A'},
                                                {16514142,"Borrato","Jorge Esteban",54,24000.00,'A'},
                                                {36916554,"Cancarro","Matías Ignacio",25,37870.00,'A'},
                                                {13259961,"Donastero","Edmundo Pedro",58,447500,'A'},
                                                {26489494,"Echegaray","Malena Romina",33,17470.00,'B'},
                                                {31548454,"Figueroa","Ricardo Paulo",28,18500.00,'A'},
                                                {18564966,"Gutierrez","Enrique Luis",50,16640.00,'B'},
                                                {23487487,"Montero","Patricio Humberto",26,23350.00,'A'},
                                                {28946356,"Oberto","Jorge Ignacio",35,17000.00,'A'},
                                                {32659449,"Ortúzar","Oriana Lucía",27,32000.00,'A'},
                                                {19648754,"Pereyra","Oscar Darío",43,34656.00,'B'},
                                                {25648754,"Roberto","Sergio",31,14500.00,'A'},
                                                {26496135,"Sánchez","Tamara",25,16700.00,'A'},
                                                {36494948,"Segobia","Laura Daiana",25,14750.00,'A'},
                                                {20161131,"Serrano","Omar Ricardo",35,16400.00,'A'},
                                                {13648754,"Torres Rojas","Gilberto Pancracio",56,29850.00,'B'},
                                                {25648754,"Ulisotta","Juan Edgardo",34,16200.00,'B'},
                                                {29135796,"Valente","Loana Elene",34,29500.00,'A'},
                                                {23648754,"Zuñiga","Pedro Iván",42,14750.00,'B'}  };

    t_novedades personas_novedades[TAM_NOVEDADES]= {    {25494177,"Andrada","Sofía",31,34000.00,'A'},
                                                        {25648754,"Ascacibar","Andrea Julieta",35,32000.00,'B'},
                                                        {16514142,"Borrato","Jorge Esteban",54,24000.00,'B'},
                                                        {13259961,"Donastero","Edmundo Pedro",58,447500,'A'},
                                                        {26489494,"Echegaray","Malena Romina",33,17470.00,'A'},
                                                        {31548454,"Figueroa","Ricardo Paulo",28,18500.00,'A'},
                                                        {18564966,"Gutierrez","Enrique Luis",50,16640.00,'B'},
                                                        {36514142,"Miranda","Milena Lena",26,26500.00,'A'},
                                                        {23487488,"Montero","Romualdo Humberto",26,16590.00,'B'},
                                                        {28946356,"Oberto","Jorge Ignacio",35,17000.00,'B'},
                                                        {32659449,"Ortúzar","Oriana Lucía",27,32000.00,'A'},
                                                        {19648754,"Pereyra","Oscar Darío",43,34656.00,'B'},
                                                        {12514142,"Pontesa","Jose María",62,354000.00,'M'},
                                                        {25648754,"Roberto","Sergio",31,14500.00,'A'},
                                                        {36494948,"Segobia","Laura Daiana",25,14750.00,'A'},
                                                        {20161131,"Serrano","Omar Ricardo",35,26400.00,'M'},
                                                        {13648754,"Torres Rojas","Gilberto Pancracio",56,29850.00,'B'},
                                                        {29135796,"Valente","Loana Elene",34,29500.00,'A'}    };

    grabar_archivo_maestro("maestro.bin",personas_maestro,TAM_MAESTRO);
    grabar_archivo_novedades("novedades.bin",personas_novedades,TAM_NOVEDADES);

    //---------------------------------------------------------------------------------------------------------------------

    FILE *pf_maestro,*pf_novedades;

    pf_maestro=fopen("maestro.bin","rb");
    if(!pf_maestro)
        {
        printf("\n\n No se pudo leer el archivo \"maestro.bin\" \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    pf_novedades=fopen("novedades.bin","rb");
    if(!pf_novedades)
        {
        printf("\n\n No se pudo leer el archivo \"novedades.bin\" \n\n\a\a");
        fclose(pf_maestro);
        exit(EXIT_FAILURE);
        }

    printf("\n\n\t\t ARCHIVO MAESTRO");
    printf("\n\t\t ***************\n\n\a\a");
    mostrar_archivo_maestro(pf_maestro);
    getch();

    printf("\n\n\t\t ARCHIVO NOVEDADES");
    printf("\n\t\t *****************\n\n\a\a");
    mostrar_archivo_novedades(pf_novedades);
    getch();

    //-------------------------------------------------------------------------------------------------------------------------

    printf("\n\n Presione cualquier tecla para comenzar con la actualización del archivo maestro \n\n\a\a");
    getch();

    FILE *pf_maestro_actualizado,*pf_errores;

    pf_maestro_actualizado=fopen("maestro actualizado.bin","wb");
    if(!pf_maestro_actualizado)
        {
        printf("\n\n No se pudo crear el archivo \"maestro actualizado.bin\" \n\n\a\a");
        fclose(pf_maestro);
        fclose(pf_novedades);
        exit(EXIT_FAILURE);
        }

    pf_errores=fopen("errores.bin","wb");
    if(!pf_errores)
        {
        printf("\n\n No se pudo crear el archivo \"errores.bin\" \n\n\a\a");
        fclose(pf_maestro);
        fclose(pf_novedades);
        fclose(pf_maestro_actualizado);
        exit(EXIT_FAILURE);
        }

    actualizar_archivo_maestro(pf_maestro,pf_novedades,pf_maestro_actualizado,pf_errores);
    printf("\n\n La actualización del archivo maestro ha finalizado exitosamente \a\a");
    printf("\n\n Se han generado los archivos \"maestro actualizado.bin\" y \"errores.bin\"");

    fclose(pf_maestro_actualizado);
    fclose(pf_errores);

    //---------------------------------------------------------------------------------------------------------

    printf("\n\n Presione cualquier tecla para ver los resultados \n\n");
    getch();

    pf_maestro_actualizado=fopen("maestro actualizado.bin","rb");
    if(!pf_maestro_actualizado)
        {
        printf("\n\n No se pudo leer el archivo \"maestro actualizado.bin\" \n\n\a\a");
        fclose(pf_maestro);
        fclose(pf_novedades);
        exit(EXIT_FAILURE);
        }

    pf_errores=fopen("errores.bin","rb");
    if(!pf_errores)
        {
        printf("\n\n No se pudo leer el archivo \"errores.bin\" \n\n\a\a");
        fclose(pf_maestro);
        fclose(pf_novedades);
        fclose(pf_maestro_actualizado);
        exit(EXIT_FAILURE);
        }

    printf("\n\n\t\t ARCHIVO MAESTRO ACTUALIZADO");
    printf("\n\t\t *************************** \n\n\a\a");
    mostrar_archivo_maestro(pf_maestro_actualizado);
    getch();

    printf("\n\n\t\t ARCHIVO ERRORES");
    printf("\n\t\t ***************\n\n\a\a");
    mostrar_archivo_novedades(pf_errores);
    getch();

    //----------------------------------------------------------------------------------------------------------------------

    fclose(pf_novedades);
    pf_novedades=fopen("novedades.bin","wb");
    if(!pf_novedades)
        {
        printf("\n\n No se ha podido vaciar el archivo \"novedades.bin\" \n\n\a\a");
        fclose(pf_maestro);
        fclose(pf_maestro_actualizado);
        fclose(pf_errores);
        exit(EXIT_FAILURE);
        }

    FILE *pf_errores_txt;
    pf_errores_txt=fopen("errores exportado a txt long fija.txt","wt");
    if(!pf_errores_txt)
        {
        printf("\n\n No se ha podido exportar el archivo errores a \n archivo de texto de longitud fija \n\n\a\a");
        fclose(pf_errores);
        fclose(pf_maestro);
        fclose(pf_novedades);
        fclose(pf_maestro_actualizado);
        exit(EXIT_FAILURE);
        }
    exportar_errores_a_txt_longitud_fija(pf_errores,pf_errores_txt);
    fclose(pf_errores_txt);

    printf("\n\n El archivo \"errores.bin\" ha sido exportado al archivo \n \"errores exportado a txt long fija.txt\" \n\n\a\a");
    getch();

    fclose(pf_errores);
    printf("\n\n El archivo \"errores.bin\" ha sido cerrado, y espera a revisión \n\n\a\a");
    getch();

    fclose(pf_novedades);
    printf("\n\n El archivo \"novedades.bin\" ha sido vaciado ya que ya se ha implementado \n\n\a\a");
    getch();

    fclose(pf_maestro);
    remove("maestro.bin");
    printf("\n\n El archivo \"maestro.bin\" ha sido descartado \n\n\a\a");
    getch();

    FILE *pf_maestro_txt;
    pf_maestro_txt=fopen("maestro exportado a txt long fija.txt","wt");
    if(!pf_maestro_txt)
        {
        printf("\n\n No se ha podido exportar el archivo maestro a \n archivo de texto de longitud fija \n\n\a\a");
        fclose(pf_maestro_actualizado);
        exit(EXIT_FAILURE);
        }
    exportar_maestro_a_txt_longitud_fija(pf_maestro_actualizado,pf_maestro_txt);
    fclose(pf_maestro_txt);

    fclose(pf_maestro_actualizado);
    rename("maestro actualizado.bin","maestro.bin");
    printf("\n\n El archivo \"maestro actualizado.bin\" ahora es el nuevo archivo \"maestro.bin\" \n\n\a\a");
    getch();

    printf("\n\n El archivo \"maestro.bin\" ha sido exportado al archivo \n \"maestro exportado a txt long fija.txt\" \n\n\a\a");
    getch();

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }
