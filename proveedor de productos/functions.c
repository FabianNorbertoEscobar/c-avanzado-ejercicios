#include "header.h"

int fecha_valida(t_fecha *f)
    {
    return (f->a>=1600&&f->m>=1&&f->m<=12&&f->d>=1&&f->d<=cant_dias_mes(f->m,f->a))?1:0;
    }

int cant_dias_mes(int m,int a)
    {
    int dias[]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (m==2)?28+bisiesto(a):dias[m-1];
    }

int bisiesto(int a)
    {
    return ((a%4==0&&a%100!=0)||a%400==0)?1:0;
    }

void ingresa_fecha(t_fecha *f)
    {
    int bandera=0;
    printf("\n Ingrese la fecha en formato dd/mm/aaaa: \t");
    do
        {
        if(bandera==1)
            printf("\n La fecha ingresada no existe. Reingrésela: \t\a\a");
        scanf("%d/%d/%d",&f->d,&f->m,&f->a);
        bandera=1;
        }
    while(!fecha_valida(f));
    }

void cargar_dato(t_dato *d)
    {
    int bandera;

    printf("\n DATO A APILAR: \a\a");

    printf("\n\n Ingrese el código de producto (7 caracteres): \n\n\t");
    fflush(stdin);
    gets(d->cod);

    printf("\n\n Ingrese la descripción del producto (15 caracteres): \n\n\t");
    fflush(stdin);
    gets(d->desc);

    printf("\n\n Ingrese el proveedor del producto (15 caracteres): \n\n\t");
    fflush(stdin);
    gets(d->prov);

    printf("\n\n Fecha de compra \n");
    fflush(stdin);
    ingresa_fecha(&d->f_comp);

    printf("\n\n Fecha de vencimiento \n");
    fflush(stdin);
    ingresa_fecha(&d->f_venc);

    printf("\n Ingrese la cantidad de productos: \t");
    bandera=0;
    do
        {
        if(bandera==1)
            printf("\n La cantidad ingresada es incorrecta. Ingrese cantidad válida: \a\a\n\n\t");
        fflush(stdin);
        scanf("%d",&d->cant);
        bandera=1;
        }
    while(d->cant<=0);

    printf("\n Ingrese el precio de compra: \t\t");
    bandera=0;
    do
        {
        if(bandera==1)
            printf("\n El precio ingresado es inválido. Ingrese un precio válido: \a\a\n\n\t");
        fflush(stdin);
        scanf("%f",&d->prec_comp);
        bandera=1;
        }
    while(d->prec_comp<=0);

    printf("\n Ingrese el precio de venta: \t\t");
    bandera=0;
    do
        {
        if(bandera==1)
            printf("\n El precio ingresado es inválido. Ingrese un precio válido: \a\a\n\n\t");
        fflush(stdin);
        scanf("%f",&d->prec_vent);
        bandera=1;
        }
    while(d->prec_vent<=0);
    }

void mostrar_dato(t_dato *d)
    {
    printf("\n DATO: \n\a\a");
    printf("\n Código de producto: \t %s",d->cod);
    printf("\n Descripción del producto: \t %s",d->desc);
    printf("\n Proveedor del producto: \t %s",d->prov);
    printf("\n Fecha de compra: \t %d/%d/%d",d->f_comp.d,d->f_comp.m,d->f_comp.a);
    printf("\n Fecha de vencimiento: \t %d/%d/%d",d->f_venc.d,d->f_venc.m,d->f_venc.a);
    printf("\n Cantidad de productos: \t %d",d->cant);
    printf("\n Precio de compra: \t %.2f",d->prec_comp);
    printf("\n Precio de venta:  \t %.2f\n\n",d->prec_vent);
    }

int menu(void)
    {
    int op,bandera;
    bandera=0;
    do
        {
        if(bandera==1)
            {
            system("cls");
            printf("\n\n La opción ingresada no existe \a\a");
            getch();
            system("cls");
            }

        printf("\n\t\t *********************************");
        printf("\n\t\t * MENÚ - PROVEEDOR DE PRODUCTOS *\a\a");
        printf("\n\t\t *********************************");

        printf("\n\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Crear pila de productos");
        printf("\n 2- Apilar un nuevo producto");
        printf("\n 3- Desapilar un producto");
        printf("\n 4- ¿Pila de productos llena?");
        printf("\n 5- ¿Pila de productos vacía?");
        printf("\n 6- Ver tope de la pila de productos");
        printf("\n 7- Vaciar pila de productos");
        printf("\n 8- Borrar pila de productos");
        printf("\n 9- Exportar pila de productos a archivo binario");
        printf("\n 10- Exportar pila de productos a archivo de texto");
        printf("\n 11- Cargar pila de productos desde archivo binario");
        printf("\n 12- Cargar pila de productos desde archivo de texto");
        printf("\n\n 0- SALIR");

        printf("\n\n \t\t\t\t Opción: \t");
        scanf("%d",&op);
        bandera=1;
        }
    while(!DATO_VALIDO(op,0,12));

    return op;
    }

int exportar_pila_a_archivo_bin(t_pila *pila)
    {
    FILE *pf;
    pf=fopen("datos.bin","wb");
    if(!pf)
        return 0;

    t_dato dato;
    t_pila pila_inversa;
    crear_pila(&pila_inversa);

    while(!pila_vacia(pila))
        {
        desapilar(pila,&dato);
        apilar(&pila_inversa,&dato);
        }

    while(!pila_vacia(&pila_inversa))
        {
        desapilar(&pila_inversa,&dato);
        fwrite(&dato,sizeof(t_dato),1,pf);
        }

    fclose(pf);
    return 1;
    }

int exportar_pila_a_archivo_txt(t_pila *pila)
    {
    FILE *pf;
    pf=fopen("datos.txt","wt");
    if(!pf)
        return 0;

    t_dato dato;
    t_pila pila_inversa;
    crear_pila(&pila_inversa);

    while(!pila_vacia(pila))
        {
        desapilar(pila,&dato);
        apilar(&pila_inversa,&dato);
        }

    while(!pila_vacia(&pila_inversa))
        {
        desapilar(&pila_inversa,&dato);
        fprintf(pf,"%s|%s|%s|%d/%d/%d|%d/%d/%d|%d|%f|%f\n",dato.cod,dato.desc,dato.prov,dato.f_comp.d,dato.f_comp.m,dato.f_comp.a,dato.f_venc.d,dato.f_venc.m,dato.f_venc.a,dato.cant,dato.prec_comp,dato.prec_vent);
        }

    fclose(pf);
    return 1;
    }

int cargar_pila_desde_archivo_bin(t_pila *pila)
    {
    t_dato dato;
    FILE *pf;
    pf=fopen("datos.bin","rb");
    if(!pf)
        return 0;

    fread(&dato,sizeof(t_dato),1,pf);
    while(!feof(pf))
        {
        apilar(pila,&dato);
        fread(&dato,sizeof(t_dato),1,pf);
        }

    fclose(pf);
    return 1;
    }

int cargar_pila_desde_archivo_txt(t_pila *pila)
    {
    t_dato dato;

    FILE *pf;
    pf=fopen("datos.txt","rt");
    if(!pf)
        return 0;

    fscanf(pf,"%[^|]|%[^|]|%[^|]|%d/%d/%d|%d/%d/%d|%d|%f|%f\n",dato.cod,dato.desc,dato.prov,&dato.f_comp.d,&dato.f_comp.m,&dato.f_comp.a,&dato.f_venc.d,&dato.f_venc.m,&dato.f_venc.a,&dato.cant,&dato.prec_comp,&dato.prec_vent);
    while(!feof(pf))
        {
        apilar(pila,&dato);
        fscanf(pf,"%s|%s|%s|%d/%d/%d|%d/%d/%d|%d|%f|%f\n",dato.cod,dato.desc,dato.prov,&dato.f_comp.d,&dato.f_comp.m,&dato.f_comp.a,&dato.f_venc.d,&dato.f_venc.m,&dato.f_venc.a,&dato.cant,&dato.prec_comp,&dato.prec_vent);
        }

    fclose(pf);
    return 1;
    }

