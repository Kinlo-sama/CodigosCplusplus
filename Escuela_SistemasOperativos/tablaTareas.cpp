#ifndef TABLA_TAREAS
#define TABLA_TAREAS
#include "Estructuras.h"

nodo_jt * DAR_DATOS_JT(int nt,int tam,int pmt){
    nodo_jt * nodo;
    nodo = (nodo_jt *)malloc(sizeof(nodo_jt));
    nodo->no_tarea = nt;
    nodo->tam = tam;
    nodo->loc_pmt = pmt;
    int n = tam;
    if(n % 100 != 0){
        n = n / 100;
        ++n;
    }
    else
        n /= 100;
    int n_ = n;
    n = rand()%(n - 2) + 2;
    nodo->secuencia = (int *)malloc(n * sizeof(int));
    int dato;
    --n;

    for(int i = 0; i <= n;++i){
        dato = rand()%n_;
        nodo->secuencia[i] = dato;
    }
    nodo->size_sec = n+1;
    return nodo;
}

void CREAR_JT(){
    int i = 1;
    int lineas = rand()%500 + 300;
    int loc = rand()%19000;
    PLISTAJT = DAR_DATOS_JT(i++,lineas,loc);
    PLISTAJT->sig = NULL;
    QLISTAJT = PLISTAJT;
    for(i; i <= NO_TAREAS; ++i){
        lineas = rand()%1000 + 300;
        Nueva_jt = DAR_DATOS_JT(i,lineas,++loc);
        Nueva_jt->sig = NULL;
        QLISTAJT->sig = Nueva_jt;
        QLISTAJT = Nueva_jt;
    }
}

void VER_JT(){
    AUXJT = PLISTAJT;
    printf("%-15s%-15s%-15s%-15s\n","No_Tarea","Tam(Lineas)","Loc_PMT(KB)","Secuencia");
    while(AUXJT != NULL)
    {
        printf("%-15d%-15d%-15d ",AUXJT->no_tarea,AUXJT->tam,AUXJT->loc_pmt);
        for(int i = 0; i < AUXJT->size_sec;++i){
            printf("%d ",AUXJT->secuencia[i]);
        }
        printf("\n");
        AUXJT = AUXJT->sig;
    }
}

#endif // TABLA_TAREAS
