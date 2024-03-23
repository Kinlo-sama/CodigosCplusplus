#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int main(){
    VVI M(5);   //matriz de 5 filas vacias
    for(int i = 0; i < M.size(); ++i){
        M[i].resize(3);//Definimos cada fila con 5 elementos cada uno
    }
    VVI M2(5,VI(3));//Tenemos 5 vectores inicializados todos cono vectores de 3 elementos
    for(int i = 0; i < M.size();++i){
        for(int j = 0; j < M[i].size(); ++j){
            M[i][j] = M[i][j] = i + j;
        }
    }
    for(int i = 0; i < M.size();++i){
        for(int j = 0; j < M[i].size(); ++j){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
