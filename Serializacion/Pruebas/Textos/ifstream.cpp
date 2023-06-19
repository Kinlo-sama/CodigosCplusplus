#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <sstream>
using namespace std;

void caracteres(){//uso de los gets
    try{
        ifstream archivo("Datos.txt");
        //peek lee el siguiente caracter sin extraerlo
        char dato = archivo.peek();
        //unget es para desextraer caracteres
        dato = archivo.get();
        cout << dato;
        archivo.unget();
        dato = archivo.get();
        cout<< dato;
        archivo.unget();
        //Como vemos el unget devuelve el caracter leido
        //Lectura caracter a caracter
        while(dato != EOF ){
            cout<<dato;
            dato = archivo.get();
        }
        archivo.close();
    }
    catch (const exception e){
        cerr << "Error:" << e.what() << endl;
    }
}
void lineas(){//Uso de getline con vectores de arreglos
    ifstream archivo("Datos2.txt");
    vector<array<char,10>> v;
    for(array<char,10>a;archivo.getline(&a[0],100,'\n');){
        v.push_back(a);
    }
    for(auto& dato:v){
        cout<<&dato[0]<<endl;
    }

    archivo.close();
}
void lineas2(){//Usando string
    try{
        ifstream archivo("Datos.txt");
        for(string linea; archivo.getline(&linea[0],400);){
            cout<<&linea[0]<<endl;
        }
        archivo.close();
    }
    catch (const exception e){
        cerr<<"Error:" <<e.what() << endl;
    }
}
void operador(){//Usando el operador <<
    ifstream archivo("Datos2.txt");
    string dato;
    while(archivo >> dato){
        cout<<dato<<endl;
    }
    archivo.close();
}
int main(){
    rename("Datos3_.txt","Datos3.txt");
}
