#include <iostream>
using namespace std;
// *.*.
int main(){
    int N,D,i,actual = 0;
    cin >> N >> D;
    string camino;
    cin >> camino;
    bool salio = false,imposible = false;
    for(i = 0; i < N; ++i){
        for(int j = D;j > 0; --j){
            if((j + actual) > N){
                salio = true;
                break;
            }
            if((j + actual < N) and camino[j + actual] == '.'){
                actual += j;
                break;
            }
            if(j == 1){
                imposible = true;
                break;
            }
        }
        if(imposible || salio )
            break;

    }
    if(imposible)
        cout <<-1<< endl;
    else
        cout <<i + 1<< endl;
}
