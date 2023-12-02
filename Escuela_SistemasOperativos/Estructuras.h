#ifndef ESTRUCTURAS
#define ESTRUCTURAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NO_TAREAS 3
#define MARCOS 32
#define TAM_MARCO 64
#define MIN_CICLOS 2
#define MAX_CICLOS 15
#define QUANTUMS 5

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

nodo_MMT *PLISTAMMT,*QLISTAMMT,*AUXMMT,*Nueva_MMT;
nodo_jt *PLISTAJT, *QLISTAJT,*AUXJT,*Nueva_jt;
tablas_mpg *PTABLA,*QTABLA,*AUXTABLA,*Nueva_tabla;
node_PCB *P_PCB, *Q_PCB,*New_PCB;
ahorrosQ *P_ahorro, *Q_ahorro,*New_ahorro;
PCB_sem *P_sem,*Q_sem,*New_sem;

void VER_PCB(int q);
void meter_Ahorro(int a);
void ALGORITMO_RR();
void VERJT_N(int n);
void CREAR_TABLAS();
int VER_TABLA(int n);
int CREATE_PCB(int n);
void CREAR_JT();
void CREAR_MMT();
void VER_MMT();
void VER_JT();
void Algoritmo_din(int * arr,int n);
void VER_PCB();
void ORDENAR_MAYOR(node_PCB ** primero);
void AlgoritmoFCFS(int p);
void VER_PCB_TR(int *arreglo,int n);
void meter_PCB_sem(node_PCB*);
void sacar_PCB(node_PCB*);
void ver_PCB_sem();
node_PCB  * DATA(int nt,int np,int t,int c,int cm,int tp,int f,int tsu,int e);
tablas_mpg * DATOS(int n);
nodo_MMT * DAR_DATOS_MMT(int m,int l,int e);
nodo_jt * DAR_DATOS_JT(int nt,int tam,int pmt);
#endif // ESTRUCTURAS
