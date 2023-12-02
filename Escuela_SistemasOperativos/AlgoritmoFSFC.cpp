#ifndef ALGO_FCFS
#define ALGO_FCFS
#include "Estructuras.h"
void AlgoritmoFCFS(int p){
    bool terminado = false;
    double trp;
    node_PCB * current = P_PCB;
    int t = 0,cont_t = 0;
    int k = 0;
    int * arreglo = (int *)malloc(p * sizeof(int));
    int actual = 0;
    arreglo[actual] = current->cycles;
    while(Q_PCB->estado != 5){
        if(current->estado == 1){
            ++current->estado;
        }
        if(!terminado){
            if(current->next != NULL){
                arreglo[actual+1] = current->next->cycles + arreglo[actual];
            }
            ++actual;
        }
        current = current->next;
        if(current == NULL){
            VER_PCB();
            printf("...");
            getchar();
            system("cls");
            current = P_PCB;
            terminado = true;
        }
        while(current->cycles != 0 && terminado){
            --current->cycles;
            current->estado = 3;
            VER_PCB();
            printf("...");
            getchar();
            system("cls");
            if(current->cycles -1 == 0){
                --current->cycles;
                terminado = true;
                break;
            }
        }
        if(terminado){
            current->estado = 5;
            if(current->next != NULL)
                current->next->estado = 3;
        }
    }
    VER_PCB();
    printf("\n");
    printf("...");
    getchar();
    system("cls");
    printf("\n");
    VER_PCB_TR(arreglo,p);
    float suma = 0,promedio;
    for(int i = 0; i < p;++i)
        suma += arreglo[i];
    promedio = suma / p;
    printf("\nTiempo de retorno promedio del sistema(TRPS): %.0f/%d = %.2fms\n",suma,p,promedio);
    printf("...");
    getchar();
    system("cls");

}

void ORDENAR_MAYOR(node_PCB ** primero){
    //Primero inicializamos  una lista vacia
    node_PCB * lista_ordenada = NULL;
    node_PCB * current = *primero;
    //Mientras no lleguemos al final de la lista
    while(current != NULL){
        node_PCB * siguiente = current->next;
        //En caso de que sea la primera iteracion o el dato almacenado en la lista ordenada al final es mayor al current
        if(lista_ordenada == NULL || lista_ordenada->cycles >= current->cycles){
            current->next = lista_ordenada; //eliminamos el elemento siguiente de current
            lista_ordenada = current;//el elemento en lista_ordenada actualmente
        }else{
            node_PCB *current_ordenado = lista_ordenada;
            while(current_ordenado->next != NULL && current_ordenado->next->cycles < current->cycles){
                current_ordenado = current_ordenado->next;
            }
            current->next = current_ordenado->next;
            current_ordenado->next = current;
        }
        current = siguiente;
    }
    *primero = lista_ordenada;
}

#endif // ALGO_FCFS
