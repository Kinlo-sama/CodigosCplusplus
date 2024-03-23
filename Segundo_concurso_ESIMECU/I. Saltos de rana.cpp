#include <iostream>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    // 10010101
    string camino;
    cin >> camino;
    int actual = 0;
    int i;
    bool salida = true;
    for(i = 0; i < N; ++i){
        for(int j = M; j > 0; --j){
            if((j+actual < N) and camino[j+actual] == '1'){
                actual += j;
                break;
            }
            if(j == 1){
                salida = false;
                break;
            }
        }
        if(!salida)
            break;
        if(actual == N-1)
            break;
    }
    if(salida)
        cout << i + 1;
    else
        cout << -1;
}
