//ponerVertices sirve para poner una cantidad n de puntos en un txt de la siguiente maner
/*
a b 
c d 
...
n m
*/
//Tiene como parametro un vector de tipo Punto 
//Y ponerVertices para poner una cantidad n de puntos en un vector de tipo Punto
#ifndef FLUJO_DATOS
#define FLUJO_DATOS
#include <vector>
#include <string>
#include "../ADT/Punto.h"
#include <fstream>
using namespace std;
namespace Flujo{	
//Cuando se obtienen los vertices se colocan en un archivo .txt
void ponerVertices(string nombre,vector<Punto> puntos){
	ofstream archivo(nombre);
	if(archivo.is_open()){
		for(auto punto: puntos){
			archivo << punto.puntX();
			archivo << " ";
			archivo << punto.puntY();
			archivo << endl;
		}
		archivo.close();
	}else{
		cout<<"No";
	}
}
//Poner los puntos de un .txt en un vector
vector<Punto> ponerPuntos(string nombre){
	vector<Punto> puntos;
	Punto punto;	
	ifstream archivo(nombre);
	if(archivo.is_open())
	{
		int x,y;
		while(archivo >> x >> y){	
			punto.setX(x);
			punto.setY(y);
			puntos.push_back(punto);
		}
		archivo.close();
	}
	else{
		cout<<"no"<<endl;
	}
	return puntos;
}
}
#endif
//By KINLO_SAMA :3