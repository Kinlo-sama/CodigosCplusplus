#include <map>
#include <iostream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <set>


using namespace std;
typedef map<string,int> MSI;
typedef MSI::iterator MSIit;
//Usando macros para simplificar los bucles
#define foreach(i,m) \
for( decltype((m).begin()) i  = (m).begin(); i != (m).end(); ++i)

void sets(){
    set<int> potencias3_5;
    int pot;
    potencias3_5.insert(1);
    potencias3_5.insert(3);
    potencias3_5.insert(5);
    set<int>::iterator it = potencias3_5.begin();
    ++it;
    while(it != potencias3_5.end()){
        if(((*it) *  5) < 100000){
            potencias3_5.insert((*it) * 3);
            ++it;
            potencias3_5.insert((*it) * 5);
            ++it;
        }else{
            ++it;
        }
    }
    for(it = potencias3_5.begin(); it != potencias3_5.end(); ++it)
        cout << *it << endl;
}

void recorrer(){
    MSI mapa;
    string s;
    while(cin >> s) ++mapa[s];

    MSIit it;
    for(it = mapa.begin(); it != mapa.end(); ++it)
        cout << it->first << " " <<  it->second <<  " veces" << endl;
}

void recorrer_V2(){
    MSI mapa;
    string s;
    while(cin >> s) ++mapa[s];

    MSIit it;
    foreach(it,mapa){
        cout << it->first << " " << it->second << " veces" << endl;
    }
}

int main(){
    sets();
}
