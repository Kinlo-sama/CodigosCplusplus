#ifndef ESTRUCTURAS
#define ESTRUCTURAS

struct ahorrosQ{
    int ahorros;
    ahorrosQ * next;
};

struct node_PCB{
    int trp;
    int name_task;
    int name_page;
    int time;
    int cycles;//ms
    int cap_memory;//KB
    char * type_process;//0 CPU and 1 I/O
    int recursos;//if have I/O process
    int files;
    char * type_su;//0 system/1 user
    int estado;
    int begin_sc;
    int duration_sc;
    node_PCB * next;
    int ciclos_sc;
};

struct PCB_sem{
    node_PCB *item_sc;
    PCB_sem * next;
};
struct nodo_MMT{
    int marco;
    int loc_inicio;
    int estado;
    nodo_MMT * sig;
};

struct nodo_jt{
    int no_tarea;
    int tam;
    int loc_pmt;
    int * secuencia;
    int size_sec;
    nodo_jt * sig;
};

struct tablas_mpg{//tabla de mapa de paginas
    int n_tarea;
    int n;
    int * paginas;
    int * loc_mar;
    int estado;
    int referencia;
    int modificacion;
    tablas_mpg * sig;
};
#endif // ESTRUCTURAS
