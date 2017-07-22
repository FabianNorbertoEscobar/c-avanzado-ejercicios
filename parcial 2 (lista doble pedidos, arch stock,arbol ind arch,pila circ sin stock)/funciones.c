#include "header.h"

char *str_cpy(char *destino,const char *origen)
{
    char *inicio=destino;
    while(*origen)
    {
        *destino=*origen;
        destino++;
        origen++;
    }
    *destino='\0';
    return inicio;
}

int str_cmp(const char *s1,const char *s2)
{
    while(*s1&&*s2&&*s1==*s2)
    {
        s1++;
        s2++;
    }
    return *s1-*s2;
}

int comparar_dato_contra_dato(const void *v1,const void *v2)
{
    t_dato_lista *dato1=(t_dato_lista*)v1;
    t_dato_lista *dato2=(t_dato_lista*)v2;
    return str_cmp(dato1->codigo_producto,dato2->codigo_producto);
}

int comparar_dato_contra_clave(const void *v,const void *c)
{
    t_dato_arbol *dato=(t_dato_arbol*)v;
    char *clave=(char*)c;
    return str_cmp(dato->codigo_producto,clave);
}

void generar_archivo_de_productos(FILE *pf)
{
    t_registro registros[10]= {         {"Caramelos","asd15",500},
                                        {"Alfajores","erg54",920},
                                        {"Barritas de cereal","nbm78",460},
                                        {"Galletitas","ret36",100},
                                        {"Botellitas de licor","aqw33",300},
                                        {"Gomitas","oiu87",130},
                                        {"Gaseosa","zas23",250},
                                        {"Agua","hgf22",250},
                                        {"Energizante","dde58",300},
                                        {"Cigarrillos","rte60",700}
                                                                                        };

    pf=fopen("PRODUCTO.dat","wb");
    if(!pf)
        exit(EXIT_FAILURE);

    fwrite(registros,sizeof(t_registro),10,pf);
    fclose(pf);

}

void generar_indice_del_archivo_en_el_arbol(FILE *pf,t_arbol *a,t_cmp comparar)
{
    t_registro registro;
    t_dato_arbol dato;
    int i=1;

    pf=fopen("PRODUCTO.dat","rb");
    if(!pf)
        exit(EXIT_FAILURE);

    fread(&registro,sizeof(t_registro),1,pf);
    while(!feof(pf))
    {
        str_cpy(dato.codigo_producto,registro.codigo_producto);
        dato.posicion_en_archivo=i;

        insertar_en_arbol(a,&dato,comparar_dato_contra_clave);
        fread(&registro,sizeof(t_registro),1,pf);
        i++;
    }

    fclose(pf);
}

void generar_lista_de_pedidos(t_lista *l)
{
    int i=0;
    t_dato_lista registros[35]=     {       {"asd15",50},
                                            {"zas23",250},
                                            {"asd15",150},
                                            {"erg54",920},
                                            {"ret36",100},
                                            {"zas23",200},
                                            {"dde58",300},
                                            {"erg54",290},
                                            {"asd15",50},
                                            {"zas23",250},
                                            {"rte60",70},
                                            {"nbm78",46},
                                            {"ret36",100},
                                            {"erg54",920},
                                            {"hgf22",250},
                                            {"aqw33",30},
                                            {"nbm78",460},
                                            {"oiu87",130},
                                            {"rte60",70},
                                            {"erg54",92},
                                            {"nbm78",460},
                                            {"rte60",70},
                                            {"ret36",100},
                                            {"oiu87",130},
                                            {"erg54",92},
                                            {"oiu87",100},
                                            {"hgf22",25},
                                            {"hgf22",200},
                                            {"dde58",300},
                                            {"aqw33",300},
                                            {"nbm78",46},
                                            {"aqw33",300},
                                            {"dde58",30},
                                            {"asd15",500},
                                            {"rte60",700}             };

    for(i=0;i<35;i++)
        insertar_en_lista_doble_ordenada_con_duplicado(l,&registros[i],comparar_dato_contra_dato);
}

void procesar_pedido_completo(FILE *pf,const t_arbol *arbol,t_pila *pila,t_dato_lista *dato_lista,int cantidad_pedida)
{
    t_registro registro;
    t_dato_arbol dato_arbol;
    t_dato_pila dato_pila;

    // con el código de producto, busco en el árbol el registro en el archivo
    buscar_en_arbol_y_retornar_dato(arbol,&dato_arbol,(void*)dato_lista->codigo_producto,comparar_dato_contra_clave);

    // me posiciono en ese registro y lo leo
    fseek(pf,(dato_arbol.posicion_en_archivo-1)*sizeof(t_registro),SEEK_SET);
    fread(&registro,sizeof(t_registro),1,pf);

    // me fijo se el stock me alcanza para concretar el pedido
    if(cantidad_pedida<=registro.stock)
    {
        registro.stock-=cantidad_pedida;        // si alcanza, lo concreto y actualizo el registro en el archivo

        fseek(pf,-sizeof(t_registro),SEEK_CUR);
        fwrite(&registro,sizeof(t_registro),1,pf);
    }
    else
    {
        if(!pila_llena(pila))       // si no alcanza, apilo el pedido sin stock en una pila circular
        {
            str_cpy(dato_pila.codigo_producto,dato_lista->codigo_producto);
            dato_pila.cantidad_pedida=dato_lista->cantidad_pedida;

            apilar(pila,&dato_pila);
        }
        else
            printf("\n\n PILA LLENA: No se puede apilar pedido sin stock \n\n");
    }
}

void mostrar_pedidos_sin_stock(t_pila *pila)
{
    t_dato_pila dato;

    while(!pila_vacia(pila))
    {
        desapilar(pila,&dato);

        printf("\n\n Código de producto: \t %s",dato.codigo_producto);
        printf("\n Cantidad pedida: \t %d \n",dato.cantidad_pedida);
    }
}
