#include <iostream>
#include <array>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

template <typename T, size_t size>
void mostrarElementos(const array<T,size> &elementos, size_t bajo,size_t alto){
    for(int i = 0; i < elementos.size() && i < bajo; ++i)
        cout<<"    ";

    for(int i = bajo; i < elementos.size() && i <= alto; ++i)
        cout<<elementos[i] << "  ";
    cout<<endl;
}

//Aqui empezamos con la busqueda binaria sobre los datos
template <typename T,size_t size>
int busquedaBinaria(const array<T,size> &elementos,const T& dato){
    int bajo = 0;
    int alto = elementos.size();
    int medio = (alto + bajo + 1) / 2;
    int localizacion = -1;//En caso de no encontrarlo

    do{
        //Mostraremos los elementos del arreglo a buscar esto lo haremos para ver como funciona la busqueda binaria
        mostrarElementos(elementos,bajo,alto);
        for(int i = 0; i < medio;++i)
            cout<<"   ";
        cout<<"  *"<<endl;
        if(dato == elementos[medio])
            localizacion = medio;
        else if(dato < elementos[medio])
            alto = medio - 1;
        else//Si el elemento a buscar es mayor al de en medio
            bajo = medio + 1;//El bajo ahora tomara el valor del medio mas un elemento arriba porque ya usamos el indice medio

        medio = (bajo + alto + 1) / 2;//Recalculamos el medio
    }while(bajo <= alto && localizacion == -1);

    return localizacion;
}

int main(){
    default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<unsigned int> randomInt(10,99);
    const size_t tam = 15;
    array<int,tam> arregloABuscar;

    for(auto &elemento:arregloABuscar)
        elemento = randomInt(engine);
    //La busqueda binario solo funciona con un arreglo que tiene elementos ordenados
    sort(arregloABuscar.begin(),arregloABuscar.end());

    mostrarElementos(arregloABuscar,0,arregloABuscar.size() - 1);
    cout<<"Ingrese un dato a buscar en el arreglo(-1 para salir):";
    int dato;
    cin>>dato;
    while(dato != -1){
        int localizacion = busquedaBinaria(arregloABuscar,dato);
        if(localizacion == -1)
            cout<<"Dato no encontrado"<<endl;
        else
            cout<<"Dato encontrado en la direccion "<< localizacion <<endl;

        cout <<"Ingrese un dato a buscar en el arreglo(-1 para salir:";
        cin >> dato;
    }
}
