#include <stdio.h>
//Determinar determinante de matriz cuadrada 2x2
int detCua(int mat[2][2]){
    int izq = mat[0][0] * mat[1][1];
    int der = mat[0][1] * mat[1][0];
    return izq - der;
}
//Prueba para encontrar primero los menores
int Menor(int m[3][3],int mi,int mj){
//Para iterar por la matriz cuadrada
    int iM = 0,jM = 0;
//la matriz cuadrada
    int m_cua[2][2];
//For para extraer los elementos dentro de la menor especifica
    for(int i = 0; i < 3; ++i){
        if(i == mi)//Ignoramos la fila mi
            continue;
        for(int j = 0; j < 3; ++j){
            if(j == mj)//Ignoramos la columan mj
                continue;
            m_cua[iM][jM++] = m[i][j];//Agregamos los valores a la matriz cuadrada
        }
        ++iM;
        jM = 0;
    }
    int menor = detCua(m_cua);//Calculamos la determinante de la menor
    return menor;
}


int main(){
    int a[3][3] = {{1,-2,5},{3,-3,-1},{0,4,2}};
    printf("Matriz Origen\n");
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j)
            printf("%d ",a[i][j]);
        printf("\n");
    }
/*
La matriz se ve asi
1 -2 5
3 -3 -1
0 4 2
Ahora encontraremos todos los menores de la matriz y los almacenamos en una matriz
*/
    printf("Menores\n");
    int mMenores[3][3];
    for(int i = 0; i < 3;++i){
        for(int j = 0; j < 3; ++j){
            mMenores[i][j] = Menor(a,i,j);
        }
    }
    //Y los visualizamos en una matriz
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j)
            printf("%d ",mMenores[i][j]);
        printf("\n");
    }

printf("\nMatriz de Coefactores\n");
//Ahora solo falta generar la matriz de cofactores
//Se usa la siguiente formula C(i,j) = [(-1)^(i+j)] * (menor(i,j))
//Para siplificar si i + j es par entonces (menor(i,j)
//Si no entonces -(menor(i,j)
    int mCoefactores[3][3];
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            mCoefactores[i][j] = (i+j % 2 == 0) ? mMenores[i][j] : -mMenores[i][j];
        }
    }
    //Visualizamos la matriz de coefactores
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j)
            printf("%d ",mCoefactores[i][j]);
        printf("\n");
    }
}
