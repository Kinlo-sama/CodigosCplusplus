#include <iostream>
#include <fstream>
using namespace std;
int main(){
    try{
        ifstream archivo("Datos.txt");
        char linea = archivo.get();
        while(linea != EOF){
            cout <<linea;
            linea = archivo.get();
        }
    }
    catch (const exception e){
        cerr << "Error:" << e.what() << endl;
    }
}
