//Esto no es parte de los ejercicios si no una forma de comprender los limites de los vectores
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //Declaramos un arreglo sin tamaño definido
    int arreglo[] = {6,2,4,8,4,7};
    //Para obtener el tamaño del arreglo hacemos lo siguiente
    int sizeArreglo = sizeof(arreglo)/sizeof(arreglo[0]);//Lo que hacemos aqui es dividir a los bits totales entre la unidad
    //Podriamos haber usado cualquier elemento dentro del arreglo y obtendriamos lo mismo
    //int sizeArreglo = sizeof(arreglo)/sizeof(arreglo[1]);
    //Una vez que tengamos el tamaño del arreglo lo copiaremos a un vector
    vector<int>arregloV(arreglo,arreglo + sizeArreglo);//Copiamos desde el primer elemento del arreglo al final
    //Ahora ordenamos
    sort(arregloV.begin(),arregloV.end());
    //Ahora creamos dos iteradores donde almacenaremos los limites
    vector<int>::iterator low,up;
    int n = 1;
    low = lower_bound(arregloV.begin(),arregloV.end(),n);
    up = upper_bound(arregloV.begin(),arregloV.end(),n);
    //Low buscara desde el inicio hasta el final la primera aparicion de 4 o el numero que quieras buscar
    //up buscara desde el inicio hasta el final la ultima aparicion de 4 o el numero que quieras buscar
    for(auto elemento:arregloV)
        cout<<elemento<<" ";
    cout<<endl;
    if(low == up){

        cout<<(low - arregloV.begin()) - 1<<endl;
    }
    else{
        cout<<"El limite inferior del numero buscado es:"<<(low - arregloV.begin())<<endl;
        cout<<"El limite superior del numero buscado es:"<<(up - arregloV.begin());
    }

}
