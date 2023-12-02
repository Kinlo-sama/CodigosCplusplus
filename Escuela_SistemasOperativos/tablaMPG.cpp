#ifndef TABLA_MPG
#define TABLA_MPG
#include "Estructuras.h"

tablas_mpg * DATOS(int n,int i){
    tablas_mpg * nodo;
    nodo = (tablas_mpg*)malloc(sizeof(tablas_mpg));
    nodo->paginas = (int*)malloc(n *sizeof(int));
    nodo->loc_mar = (int*)malloc(n * sizeof(int));
    nodo->n_tarea = i;
    nodo->estado = 0;
    nodo->referencia = 0;
    nodo->modificacion = 0;
    return nodo;
}

void CREAR_TABLAS(){
    nodo_jt * aux= PLISTAJT;
    int i = 1;
    while(aux != NULL){
        int n_p = aux->tam;
        if(n_p % 100 != 0){
            n_p = n_p / 100;
            ++n_p;
        }
        else
            n_p /= 100;
        if(PTABLA == NULL){
                PTABLA = DATOS(n_p,i++);
                PTABLA->n = n_p;
                for(int i = 0; i < n_p;++i){
                    PTABLA->paginas[i] = i;
                    PTABLA->loc_mar[i] = 0;
                }
                PTABLA->sig = NULL;
                QTABLA = PTABLA;
        }else{
            Nueva_tabla = DATOS(n_p,++i);
            Nueva_tabla->n = n_p;
            for(int i = 0; i < n_p;++i){
                Nueva_tabla->paginas[i] = i;
                Nueva_tabla->loc_mar[i] = 0;
            }
            Nueva_tabla->sig = NULL;
            QTABLA->sig = Nueva_tabla;
            QTABLA = Nueva_tabla;
        }
        aux = aux->sig;
    }
}

int VER_TABLA(int n){
    int maximo = 0;
    AUXTABLA = PTABLA;
    int i = 1;
    while(AUXTABLA != NULL){
        if(i == n){
            printf("J%d\n",i++);
            printf("%-15s%-15s%-15s%-15s%-15s\n","No_Paginas","No_marco","Estado","Referencia","Modificacion");
            int n = AUXTABLA->n;
            for(int j = 0; j < n;++j){
                printf("P%-15d%-15d%-15d%-15d%-15d\n",AUXTABLA->paginas[j],AUXTABLA->loc_mar[j],AUXTABLA->estado,AUXTABLA->referencia,AUXTABLA->modificacion);
            }
            printf("\n");
            break;
        }
        ++i;
        AUXTABLA = AUXTABLA->sig;
    }
    return AUXTABLA->n;
}

#endif // TABLA_MPG
