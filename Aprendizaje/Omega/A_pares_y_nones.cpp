#include <iostream>
using namespace std;
int main(){
    int N;  cin>>N;
    int pares = 0,nones = 0;
    int dato;
    int cont_p = 0, cont_n = 0;
    for(int i = 0; i < N; ++i){
        cin>>dato;
        if(dato%2 == 0){
            pares += dato;
            ++cont_p;
        }
        else{
            nones += dato;
            ++cont_n;
        }
    }
    int m_p,m_n;
    m_p = pares / cont_p;
    m_n = nones / cont_n;
    if(m_p == m_n)
        cout<<"EMPATE!";
    else if(m_p < m_n)
            cout<<"NONILA";
        else
            cout<<"APARICIO";

}
