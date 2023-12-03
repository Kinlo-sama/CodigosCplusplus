#ifndef TABLA_PCB
#define TABLA_PCB
#include "Estructuras.h"

void VER_PCB_TR(int *arreglo,int n){
    int i = 0;
    printf("\t\t\t\t\t\t\tTABLA PCM\n");
    node_PCB *aux = P_PCB;
    printf("%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-19s\n","Proceso","T.Llegada","Ciclos(ms)","CPU/E/O","Estado","    TR");
    while(aux != NULL){
        printf(" J%02dP%02d%17d%15d%13s%16d%15d%15s%18d%10d%15d\n",aux->name_task,aux->name_page,aux->time,aux->cycles,aux->type_process,aux->estado,arreglo[i++]);
        aux = aux->next;
    }
}

void VER_PCB(){
    while (getchar() != '\n');
    printf("...");
    getchar();
    system("cls");
    printf("\t\t\t\t\t\t\tTABLA PCM\n");
    node_PCB *aux = P_PCB;
    printf("%-15s%-15s%-15s%-15s%-10s%-15s%-15s%-15s\n","Proceso","T.Llegada","Ciclos(ms)","CPU/E/O","Estado","Inicio_SC","Duracion_SC","Ciclos_sc");
    while(aux != NULL){
        printf(" J%02dP%02d%17d%15d%13s%14d%13d%17d%13d\n",aux->name_task,aux->name_page,aux->time,aux->cycles,aux->type_process,aux->estado,aux->begin_sc,aux->duration_sc,aux->ciclos_sc);
        aux = aux->next;
    }
}

node_PCB * DATA(int nt,int np,int t,int c,int cm,int tp,int f,int tsu,int e){
    node_PCB * node;
    node = (node_PCB *)malloc(sizeof(node_PCB));
    node->type_process = (char*)malloc(15 *sizeof(char));
    node->type_su = (char*)malloc(15 * sizeof(char));
    node->name_task = nt;
    node->name_page = np;
    node->time = t;
    node->cycles = c;
    node->cap_memory = cm;
    if(tp != 0){
        node->begin_sc = rand()%(c-1) + 1;
        int tam_sc = rand()%3 + 1;
        while((tam_sc + node->begin_sc) > c){
            --tam_sc;
        }
        node->duration_sc = tam_sc;
    }else{
        node->begin_sc = 0;
        node->duration_sc  = 0;
    }
    if(tp == 0){
        strcpy(node->type_process,"CPU");
    }
    else
        strcpy(node->type_process,"I/O");
    if(tsu == 0){
        strcpy(node->type_su,"Sistema");
    }
    else
        strcpy(node->type_su,"Usuario");
    node->files = f;
    node->estado = e;
    if(tp == 1){
        node->recursos = rand()% 10;
    }
    else{
        node->recursos = 0;
    }
    node->ciclos_sc = 0;
    node->sem = 0;
    node->w_s = 1;
    node->s_s = 0;
    return node;
}

int CREATE_PCB(int n){
    nodo_jt * tarea_actual = PLISTAJT;
    int tarea = 1;
    int time = 0;
    int total = 0;//*****************************************Para acumular los procesos por tarea
    int j = 0;
    while(tarea_actual != NULL){//***************************Iteramos por la lista de tareas
        int no_procesos = tarea_actual->size_sec;//**********Procesos de cada tarea
        total += no_procesos;
        while(no_procesos--){
            int ciclos,capacidad,pro,files,su,estado;
            ciclos = rand()%(MAX_CICLOS-MIN_CICLOS) + MIN_CICLOS;
            capacidad = rand()%11 +5;
            pro = rand()%2;
            files = rand()%11 + 5;
            su = rand()%2;
            estado = 1;
            if(P_PCB == NULL){
                P_PCB = DATA(tarea,tarea_actual->secuencia[j++],time++,ciclos,capacidad,pro,files,su,estado);
                P_PCB->next = NULL;
                Q_PCB = P_PCB;
            }
            else{
                New_PCB = DATA(tarea,tarea_actual->secuencia[j++],time++,ciclos,capacidad,pro,files,su,estado);
                New_PCB->next = NULL;
                Q_PCB->next = New_PCB;
                Q_PCB = New_PCB;
            }
        }
        j=0;
        ++tarea;
        tarea_actual = tarea_actual->sig;
    }
    return total;

}

void ver_PCB_sem(){
    printf("\n");
    printf("\t\t\t\t\t\t\tTABLA PCM_SEM\n");
    PCB_sem *auxP = P_sem;
    printf("%-15s%-15s%-15s%-10s%-15s%-15s%-15s%-15s%-15s%-15s\n",
           "Proceso","T.Llegada","Ciclos(ms)","Estado","Inicio_SC","Duracion_SC","Ciclos_sc","Semaforo","Wait(sem)","Signal(sem)");
    while(auxP != NULL){
        node_PCB *aux = auxP->item_sc;
        printf(" J%02dP%02d%16d%17d%11d%13d%17d%13d%14d%16d%17d\n",
               aux->name_task,aux->name_page,aux->time,aux->cycles,aux->estado,aux->begin_sc,aux->duration_sc,aux->ciclos_sc,aux->sem,aux->w_s,aux->s_s);
        auxP = auxP->next;
    }
}

void VER_PCB(int q){
    while (getchar() != '\n');
    printf("...");
    getchar();
    system("cls");
    printf("\t\t\t\t\t\t\tTABLA PCM\n");
    node_PCB *aux = P_PCB;
    printf("Quantums:%d\n",q);
    printf("%-15s%-15s%-15s%-15s%-10s%-15s%-15s%-15s\n","Proceso","T.Llegada","Ciclos(ms)","CPU/E/O","Estado","Inicio_SC","Duracion_SC","Ciclos_sc");
    while(aux != NULL){
        printf(" J%02dP%02d%17d%15d%13s%14d%13d%17d%13d\n",aux->name_task,aux->name_page,aux->time,aux->cycles,aux->type_process,aux->estado,aux->begin_sc,aux->duration_sc,aux->ciclos_sc);
        aux = aux->next;
    }
    ver_PCB_sem();
}

#endif // TABLA_PCB
