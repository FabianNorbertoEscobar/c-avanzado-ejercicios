#define     TAM     10

typedef struct
    {
    int d,
        m,
        a;
    }t_fecha;

typedef struct
    {
    char cod[8];
    char desc[16];
    char prov[16];
    t_fecha f_comp;
    t_fecha f_venc;
    int cant;
    float prec_comp;
    float prec_vent;
    }t_dato;
