#include <iostream>
#include <queue>
using namespace std;
int main(){
    int C,A;//C comida y A de acciones
    queue<int> colaCanguros;
    cin >> C >> A;
    while(A--){
        char opcion;
        cin >> opcion;
        switch(opcion){
        case 'N':
            int canguros;
            cin >> canguros;
            colaCanguros.push(canguros);
            break;
        case 'A':
            C -= colaCanguros.front() + 1;
            colaCanguros.pop();
            break;
        case 'C':
            cout << colaCanguros.size() << endl;
            break;
        case 'R':
            cout << C << endl;
            break;
        }
    }
}
