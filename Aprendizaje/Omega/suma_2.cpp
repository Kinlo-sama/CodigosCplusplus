#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int J,F;
    cin >> J >> F;
    vector<long long>numJ;

    int dato;
    while(J--){
        cin >> dato;
        numJ.push_back(dato);
    }
    sort(numJ.begin(),numJ.end());
    long long  suma = 0,cont = 0,n,k;
    if(numJ[0] != 1){
        if((numJ[0] - 1) > F){
            n = F;
        }
        else
            n = numJ[0] - 1;
        suma += (n * (n + 1)) / 2;
        cont = n;
    }
//******************Hasta aqui correcto :u
    for(int i = 0; i < numJ.size()-1;++i){
        if((numJ[i+1] - numJ[i]) != 1){
            long long  dif = numJ[i + 1] - numJ[i] - 1;
            long long lsup;
            long  linf = numJ[i];
            if((cont + dif) > F){
                lsup = linf + (F - cont);
                cont = F;
            }
            else{
                lsup = numJ[i + 1] - 1;
                cont += dif;
            }
            n = (lsup * ( lsup + 1)) / 2;
            k = (linf * ( linf + 1)) / 2;
            suma += n - k;
        }
        if(cont == F)
            break;
    }
    if(cont < F){
        long long  dif = F - cont;
        long long linf = numJ[numJ.size() - 1];
        long long  lsup = linf + dif;
        n = (lsup * ( lsup + 1)) / 2;
        k = (linf * ( linf + 1)) / 2;
        suma += n - k;
    }
    cout<<suma<<endl;
}
