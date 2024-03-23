#include <iostream>
#include <list>

using namespace std;

int main(){
    int32_t N;
    char opcion;

    list<int> chemandria;
    list<int> chemandria_ordenada;

    cin >> N;
    while(N--){
        cin >> opcion;
        int dato;
        int frente,atras;
        switch(opcion){
        case 'A':
            cin >> dato;
            chemandria.push_back(dato);
            break;
        case 'B':
            frente = chemandria.front();
            chemandria.pop_front();
            cout << frente << endl;
            break;
        case 'C':
            atras = chemandria.back();
            chemandria.pop_back();
            cout << atras << endl;
            break;
        case 'D':
            chemandria_ordenada.assign(chemandria.begin(),chemandria.end());
            chemandria_ordenada.sort();
            for(int elemento: chemandria_ordenada)
                cout << elemento << " ";
            cout << endl;
            break;
        case 'E':
            cout << chemandria.size() << endl;
            break;
        }
        }
}
