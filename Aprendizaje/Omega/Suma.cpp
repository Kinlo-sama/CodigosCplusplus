#include <iostream>

using namespace std;

int main(){
    int J,F;
    cin >> J >> F;
    int * numJ = new int[J];

    int dato;
    int j_total = J;
    int i = 0;
    while(J--){
        cin >> dato;
        numJ[i++] = dato;
    }

    bool asc = false;
    if((numJ[0] - numJ[1]) < 0)
        asc = true;

    int suma = 0,tot_ = 0,n,k;
    int inf,dif,sup;
    i = 0;
    while(tot_ < F){
        if(i == (j_total-1))
            break;
        if(asc){
            if(numJ[i+1] - numJ[i] != 1){
                dif = numJ[i+1] - numJ[i] - 1;
                inf = numJ[i];
                if((tot_ + dif) > F){
                    sup = inf + (F - tot_);
                    tot_ = F;
                }
                else{
                    sup = numJ[i + 1]- 1;
                    tot_ += dif;
                }
                n = (sup * (sup + 1)) / 2;
                k = (inf * (inf + 1)) / 2;
                suma += ( n - k );
            }
        }
        else{
            if(numJ[i] - numJ[i+1] != 1){
                dif = numJ[i] - numJ[i+1] - 1;
                sup = numJ[i] -  1;
                if((tot_ + dif) > F){
                    inf = sup - (F - tot_);
                    tot_ = F;
                }
                else{
                    inf = sup - dif;
                    tot_ += dif;
                }
                n = (sup * (sup + 1)) / 2;
                k = (inf * (inf + 1)) / 2;
                suma += ( n - k );
            }
        }
        ++i;
    }
//******************Hasta aqui correcto :u
    dif = F - tot_;
    bool aun = false;
    if((F - tot_) > 0){
        if(asc){
            inf = numJ[i];
            sup = numJ[i] + (dif);
            n = (sup *(sup + 1)) / 2;
            k = (inf *(inf + 1)) / 2;
            suma += n - k;
        }
        else{
            if((numJ[i] - dif) > 0 ){
                sup = numJ[i] - 1;
                inf = numJ[i] - dif - 1;
                n = (sup *(sup + 1)) / 2;
                k = (inf *(inf + 1)) / 2;
                suma += n - k;
            }
            else{
                sup = numJ[i] - 1;
                inf = 0;
                n = (sup *(sup + 1)) / 2;
                k = (inf *(inf + 1)) / 2;
                suma += n - k;
                tot_ += numJ[i] - 1;
                inf = numJ[0];
                sup = inf + (F - tot_);
                n = (sup *(sup + 1)) / 2;
                k = (inf *(inf + 1)) / 2;
                suma += n - k;
            }
        }
    }
    cout<<suma<<endl;
}
