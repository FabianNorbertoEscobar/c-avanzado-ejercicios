#include "dato.h"

#define     LISTA_LLENA     0
#define     LISTA_VACIA     0
#define     OK              1

typedef struct
    {
    t_dato dato[TAM];
    int pos[TAM];
    int indice;
    int ce;
    }t_lista;

typedef int(*t_cmp)(const void*,const void*);

void crear_lista(t_lista*);
int lista_vacia(const t_lista*);
int lista_llena(const t_lista*);
int poner_en_lista(t_lista*,const t_dato*,t_cmp);
int sacar_de_lista(t_lista*,t_dato*);
int ver_primero_de_lista(const t_lista*,t_dato*);
void vaciar_lista(t_lista*);
