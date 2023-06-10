#include "Jarvis.h"
int main(){
		vector<Punto> puntos = ponerPuntos("Puntos.txt");
		vector<Punto> convexa = Jarvis::jarvis(puntos);
		ponerVertices("Vertices.txt",convexa);
}