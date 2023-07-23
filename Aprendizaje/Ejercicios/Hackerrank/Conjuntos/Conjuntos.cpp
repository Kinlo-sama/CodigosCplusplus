#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q,x,y;
    set<int>conjunto;
    cin>>Q;
    for(int i = 0; i < Q; ++i){
        cin>>y>>x;
        set<int>::iterator busqueda = conjunto.find(x);
        switch (y) {
            case 1:
                conjunto.insert(x);
                break;
            case 2:
                if(busqueda != conjunto.end())
                    conjunto.erase(x);
                break;
            case 3:
                if(busqueda == conjunto.end())
                    cout<<"No"<<endl;
                else
                    cout<<"Si"<<endl;
        }
    }
    return 0;
}
