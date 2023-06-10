#ifndef GRAHAM_ALG
#define GRAHAM_ALG

#include <algorithm>
#include <cmath>
#include "../../ADT/Pila.h"
#include "../../ADT/Punto.h"
#include "../../Modulos/Flujo.h"
using namespace std;
using namespace Flujo;
namespace Graham{
//Angulo entre el punto P y otro punto y el eje de las x
double angulo(Punto p1, Punto p2) {
    return atan2(p2.puntY() - p1.puntY(), p2.puntX() -p1.puntX());
}

//Comparamos dos puntos 
//Parametros -> Dos puntos 
//Retorno Si p1 es menor entonces retorna true de lo contrario false: esto es con base a sus angulos
bool compararPuntos(Punto punto_referencia,Punto p1,Punto p2){
	double angulo1 = angulo(punto_referencia,p1);
	double angulo2 = angulo(punto_referencia,p2);
	if(angulo1 < angulo2)
		return true;
	if(angulo1 > angulo2)
		return false;
	//Si la comparacion por medio de los angulos resultado que ambos son iguales
	int dist1 = pow((p1.puntX() - punto_referencia.puntX()),2)  + pow((p1.puntY() - punto_referencia.puntY()),2);
	int dist2 = pow((p2.puntX() - punto_referencia.puntX()),2)  + pow((p2.puntY() - punto_referencia.puntY()),2);
	return dist1 < dist2;
}
//Funcion para retornar el punto de referencia de todos los puntos
//El punto de referencia tiene que ser el punto con cordenada 'y' menor que todas y si hay con corde 'y' se escoge la de corde 'x' menor
void imprimir(vector<Punto>p)
{
	for(auto punto:p)
		cout<<"("<<punto.puntX()<<","<<punto.puntY()<<")"<<endl;
	cout<<endl;
}
//return -> si el productor cruz es positivo entonces el giro es antihorario
bool giroAntiH(Punto p1,Punto p2,Punto p3){
	int producto_cruz = (p2.puntX() - p1.puntX()) * (p3.puntY() - p1.puntY()) - (p2.puntY() - p1.puntY()) * (p3.puntX() - p1.puntX());
	return producto_cruz > 0;
}
//no retorna nada porque ordena al vector modificandolo, siendo una funcion destructiva
void ordenar(vector<Punto> &p){
	Punto punto_referencia = p[0];
	for(auto punto : p){
		if(punto.puntY() < punto_referencia.puntY() || (punto.puntY() == punto_referencia.puntY() && punto.puntX() < punto_referencia.puntX()))
		punto_referencia = punto;
	}
		
	/*
	for(int i = 1,j; i < p.size();++i){
		Punto temp = p[i];
		for(j = i; j > 0 && compararPuntos(punto_referencia,temp,p[j-1]); --j)
			p[j] = p[j-1];
		p[j] = temp;
	}
	*/
	sort(p.begin(),p.end(),[punto_referencia](Punto a,Punto b){
		return compararPuntos(punto_referencia,a,b);	
	});
	
}
//Devuelve un vector con todos las vertices que forman la envoltura
vector<Punto> graham(vector<Punto>puntos){
	ordenar(puntos);
	Pila<Punto> *resultado = new Pila<Punto>();
	resultado->push(puntos[0]);
	resultado->push(puntos[1]);
	resultado->push(puntos[2]);
	for(int i = 3; i < puntos.size();++i){
		Punto punto_act = puntos[i];
		while(resultado->size() >= 2)
		{
			Punto segundoPunto = resultado->top();
			resultado->pop();
			Punto top = resultado->top();
			
			if(!giroAntiH(top,segundoPunto,punto_act))//
				continue;
			resultado->push(segundoPunto);
			break;
		}
		resultado->push(punto_act);
	}
	vector<Punto> puntosC;
	while(!resultado->vacia()){
		puntosC.push_back(resultado->pop());
	}
	return puntosC; 
}
}
#endif
//BY KINLO_SAMA :3