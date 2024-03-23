#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool es_menor(const string &a,const string &b){
    if(a.size() != b.size())
        return a.size() > b.size();
    return a<b;
}

void ordenar_string(){
    string s;
    vector<string> v;
    while(cin >> s) v.push_back(s);
    sort(v.begin(),v.end(),es_menor);
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}

int main(){
    ordenar_string();
}
