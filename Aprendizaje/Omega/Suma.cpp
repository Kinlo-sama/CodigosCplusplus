#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
//Creamos una funcion para eliminar espacios

vector<string>split(const string cadena, char delimitador)
{
    vector<string>partes;
    istringstream flujo(cadena);
    string parte;
    while(getline(flujo,parte,delimitador))
        partes.push_back(parte);
    return partes;
}

void nad(){
    string cadena;
    getline(cin,cadena);
    for(auto &caracter: cadena)
        caracter = tolower(caracter);


    bool upper = true;
    vector<string>partes_cadena = split(cadena,' ');
    for(auto &elemento: partes_cadena){
        if(upper){
            elemento[0] = toupper(elemento[0]);
            upper = false;
        }
        if(elemento[elemento.size() - 1] == '.')
            upper = true;
    }
    for(auto elemento:partes_cadena)
        cout<<elemento<<" ";
}
int main() {
  // TODO: fixme.
    string cadena = "sadasd.asda";
    string::iterator iter;
    iter = cadena.begin();
    int enc = find(cadena.begin(),cadena.end(),'.');

    return 0;

}