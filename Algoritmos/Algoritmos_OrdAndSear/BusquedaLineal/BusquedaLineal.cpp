#include <iostream>
#include <array>
using namespace std;
//La busqueda linea no es mams que una busqueda por todos los elementos del arreglo hasta encontrar o no el elemento buscado
template <typename T, size_t size>
int busquedaLineal(const array<T,size> &items,const T &llave){
    for(int i = 0; i < items.size(); ++i )
        if(items[i] == llave)
            return i;

    return -1;
}
int main(){
    const size_t tamArr = 100;
    array< int , tamArr> arregloABuscar;
    for(int i = 0; i < tamArr; ++i)
        arregloABuscar[i] = 2 * i;//Ponerle unos datos para prueba
    cout <<"Ingrese un dato a buscar en el arreglo:";
    int datoBuscado;
    cin>>datoBuscado;
    int elementoBuscado = busquedaLineal(arregloABuscar,datoBuscado);
    if(elementoBuscado != -1 )
        cout<<"Dato encontrado en "<<elementoBuscado<<endl;
    else
        cout<<"Dato no encontrado"<<endl;
    int i = 0;
    for(auto elemento: arregloABuscar){
        if(i % 10 == 0)
            cout <<endl;
        cout<<elemento<<" ";
        ++i;
    }
}
