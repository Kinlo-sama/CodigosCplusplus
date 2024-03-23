#include <iostream>
using namespace std;
//Pongo los ejemplos en funciones
void ejercicio1(void){
    int TC,a,b;
    cin >> TC;
    while(TC--){
        cin >> a >> b;
        cout << a + b << endl;
    }
}

void ejercicio2(void){
    int a,b;
    while((cin>> a >> b),(a || b)){
        cout << a + b << endl;
    }
}

void ejercicio3(void){
    int a,b;
    while(cin >> a >> b){
        cout << a + b << endl;
    }
}

void ejercicio4(void){
    int a,b,c = 1;
    while(cin >> a >> b){
        cout << "Case " << c++ <<":" << a + b << "\n\n";
    }//Aqui nos advierten de los saltos que nos ordenen mostrar
}

void ejercicio5(void){
    int k,ans,v;
    while(cin >> k){
        ans = 0;
        while(k--){
            cin >> v; ans += v;
        }
        cout << ans << endl;
    }
}


int main(){
    ejercicio5();
}
