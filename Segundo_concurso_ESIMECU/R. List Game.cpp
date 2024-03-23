#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;
/*
    I x colocar al final de la lista de paget y
*/
int main(){
        priority_queue<long long> AJ;
        queue<long long> Paget;
        int N;
        cin >> N;
        while(N--){
            char opcion;
            long long  mayor,frente,x;
            cin >> opcion;
            switch(opcion){
            case 'Q':
                if(not Paget.empty() and not AJ.empty()){
                    mayor = AJ.top();   frente = Paget.front();
                    AJ.pop();
                    Paget.pop();
                    cout << abs( mayor - frente) << endl;
                }
                else{
                    cout << "MARIOLA NO!" << endl;
                }
                break;
            case 'I':
                cin >> x;
                Paget.push(x);
                AJ.push(x);
                break;
            }
        }
}
