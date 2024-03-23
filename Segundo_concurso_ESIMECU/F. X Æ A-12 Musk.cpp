#include <map>
#include <iostream>
#include <vector>
/*
1
6
1 1 2 2 2 3
*/
using namespace std;

int main(){
    int T,N,Ni;
    cin >> T;
    while(T--){
        map<int,int> frecuencias;//key -> numero, value -> frecuencia de numero
        cin >> N;//Cuantos numeros
        vector<int> numeros,resultados;//Que numeros y en donde se guardan los resultados
        while(N--){
            cin >> Ni;
            numeros.push_back(Ni);
        }
        for(int i = 0; i < numeros.size(); ++i){
            ++frecuencias[numeros[i]];
        }

        int frecuencia_enc;
        for(int i = 0; i < numeros.size(); ++i){
            bool encontrado = false;
            for(int j = i; j < numeros.size(); ++j){
                if(frecuencias[numeros[j]] > frecuencias[numeros[i]]){
                    frecuencia_enc = numeros[j];
                    encontrado = true;
                    break;//rompemos para no encontrar al siguiente mas grande si no al mas cercano y mas grande
                }
            }
            if(encontrado)
                resultados.push_back(frecuencia_enc);
            else
                resultados.push_back(-1);
        }
        for(int i = 0; i < resultados.size(); ++i ){
            cout << resultados[i] << " ";
        }
        cout << endl;
    }
}
