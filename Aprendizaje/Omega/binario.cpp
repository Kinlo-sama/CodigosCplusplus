//El problema aqui -> https://omegaup.com/course/introduccion_a_cpp/assignment/funciones#problems/binario_cpp
#include <iostream>
using namespace std;

void bin(int n){
    if(n == 1)
        cout<<1;
    else{
        bin(n/2);
        cout<<" "<<n%2;
    }
}

int main(){
    int N; cin>>N;
    bin(N);
}
