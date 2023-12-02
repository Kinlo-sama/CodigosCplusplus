#ifndef TABLA_MMT
#define TABLA_MMT
#include "Estructuras.h"

nodo_MMT * DAR_DATOS_MMT(int m,int l,int e){
    nodo_MMT * nodo;
    nodo = (nodo_MMT*)malloc(sizeof(nodo_MMT));
    nodo->marco = m;
    nodo->loc_inicio = l;
    nodo->estado = e;
    return nodo;
}

void CREAR_MMT(){
    int i = 0;
    PLISTAMMT = DAR_DATOS_MMT(i++,0,1);
    PLISTAMMT->sig = NULL;
    QLISTAMMT = PLISTAMMT;
    for(i; i < MARCOS;++i){
        if(i < 5)//Son 0 y 1 para el SO
            Nueva_MMT = DAR_DATOS_MMT(i,TAM_MARCO*i,1);
        else
            Nueva_MMT = DAR_DATOS_MMT(i,TAM_MARCO*i,0);
        Nueva_MMT->sig = NULL;
        QLISTAMMT->sig = Nueva_MMT;
        QLISTAMMT = Nueva_MMT;
    }
}

void VER_MMT(){
    AUXMMT = PLISTAMMT;
    printf("%-15s%-15s%-15s\n","No_Marco","Loc_ini (KB)","Estado");
    while(AUXMMT != NULL)
    {
        printf("%-15d%-15d%-15d\n",AUXMMT->marco,AUXMMT->loc_inicio,AUXMMT->estado);
        AUXMMT = AUXMMT->sig;
    }
}

#endif // TABLA_MMT
