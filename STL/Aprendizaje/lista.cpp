#include <list>
#include <iostream>
using namespace std;
typedef list<int>::iterator Lit;


void subsecuencia(list<int> &l){
   Lit it= l.begin();
   while(it != l.end()){
        Lit next = it;
        ++next;
        if(next != l.end() and *it>= *next)
            l.erase(next);
        else
            it = next;
   }
}

int main(){
    list<int> lista{1,3,4,2,4,7,7,1};
    subsecuencia(lista);
    Lit it;
    for(it = lista.begin(); it != lista.end(); ++it)
        cout << *it << " ";
}
