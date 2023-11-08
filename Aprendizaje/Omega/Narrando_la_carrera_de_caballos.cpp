//Ejercicio -> https://omegaup.com/course/introduccion_a_cpp/assignment/ciclos#problems/Narrando-la-carrera-de-caballos
#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    int times[T][2];
    for(int i = 0; i < T;++i){
        int c1,c2;
        cin>>c1>>c2;
        times[i][0] = c1;
        times[i][1] = c2;
    }
    int cab1 = 0,cab2 = 0;
    int dif = 0;
    bool cab1_win = false,cab2_win = false;
    for(int i = 0; i < T;++i){
        cab1 += times[i][0];
        cab2 += times[i][1];
        if(dif < abs(cab1 - cab2))
            dif = abs(cab1 - cab2);

        if(cab1 == cab2){
            if(!cab1_win && cab2_win){
                cout<<"Al minuto "<<i+1<<" los caballos van empatados"<<endl;
            }
            if(cab1_win && !cab2_win){
                cout<<"Al minuto "<<i+1<<" los caballos van empatados"<<endl;
            }
            cab1_win = false;
            cab2_win = false;
        }
        else if(cab1 >  cab2 && !cab1_win){
            cout<<"Al minuto "<<i+1<<" el caballo 1 toma la delantera"<<endl;
            cab1_win = true;
            cab2_win = false;
        }
        else if(cab1 < cab2 && !cab2_win){
            cout<<"Al minuto "<<i+1<<" el caballo 2 toma la delantera"<<endl;
            cab2_win = true;
            cab1_win = false;
        }
    }
    if(cab1 > cab2)
        cout<<"Termina la carrera y gana el caballo 1"<<endl;
    if(cab1 < cab2)
        cout<<"Termina la carrera y gana el caballo 2"<<endl;
    if(cab1 == cab2)
        cout<<"Termina la carrera y empatan los caballos"<<endl;
    cout<<"La distancia maxima entre los caballos fue de "<<dif<<endl;
}
