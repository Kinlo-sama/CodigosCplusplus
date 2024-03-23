#include <vector>
#include <iostream>

using namespace std;

int main(){
    int N;  cin >> N;
    while(N--){
        long long numero;
        cin >> numero;
        vector<bool> es_primo(numero+1,true);
        es_primo[0] = es_primo[1] = false;
        for(int p = 2; p * p <= numero; ++p){
            if(es_primo[p]){
                for(int i = p * p; i <= numero; i += p){
                    es_primo[i] = false;
                }
            }
        }
        int con = 0;
        for(int i = 2; i <= numero; ++i){
            if(es_primo[i]){
                ++con;
            }
        }
        cout << con << endl;
    }
}
