#include "Algoritmo_Chan.h"
int main(){
	vector<Punto> puntos = ponerPuntos("Puntos.txt");
	vector<vector<Punto>> grupoP = Chan::grupos(puntos);
	vector<Punto> puntosC = Chan::chan(grupoP);
	for(Punto punto:puntosC)
		punto.verPunto();
	ponerVertices("Vertices.txt",puntosC);
}