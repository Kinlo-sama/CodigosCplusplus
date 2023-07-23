#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int>arreglo;
    int n;
    cin>>n;
    int dato;
    for(int i = 0; i < n;++i){
        cin>>dato;
        arreglo.push_back(dato);
    }
    cin >> n;
    vector<int>::iterator low,up;
    for(int i = 0; i < n;++i){
        cin>>dato;
        low = lower_bound(arreglo.begin(), arreglo.end(),dato);
        up = upper_bound(arreglo.begin(),arreglo.end(),dato);
        if( up != low)
            cout<<"Yes "<<(low - arreglo.begin()) + 1<<endl;
        else
            cout<<"No "<<(low - arreglo.begin()) + 1<<endl;
    }
    return 0;
}
