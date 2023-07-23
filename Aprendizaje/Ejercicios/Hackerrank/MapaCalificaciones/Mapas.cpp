#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string,int>calificaciones;
    int alumnos;
    cin>>alumnos;
    for(int i = 0; i < alumnos;++i){
        string nombre;
        int mark,caso;
        cin>>caso>>nombre;
        map<string,int>::iterator ite = calificaciones.find(nombre);
        //Tenemos tres casos
        if(caso == 1){//caso para agregar
            cin>>mark;
            if(ite != calificaciones.end()){//Si hay una calificacion ya para este nombre
                int aum = ite->second + mark;
                calificaciones[nombre] = aum;
            }else{
                calificaciones[nombre] = mark;
            }
        }else if(caso == 2){//caso para eliminar
            if(ite != calificaciones.end()){
                calificaciones.erase(nombre);
            }
        }else{//caso para buscar
            if(ite != calificaciones.end())
                cout<<calificaciones[nombre]<<endl;
            else
                cout<<0<<endl;
        }
}
    return 0;
}


