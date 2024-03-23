#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,string> PIS;

//Cola de prioridad, si lee 0 o LIBRE ejecuta el top si no, entonces lo almacena
void queue_pri(){
    PIS p;
    priority_queue<PIS> pq;
    while( cin >> p.second >> p.first ){
        if(p.first == 0 and p.second == "LIBRE"){
            if(not pq.empty()){
                p = pq.top();
                pq.pop();
                cout << p.second << endl;
            }
        }
        else{
            pq.push(p);
        }
    }
}

void queue_pri_Ord(){
    priority_queue<pair<pair<int,int>,string> > p;
    string desc;
    int s = 0, prio;
    while( cin >> desc >> prio){
        if(desc == "LIBRE" and prio == 0){
            if(not p.empty()){
                pair<pair<int,int>,string> PIIS = p.top();
                p.pop();
                cout << PIIS.second << endl;
            }
        }
        else{//Usa typedef para mejor lectura aqui solo lo hice para practicar
            ++s;
            pair<int,int> pii(prio,-s);
            pair<pair<int,int>,string> q(pii,desc);
            p.push(q);
        }
    }
}

//alamcena en dos colas, qMax cuando empieza con mayuscula y qMin para minusculas
void colas_Max_Min(){
    queue<string> qMax,qMin;
    string s;
    while(cin >> s){
        if(s[0] >= 'A' and s[0] <= 'Z')
            qMax.push(s);
        else
            qMin.push(s);
    }
    while(not qMax.empty() and not qMin.empty()){
        cout << qMax.front() << " - " << qMin.front() << endl;
        qMax.pop(); qMin.pop();
    }
    cout << "Sobraron:" << (qMax.size() + qMin.size()) << " palabras" << endl;
}
//Uso simple de pila
void uso_Pila(){
    string s;
    stack<string> ps;
    while(cin >> s) ps.push(s);
    while(not ps.empty()){
        cout << ps.top() << endl;
        ps.pop();
    }
}

int main(){

}
