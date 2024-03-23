#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct Trabajo{
    int prio,t;
    string desc;
};

bool operator<(const Trabajo &a,const Trabajo &b){
    if(a.prio != b.prio) return a.prio < b.prio;
    return a.t > b.t;
}

void pq_Ord(){
    int t = 0;
    Trabajo tra;
    priority_queue<Trabajo> p;
    while( cin >> tra.desc >> tra.prio){
        if(tra.desc == "LIBRE" and tra.prio == 0){
            if(not p.empty()){
                Trabajo t_top = p.top();
                p.pop();
                cout << t_top.desc << endl;
            }
        }
        else{
           ++t;
           tra.t = t;
           p.push(tra);
        }
    }
}
//uso de funtores para la comparacion en las priority_queue
struct compara_diccionario{
    bool operator()(const string &a,const string &b){
        return a > b;
    };
};

struct compara_size{
    bool operator()( const string &a,const string &b){
        if(a.size() != b.size())    return a.size() < b.size();
        return a > b;
    };
};


typedef priority_queue<string,vector<string>,compara_diccionario> PQ_dic;
typedef priority_queue<string,vector<string>,compara_size> PQ_size;

int main(){
    string s;
    PQ_size pq_s;
    while( cin >> s)    pq_s.push(s);
    while( not pq_s.empty()){
        cout << pq_s.top() << endl;
        pq_s.pop();
    }
}
