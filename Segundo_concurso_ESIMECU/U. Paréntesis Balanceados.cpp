#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int N;

    cin >> N;

    while(N--){
        bool balanceado = true;
        stack<char> primeros;
        queue<char> segundos;
        string caso;    cin >> caso;
        for(int i = 0; i < caso.size();++i)
            if(caso[i] == '{' || caso[i] == '(' || caso[i] == '[')
                primeros.push(caso[i]);
            else
                segundos.push(caso[i]);
        while(not primeros.empty() and not segundos.empty()){
            if((primeros.top() == '(' and segundos.front() != ')') ||
              (primeros.top() == '[' and segundos.front() != ']') ||
              (primeros.top() == '{' and segundos.front() != '}')) {
                balanceado = false;
                break;
            }
            primeros.pop(); segundos.pop();
        }
        if(balanceado and primeros.empty() and segundos.empty())
            cout << "SI" << endl;
        else
            cout << "NO" << endl;
    }
}

