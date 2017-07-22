#include "dato.h"

#define     MEMORIA_LLENA       0
#define     LISTA_VACIA         0
#define     OK                  1

typedef struct s_nodo
    {
    t_dato dato;
    struct s_nodo *sig;
    }t_nodo;

typedef t_nodo* t_lista;

typedef int(*t_cmp)(const void*,const void*);

void crear_lista(t_lista*);
int lista_vacia(const t_lista*);
int sacar_de_lista_primero(t_lista*,t_dato*);
int insertar_en_lista_ordenado_con_duplicado(t_lista*,const t_dato*,t_cmp);
