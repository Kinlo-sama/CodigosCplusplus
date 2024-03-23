#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//vectores como parametros
vector<int> lee_vector(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(size_t i = 0; i < n; ++i)
        cin >> v[i];
    return v;
}

void escribe_vector(const vector<int> &v){
    for(int i = 0; i <= v.size()-1; ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

void pon_a_cero(vector<int> &v){
    for(size_t i = 0; i < v.size(); ++i)
        v[i] = 0;
}

void ingreso_cadena(){
    string palabra;
    vector<string> vs;
    while(cin >> palabra){
        vs.push_back(palabra);
    }
    cout << "Palabras leidas: " << vs.size() << endl;
}
//er un vector al reves
void escribe_reves(const vector<int> &v){
    size_t n = v.size();
    for(size_t i = n -1; i >= 0;--i)
        cout << v[i] << endl;
}
//ver un vector usando iteradores
//Recuerda si usas const vector de igual manera para el iterador osea
//const_iterator
int suma_vector(const vector<int> & v){
    int suma = 0;
    for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        suma += *it;
    return suma;
}

void ordenar_vector(){
    int n;
    vector<int>v;
    while(cin >> n) v.push_back(n);
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}

int main(){
    /*
    vector<int> a(3);       //Vector con 3 elementos enteros
    vector<string> vst(10); //Vector con 10 string
    vector<bool> b;         //vector de booleano, vacio
    vector<int> v_3(10,3);  //incializamos un vector de 10 enteros con 3 de valor
    vector<int> w = a;      //Podemos hacer asignacion ya que son del mismo tipo
    ++v_3[0];               //modificar v_3 no modifica w poque w es una copia
    w.resize(0);            //cambiamos el tamaño de w a 0
    v_3 = w;                //ahora ambas estan vacias
    bool igualess = w == v_3;//Podemos usar operaciones de comparacion
    vector<char> v(2),c;    //v un vector de 2 char y w un vector vacio
    v[0] = v[1] = 'a';      //asignacion en cascada
    c = v;                  //w ahora tiene los valores de v_3
    c[1] = 'z';              //v != w
    cout << "v<c?" << (v<c) << endl;
    v_3.push_back(3);
    //escribe_vector(v_3);
    //ingreso_cadena();
    */
    ordenar_vector();
}
