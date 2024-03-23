//Funciona para los 2 test
#include <stack>
#include <iostream>

using namespace std;

int main(){
    int N;
    int numero;
    cin >> N;
    stack<int> pilaPot;
    while(N--){
        cin >> numero;
        if(not pilaPot.empty()){
            int frente = numero;
            while(frente == pilaPot.top()){
                pilaPot.pop();
                pilaPot.push(frente + frente);
                frente = pilaPot.top();
                pilaPot.pop();
                if(pilaPot.empty())
                    break;
            }
            pilaPot.push(frente);

        }
        else{
            pilaPot.push(numero);
        }
    }
    if(not pilaPot.empty())
        cout << pilaPot.size() << endl;
    while(not pilaPot.empty()){
        cout << pilaPot.top() << endl;
        pilaPot.pop();
    }
}
