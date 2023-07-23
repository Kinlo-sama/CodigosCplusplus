//Para pruebas
#include <iostream>
#include "Vectores.h"
#include "Vectores3d.h"

using namespace std;

int main(){
    Vectores3d a(2,1,-1);
    Vectores3d b(-6,-3,3);
    cout <<"Distancia entre el vector"<<a<<"y el vector"<<b<<"="<<a.distanciaPuntos(b)<<endl
         <<"Y su punto medio es:"<<a.puntoMedio(b)<<endl
         <<"Y la suma es:"<<a+b<<endl
         //<<"Y un vector 0 en tres dimensiones se ve asi:"<<Vectores3d::Zero()<<endl
         <<"El producto escalar entre a y b:"<<a.productoEscalar(b)<<endl
         <<"El angulo entre estos vectores es:"<<a.anguloEntre(b)<<endl
         <<"El angulo director alpha para el vector a es:"<<a.anguloDirectorAlpha()<<endl
         <<"El angulo director beta para el vector a es:"<<a.anguloDirectorBeta()<<endl
         <<"El angulo director gamma para el vector a es:"<<a.anguloDirectorGamma()<<endl
         <<"El componenete de a sobre b es:"<<a.comp_de(b)<<endl
         <<"El componente de b sobre a es:"<<b.comp_de(a)<<endl
         <<"Y la proyeccion de a sobre b es:"<<a.proyeccion_sobre(b)<<endl
         <<"El producto punto de axb:"<<a.producto_cruz(b)<<endl
         <<"El area formado por los vectores a y b es:"<<a.areaFormadoPor(b)<<endl;


}
