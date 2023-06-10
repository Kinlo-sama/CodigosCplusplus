#include "Graham.h"

int main(){
	vector<Punto> puntos = ponerPuntos("Puntos.txt");
	vector<Punto> vertices = Graham::graham(puntos);
	vertices.push_back(vertices[0]);
	ponerVertices("Vertices.txt",vertices);
}