//Problema -> https://omegaup.com/course/introduccion_a_cpp/assignment/ciclos#problems/El-k-esimo-numero-primo
//Podemos usar la criba de erastostenes
#include <iostream>
#define tam 8000
using namespace std;

int main(){
    int K;
    int primos[tam+1];
    primos[1] = 0;
    for(int i = 2; i <= tam;++i){
        primos[i] = 1;
    }

    for(int i = 2; i < tam; ++i){
        for(int j = 2; j < (tam / i); ++j){
            primos[i*j] = 0;
        }
    }
    int k_primo;
    cin>>K;
    int cont = 1;
    for(int i = 0; i < tam; ++i){
        if(primos[i]== 1){
            if(cont == K){
                k_primo = i;
                break;
            }
            ++cont;
    }
    }
    cout<<k_primo;
}
