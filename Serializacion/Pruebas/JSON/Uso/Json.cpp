#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;
using namespace std;

int main(){
	ifstream archivoLeer("Datos.json");
	json datosExistentes;
	archivoLeer >> datosExistentes;
	archivoLeer.close();
	
	json nuevoDato;
	string nombre,ciudad;
	int edad;	
	while(true){
		cout<<"Nombre:";
		cin>>nombre;
		cout<<"Edad:";
		cin>>edad;
		cout<<"Ciudad:";
		cin>>ciudad;
		nuevoDato["Nombre"] = nombre;
		nuevoDato["Edad"] = edad;
		nuevoDato["Ciudad"] = ciudad;
		datosExistentes.push_back(nuevoDato);
		cout<<"Desea continuar agregando elementos: 1/si 2/no: ";
		cin>>edad;
		if(edad == 2)
			break;
	}
	ofstream archivo("Datos.json");
	archivo << datosExistentes.dump(4);//Indica lo indexacion que tendra 
	archivo.close();
}