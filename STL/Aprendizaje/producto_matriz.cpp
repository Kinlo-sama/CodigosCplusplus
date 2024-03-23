#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriz;

Matriz producto(const Matriz &ma,const Matriz &mb){
    int nfa = ma.size(), nca = ma[0].size(), ncb = mb[0].size();
    //recuerda que el producto de matrices es
    // ( a x b ) ( c x d) en donde c y b tienen que ser iguales
    Matriz m(nfa,Fila(ncb));//creamos una matriz ( a x d )
    for(int i = 0; i < nfa; ++i){
        for(int j = 0; j < ncb;++j){
            for(int k = 0; k < nca; ++k){
                m[i][j] += ma[i][k] * mb[k][j];
            }
        }
    }
    return  m;
}

int main(){
//Usalo, o puedes solo comprobar que realmente funcione de esa manera el producto
}
