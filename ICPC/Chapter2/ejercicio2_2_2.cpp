#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int32_t dato;
    int32_t arr[N];//Un arreglo de N enteros
    size_t n = sizeof(arr) / sizeof(arr[0]);
    for(size_t i = 0; i < n; ++i){
        cin >> dato; arr[i] = dato;
    }
    //No se permite una complejidad mayor a n^2
    for(int i = 0; i < N/2; ++i){

    }

}
