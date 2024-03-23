#include <map>
#include <iostream>

using namespace std;

void primer_Uso(){
    map<int,string>mapa;
    mapa[2] = "Leonardo";
    cout << "2:"<<mapa[2];
    if(mapa[2] == "Leonardo")
        cout << endl << "Ademas encontramos a Leonardo" << endl;

    //Contar las veces que se repiten palabras escritas por la terminal
    map<string,int> cadenas;
    string s;
    while(cin >> s ) ++cadenas[s];
}

void recorrimiento(){
    map<string,int> mapa;
    string s;
    while( cin >> s) ++mapa[s];
    map<string,int>::iterator it;
    for(it = mapa.begin(); it != mapa.end(); ++it)
        cout << it->first << ":" << it->second << " veces" << endl;
}

int main(){
    recorrimiento();
}
