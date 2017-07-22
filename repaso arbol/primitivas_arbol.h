#include "dato.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     ARBOL_VACIO         0
#define     MEMORIA_LLENA       0
#define     DUPLICADO           0
#define     NO_ENCONTRADO       0
#define     OK                  1

#define     ABS(x)      (((x)>=0)?(x):(-(x)))

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *izq;
    struct s_nodo *der;
}t_nodo;

typedef t_nodo* t_arbol;

typedef int(*t_cmp)(const void*,const void*);
typedef void(*t_mst)(const void*);

void crear_arbol(t_arbol*);

void talar_arbol(t_arbol*);
void vaciar_arbol(t_arbol*);

int arbol_vacio(const t_arbol*);
int arbol_lleno(const t_arbol*);

int ver_raiz(const t_arbol*,t_dato*);
int es_hoja(const t_arbol*);

void recorrer_arbol_en_inorden(const t_arbol*,t_mst);
void recorrer_arbol_en_preorden(const t_arbol*,t_mst);
void recorrer_arbol_en_posorden(const t_arbol*,t_mst);

int insertar_en_arbol_recursiva(t_arbol*,const t_dato*,t_cmp);
int insertar_en_arbol_iterativa(t_arbol*,const t_dato*,t_cmp);

int buscar_en_arbol_recursiva(const t_arbol*,const t_dato*,t_cmp);
int buscar_en_arbol_iterativa(const t_arbol*,const t_dato*,t_cmp);

t_nodo **buscar_en_arbol_y_retornar_direccion_del_padre_recursiva(t_arbol*,const t_dato*,t_cmp);
t_nodo **buscar_en_arbol_y_retornar_direccion_del_padre_recursiva_interna(t_arbol*,const t_dato*,t_cmp,t_arbol*);
t_nodo **buscar_en_arbol_y_retornar_direccion_del_padre_iterativa(t_arbol*,const t_dato*,t_cmp);

void grabar_arbol_en_inorden_en_archivo_binario(const t_arbol*,FILE*);
void grabar_arbol_en_preorden_en_archivo_binario(const t_arbol*,FILE*);
void grabar_arbol_en_posorden_en_archivo_binario(const t_arbol*,FILE*);

void grabar_arbol_en_inorden_en_archivo_de_texto(const t_arbol*,FILE*);
void grabar_arbol_en_preorden_en_archivo_de_texto(const t_arbol*,FILE*);
void grabar_arbol_en_posorden_en_archivo_de_texto(const t_arbol*,FILE*);

int cargar_arbol_con_archivo_binario_en_preorden(t_arbol*,FILE*,t_cmp);
int cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible(t_arbol*,FILE*,t_cmp);
int cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible_interna(t_arbol*,FILE*,t_cmp,int,int);

int calcular_altura(const t_arbol*);
int calcular_nivel(const t_arbol*);

int arbol_balanceado(const t_arbol*);
int arbol_semibalanceado(const t_arbol*);

int mostrar_y_contar_nodos(const t_arbol*,t_mst);
int mostrar_y_contar_hojas(const t_arbol*,t_mst);
int mostrar_y_contar_no_hojas(const t_arbol*,t_mst);

int mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(const t_arbol*,t_mst);
int mostrar_y_contar_nodos_con_hijos_solo_por_derecha(const t_arbol*,t_mst);
int mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(const t_arbol*,t_mst);
int mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(const t_arbol*,t_mst);
int mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(const t_arbol*,t_mst);

int mostrar_y_contar_nodos_de_un_nivel(const t_arbol*,int,t_mst);
int mostrar_y_contar_hasta_nivel(const t_arbol*,int,t_mst);
int mostrar_y_contar_hasta_nivel_inclusive(const t_arbol*,int,t_mst);
int mostrar_y_contar_desde_nivel(const t_arbol*,int,t_mst);
int mostrar_y_contar_desde_nivel_inclusive(const t_arbol*,int,t_mst);

void podar_hojas(t_arbol*);

t_nodo **buscar_nodo_menor(t_arbol*);
t_nodo **buscar_nodo_mayor(t_arbol*);

int eliminar_nodo_y_acomodar_ramas(t_arbol*,const t_dato*,t_cmp);
