//Problema aqui -> https://omegaup.com/course/introduccion_a_cpp/assignment/ciclos#problems/Calculando-el-logaritmo-base-2
#include <bitset>
#include <iostream>
using namespace std;

int main(){
    int N;  cin>>N;
    bitset<32> bin_num(N);
    string bin_to_s = bin_num.to_string();
    int i = 0;
    for(; i < 32;++i){
        if(bin_to_s[i] == '1'){
            i = 32 - (i+1);
            break;
        }
    }
    cout<<i;
}
