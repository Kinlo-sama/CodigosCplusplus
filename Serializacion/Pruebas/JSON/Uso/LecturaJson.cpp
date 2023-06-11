#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main(){
	ifstream archivoLeer("Datos.json");
	json datos;
	archivoLeer >> datos;
	archivoLeer.close();
	
	for(auto dato: datos){
		cout<<"Nombre:"<<dato["Nombre"]<<endl
			<<"Edad:"<<dato["Edad"]<<endl
			<<"Ciudad:"<<dato["Ciudad"]<<endl<<endl;
	}
}