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
    nuevo->sem = otroNodo->sem;
    nuevo->w_s = otroNodo->w_s;
    nuevo->s_s = otroNodo->s_s;
    nuevo->interrupcion = otroNodo->interrupcion;
    return nuevo;
}

void sacar_RR(node_PCB * item){
    node_PCB *current,*anterior_C;//siguiente y el anterior a siguiente
    current = P_PCB;
    anterior_C = P_PCB;
    if(item == current){
        P_PCB = P_PCB->next;
    }else if(item == Q_PCB){
            New_PCB = DATOS(item);
            New_PCB->next = NULL;
            Q_PCB->next = New_PCB;
            Q_PCB = New_PCB;
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
}

void meter_PCB_sem(node_PCB * item){
    node_PCB *current,*anterior_C;//siguiente y el anterior a siguiente
    current = P_PCB;
    anterior_C = P_PCB;
    if(item == current){
        P_PCB = P_PCB->next;
    }else if(item == Q_PCB){
            New_PCB = DATOS(item);
            New_PCB->next = NULL;
            Q_PCB->next = New_PCB;
            Q_PCB = New_PCB;
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

void wait(){
    --P_sem->item_sc->sem;
    if(P_sem->item_sc->sem < 0){
        --P_sem->item_sc->cycles;
        --P_sem->item_sc->duration_sc;
        if(P_sem->item_sc->cycles == 0){
            P_sem->item_sc->estado = 5;
            P_sem->item_sc->sem = 0;
        }
        if(P_sem->item_sc->duration_sc == 0){
            P_sem->item_sc->sem = 0;
        }
    }
}

void signal(){
    ++P_sem->item_sc->sem;
    if(P_sem->item_sc->sem > 0){
        P_sem->item_sc->sem = 1;
        P_sem->item_sc->s_s = 1;
        P_sem->item_sc->w_s = 0;
    }
}

int semaforo(){
    int estado_5 = 0;
    if(P_sem != NULL){
        if(P_sem->item_sc->estado == 5)
            estado_5 = 1;
        if(P_sem->item_sc->s_s == 1){
            int t_l = P_sem->item_sc->time;//ubicamos el tiempo de llegada del proceso i/o
            node_PCB *current,*ant_current;
            current = P_PCB;
            ant_current = P_PCB;
            if(t_l == 0){
                P_sem->item_sc->next = P_PCB;
                P_PCB = P_sem->item_sc;
            }else if(t_l == Q_PCB->time+1){
                    P_sem->item_sc->next = NULL;
                    Q_PCB->next = P_sem->item_sc;
                    Q_PCB = P_sem->item_sc;
                }
                    else{
                        current = current->next;
                        while(current != NULL){
                            if(t_l == current->time - 1){
                                New_PCB = DATOS(P_sem->item_sc);
                                ant_current->next = New_PCB;
                                New_PCB->next = current;
                            }
                            ant_current = ant_current->next;
                            current = current->next;
                        }
                    }
            if(P_sem->next == NULL){
                P_sem = NULL;
            }else{
                P_sem = P_sem->next;
            }
        }
    }
    if(P_sem != NULL){
        wait();
        signal();
    }
    return estado_5;
}



void ALGORITMO_RR(){
    node_PCB * current = P_PCB;
    int in_state_5 = 0;
    int ahorro_ronda = 0;//ignorar por ahora en semaforo
    int tiempos = 0;//ignorado por ahora en semaforo
    int quantums = QUANTUMS;
    while(in_state_5 != (Q_PCB->time+1)){
        bool salio = false;
        bool interrupcion = false;
        if(current->estado == 2 || current->estado == 4){
            current->estado = 3;
            VER_PCB(quantums);
            if((current->cycles-QUANTUMS) <= 0){//****************Al usar todos los quantums podriamos ir al estado 5
                bool acabo = true;
                while(current->cycles > 0){
                    --current->cycles;
                    in_state_5 += semaforo();
                    if(current->begin_sc != 0)
                        ++current->ciclos_sc;
                    --quantums;
                    /*
                    if(current->ciclos_sc == current->begin_sc && current->begin_sc != 0){
                        acabo = false;
                        salio = true;
                        break;
                    }
                    */
                    if(current->begin_sc != 0 && current->ciclos_sc == current->begin_sc){
                        if(current->interrupcion ==  14 || current->interrupcion == 16){
                            acabo = false;
                            salio = true;
                            break;
                        }
                        else{
                            switch(current->interrupcion){
                            case 0:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Error...division entre 0");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 2:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Interrupcion no enmascarable");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 8:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Tictac del reloj de hardware");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 14:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("¡Atencion al diskette!");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 20:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Invoca servicios de comunicaciones de la ROM BIOS");
                                getchar();
                                system("cls");

                                break;
                            case 25:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("RESET");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 27:
                                interrupcion = true;
                                while (getchar() != '\n');
                                interrupcion = true;
                                printf("Interrupcion de la ROM BIOS para Ctrl-Break");
                                getchar();
                                system("cls");

                                break;
                            case 28:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Interrupcion generada con cada pulso de reloj");
                                getchar();
                                system("cls");
                                break;
                            case 47:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Interrupcion miltiple del DOS");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            }
                        }
                    }
                    if(interrupcion){
                        current->estado = 5;
                        break;
                    }
                    VER_PCB(quantums);
                }
                if(acabo){
                    current->estado = 5;
                    ++in_state_5;//Si entra en estado significa que un proceso acabo
                }
                else
                    current->estado = 4;

                tiempos += current->cycles;//Lo dejamos por ahora
                ahorro_ronda += QUANTUMS - current->cycles;

            }
            if((current->cycles - QUANTUMS) > 0){//**************Al usar todos los quantums no podrias ir al estado 5
                while(quantums--){
                    --current->cycles;
                    in_state_5 += semaforo();
                    if(current->begin_sc != 0)
                        ++current->ciclos_sc;//Aqui copeo
                    if(current->begin_sc != 0 && current->ciclos_sc == current->begin_sc){
                        if(current->interrupcion ==  14 || current->interrupcion == 16){
                            salio = true;
                            break;
                        }
                        else{
                            switch(current->interrupcion){
                            case 0:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Error...division entre 0");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 2:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Interrupcion no enmascarable");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 8:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Tictac del reloj de hardware");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 14:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("¡Atencion al diskette!");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 20:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Invoca servicios de comunicaciones de la ROM BIOS");
                                getchar();
                                system("cls");

                                break;
                            case 25:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("RESET");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            case 27:
                                interrupcion = true;
                                while (getchar() != '\n');
                                interrupcion = true;
                                printf("Interrupcion de la ROM BIOS para Ctrl-Break");
                                getchar();
                                system("cls");

                                break;
                            case 28:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Interrupcion generada con cada pulso de reloj");
                                getchar();
                                system("cls");
                                break;
                            case 47:
                                interrupcion = true;
                                while (getchar() != '\n');
                                printf("Interrupcion multiple del DOS");
                                getchar();
                                system("cls");
                                interrupcion = true;
                                break;
                            }
                        }
                    }
                    if(interrupcion){
                        current->estado = 5;
                        break;
                    }
                    VER_PCB(quantums);
                }
                //current->cycles -= quantums;
                //quantums = 0;
                if(!interrupcion)
                    current->estado = 4;
            }
            VER_PCB(++quantums);
            if(current->cycles == 0){//************No sirve por ahora pero lo dejamos por si acaso lo necesitaramos
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
        if(interrupcion)
            sacar_RR(aux);
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
