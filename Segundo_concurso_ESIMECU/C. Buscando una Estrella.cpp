#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct compare{//Cambiamos el orden de las cola de prioridad para que vaya guardando de menor a mayor
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

int main(){
    priority_queue<int,vector<int>,compare> estrellas;
    int N; //instrucciones
    cin >> N;
    while(N--){
        char opcion;
        cin >> opcion;
        switch(opcion){
        case 'B'://eliminar al mas bajo
            estrellas.pop();
            break;
        case 'R'://recibir un estrella con un puntaje
            int puntaje;    cin >> puntaje;
            estrellas.push(puntaje);
            break;
        case 'S'://saber los 3 peores
            if(estrellas.size() >= 3){
                stack<int>pilaAux;
                for(int i = 0; i < 3; ++i){
                    cout << estrellas.top() << " ";
                    pilaAux.push(estrellas.top());
                    estrellas.pop();
                }
                cout << endl;
                for(int i = 0; i < 3; ++i){
                    estrellas.push(pilaAux.top());
                    pilaAux.pop();
                }
            }else{
                cout << "NO HAY SUFICIENTES PUNTAJES" << endl;
            }
            break;
        }
    }
    if(estrellas.size() > 0){
        int estrella_final;
        while(not estrellas.empty()){
            estrella_final = estrellas.top();
            estrellas.pop();
        }
        cout << "EL PUNTAJE MAS ALTO FUE " << estrella_final << endl;
    }else{
        cout << "NO HUBO GANADOR" << endl;
    }
}
