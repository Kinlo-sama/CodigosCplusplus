#ifndef ALGO_RR
#define ALGO_RR
#include "Estructuras.h"
node_PCB * DATOS(node_PCB * otroNodo){
    node_PCB * nuevo = (node_PCB *)malloc(sizeof(node_PCB));
    nuevo->begin_sc = otroNodo->begin_sc;
    nuevo->cap_memory = otroNodo->cap_memory;
    nuevo->ciclos_sc = otroNodo->ciclos_sc;
    nuevo->cycles = otroNodo->cycles;
    nuevo->duration_sc = otroNodo->duration_sc;
    nuevo->estado = otroNodo->estado;
    nuevo->files = otroNodo->files;
    nuevo->name_page = otroNodo->name_page;
    nuevo->name_task = otroNodo->name_task;
    nuevo->next = otroNodo->next;
    nuevo->recursos = otroNodo->recursos;
    nuevo->time = otroNodo->time;
    nuevo->trp = otroNodo->trp;
    nuevo->type_process = otroNodo->type_process;
    return nuevo;
}

void meter_PCB_sem(node_PCB * item){
    node_PCB *current,*anterior_C;
    current = P_PCB;
    anterior_C = P_PCB;
    if(item == current){
        P_PCB = P_PCB->next;
    }
    else{
        current = current->next;
        while(current != NULL){
            if(current == item){
                anterior_C->next = current->next;
            }
            anterior_C = anterior_C->next;
            current = current->next;
        }
    }
    if(P_sem == NULL){
        P_sem = (PCB_sem * )malloc(sizeof(PCB_sem));
        P_sem->item_sc = DATOS(item);
        P_sem->next = NULL;
        Q_sem = P_sem;
    }else{
        New_sem = (PCB_sem * )malloc(sizeof(PCB_sem));
        New_sem->item_sc = DATOS(item);
        New_sem->next = NULL;
        Q_sem->next = New_sem;
        Q_sem = New_sem;
    }
}




void meter_Ahorro(int a){
    if(P_ahorro == NULL){
        P_ahorro = (ahorrosQ *)malloc(sizeof(ahorrosQ));
        P_ahorro->ahorros = a;
        P_ahorro->next = NULL;
        Q_ahorro = P_ahorro;
    }else{
        New_ahorro = (ahorrosQ *)malloc(sizeof(ahorrosQ));
        New_ahorro->ahorros = a;
        New_ahorro ->next = NULL;
        Q_ahorro->next = New_ahorro;
        Q_ahorro = New_ahorro;
    }
}

void ALGORITMO_RR(){
    node_PCB * current = P_PCB;
    int in_state_5 = 0;
    int ahorro_ronda = 0;
    int tiempos = 0;
    int quantums = QUANTUMS;
    while(in_state_5 != (Q_PCB->time+1)){
        bool salio = false;
        if(current->estado == 2 || current->estado == 4){
            current->estado = 3;
            VER_PCB(quantums);
            if((current->cycles-QUANTUMS) <= 0){//***********************************
                int cont = 0;
                bool acabo = true;

                while(current->cycles > 0){
                    --current->cycles;
                    ++cont;
                    if(current->begin_sc != 0)
                        ++current->ciclos_sc;
                    --quantums;
                    if(current->ciclos_sc == current->begin_sc && current->begin_sc != 0){
                        acabo = false;
                        salio = true;
                        break;
                    }
                    VER_PCB(quantums);
                }
                if(acabo)
                    current->estado = 5;
                else
                    current->estado = 4;
                quantums -= current->cycles;
                tiempos += current->cycles;
                ahorro_ronda += QUANTUMS - current->cycles;
                ++in_state_5;
            }
            if((current->cycles - QUANTUMS) > 0){//***********************************
                int cont = 0;
                while(cont != QUANTUMS){
                    --current->cycles;
                    ++cont;
                    if(current->begin_sc != 0)
                        ++current->ciclos_sc;
                    --quantums;
                    if(current->ciclos_sc == current->begin_sc && current->begin_sc != 0){
                        salio = true;
                        break;
                    }
                    VER_PCB(quantums);
                }
                //current->cycles -= quantums;
                //quantums = 0;
                current->estado = 4;
            }
            VER_PCB(quantums);
            if(current->cycles == 0){
                current->trp = tiempos - current->time;
            }
        }
        else if(current->estado == 1){
            ++current->estado;
            if(Q_PCB->estado == 2){
                ver_PCB_sem();
                VER_PCB(quantums);
            }
        }
        node_PCB *aux = current;
        current = current->next;
        if(salio)
            meter_PCB_sem(aux);
        quantums = QUANTUMS;
        if(current == NULL){
            node_PCB * actual = P_PCB;
            while(actual != NULL){
                if(actual->estado == 4)
                    actual->estado = 2;
                actual = actual->next;
            }
            current = P_PCB;
            if(current->estado != 2){
                meter_Ahorro(ahorro_ronda);
                ahorro_ronda = 0;
            }
        }
    }




    /*//Ahorros impresion
    printf("\n\nLista de ahorros por ronda\n");
    //******************************Ver la lista cuando se termine el algoritmo
    int i = 1,suma_ta = 0;//Suma de tiempo ahorrado
    ahorrosQ * ahorros = P_ahorro;
    while(ahorros != NULL){
        printf("Ronda%d:%d\n",i++,ahorros->ahorros);
        suma_ta += ahorros->ahorros;
        ahorros = ahorros->next;
    }
    printf("Total de tiempo ahorrado:%d\n\n",suma_ta);
    printf("Total de ciclos de CPU:%d\n",tiempos);
    printf("Tiempos de retorno promedio de cada proceso\n");
    current = P_PCB;
    while(current != NULL){
        printf("J%dP%d:%-5d\n",current->name_task,current->name_page,current->trp);
        current = current->next;
    }
    */
}

#endif // ALGO_RR
