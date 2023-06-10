#ifndef CHAN_ALG
#define CHAN_ALG
#include "../../Modulos/Flujo.h"
#include "../../ADT/Punto.h"
#include "../../Algoritmos/Algoritmo_Graham/Graham.h"
#include <cmath>
#include <vector>
using namespace Flujo;
using namespace std;
//Definir los grupos 
namespace Chan{
vector<vector<Punto>> grupos(vector<Punto>puntos) {
    int numPuntos = puntos.size();
    int m = 10;
    int numGrupos = ceil(static_cast<double>(numPuntos) / m);
    int inicio = 0;
    vector<vector<Punto>> gruposP;
    for(int i = 0; i < numGrupos - 1; ++i) {
        vector<Punto> grupo(puntos.begin() + inicio, puntos.begin() + inicio + m);
        gruposP.push_back(grupo);
        inicio += m;
    }
    vector<Punto> grupo(puntos.begin() + inicio, puntos.end());
    gruposP.push_back(grupo);
    return gruposP;
}

vector<Punto> chan(vector<vector<Punto>> grupoP){
	vector<Punto> puntosC;
	for(auto v:grupoP){
		vector<Punto> grupoPC = Graham::graham(v);
		puntosC.insert(puntosC.end(),grupoPC.begin(),grupoPC.end());
	}	
	puntosC = Graham::graham(puntosC);
	puntosC.push_back(puntosC[0]);
	return puntosC;
}
}
#endif