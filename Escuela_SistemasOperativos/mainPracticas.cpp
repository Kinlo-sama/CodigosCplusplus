#include "Estructuras.h"
#include "tablaTareas.cpp"
#include "tablaMPG.cpp"
#include "tablaMMT.cpp"
#include "tablaPCB.cpp"
#include "AlgoritmoFSFC.cpp"
#include "AlgoritmoRR.cpp"



int main(){
    srand(time(NULL));

    //*****************************Inicializacion de punteros a NULL
    P_PCB = NULL;    Q_PCB = NULL;    New_PCB = NULL;
    PLISTAMMT = NULL; QLISTAMMT = NULL; AUXMMT = NULL; Nueva_MMT = NULL;
    PLISTAJT = NULL; QLISTAJT = NULL; AUXJT = NULL; Nueva_jt = NULL;
    PTABLA = NULL; QTABLA = NULL; AUXTABLA = NULL; Nueva_tabla = NULL;
    P_ahorro = NULL; Q_ahorro = NULL; New_ahorro = NULL;
    P_sem = NULL; Q_sem = NULL; New_sem = NULL;
    //Fin de inicializacion de punteros

    CREAR_JT();//******************Creacion de tablas
    CREAR_MMT();
    CREAR_TABLAS();//**************Fin

    printf("Tabla de tareas\n");
    VER_JT();//*******************VER TODAS LAS TAREAS DISPONIBLES
    int procesos_m = 0;
    /*
    //***********VISUALIZAR TODAS LAS TAREAS CON PROCESOS
    for(int i = 1; i <= NO_TAREAS; ++i){
        VER_TABLA(i);
    }
    */
    procesos_m = CREATE_PCB(NO_TAREAS);//OBTENER TOTAL DE PROCESOS

    VER_PCB();//******************VER COMO SE VE LA PCB POR PRIMERA VEZ


    //****************************Algoritmo RR
    ALGORITMO_RR();
    /*
    //****************************Algoritmo FCFS
    while (getchar() != '\n');
    printf("...");
    getchar();
    system("cls");
    AlgoritmoFCFS(procesos_m);
    */
    return 0;
}








