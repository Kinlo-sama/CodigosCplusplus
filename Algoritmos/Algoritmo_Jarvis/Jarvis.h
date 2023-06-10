//Empezamos con el algoritmo de Jarvis
#ifndef JARVIS_ALG
#define JARVIS_ALG
#include <iostream>
#include <vector>
#include "../../Modulos/Flujo.h"
#include "../../ADT/Punto.h"
#include "../../Algoritmos/Algoritmo_Graham/Graham.h"
using namespace std;
using namespace Flujo;
//De un conjunto de punto encontrar el punto mas a la izquierda
namespace Jarvis{
	vector<Punto> jarvis(vector<Punto>puntos){
	int n = puntos.size();
	vector<Punto>convexa;
	int indiceIzq = 0,sig;
	Punto izq = puntos[0];
	for(int i = 0; i < puntos.size(); ++i)
		if((puntos[i].puntX() < izq.puntX()) ||( (puntos[i].puntX() == izq.puntX()) && (puntos[i].puntY() < izq.puntY())))
			indiceIzq = i;
	int p = indiceIzq;
	do{
		convexa.push_back(puntos[p]);
		sig = (p + 1 )% n;
		for(int i = 0; i < n;++i)
			if(Graham::giroAntiH(puntos[p],puntos[sig],puntos[i]))
				sig = i;
		p = sig;
	}while(sig != indiceIzq);
	convexa.push_back(convexa[0]);
	return convexa;
	
}
}
#endif
//By KINLO_SAMA :3