#include "dato.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     COLA_VACIA          0
#define     MEMORIA_LLENA       0
#define     OK                  1

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_lista;

void crear_cola(t_lista*);
int cola_vacia(const t_lista*);
int cola_llena(const t_lista*);
int acolar(t_lista*,const t_dato*);
int desacolar(t_lista*,t_dato*);
int ver_primero_en_cola(const t_lista*,t_dato*);
int ver_ultimo_en_cola(const t_lista*,t_dato*);
void vaciar_cola(t_lista*);
