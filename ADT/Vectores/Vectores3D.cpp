#include "Vectores3D.h"
//Metodos privados*****************************************************************************************************
int Vectores3d::MCD(int a,int b){
    if(b == 0)
        return a;
    else
        return MCD(b,a%b);
}
double Vectores3d::MCD(double a,double b,double c){//Para encontrar el mcd de 3 numero los cuales seran doubles
        a = static_cast<int>(a * 10000);
        b = static_cast<int>(b * 10000);
        c = static_cast<int>(c * 10000);
        return MCD(a,MCD(b,c)) / 10000;
}
//Fin metodos privados***********************************************************************************************
//Sobrecarga de operadores*******************************************************************************************
Vectores3d Vectores3d::operator =(Vectores3d b){
        setX(b.getX());
        setY(b.getY());
        setZ(b.getZ());
        return *this;
}
Vectores3d Vectores3d::operator +(Vectores3d b){
    return Vectores3d(getX() + b.getX(),getY() + b.getY(),getZ() + b.getZ());
}
Vectores3d Vectores3d::operator *(double esc){//Para operaciones vector * escalar
    return Vectores3d(esc * getX(),esc * getY(),esc * getZ());
}
Vectores3d Vectores3d::operator -(Vectores3d b){
    return Vectores3d(getX() - b.getX(),getY() - b.getY(), getZ() - b.getZ());
}
Vectores3d Vectores3d::operator -(){//Negacion de un vector para todos sus valores
    return Vectores3d(-getX(),-getY(),-getZ());
}
bool Vectores3d::operator ==(Vectores3d b){
    return (getX() == b.getX()) && (getY() == b.getY()) && (getZ() == b.getZ());
}
//Dejare algunas de las propiedad de los productos escalares abajo
/*
a * b > 0 => Su respectivo angulo es agudo
a * b < 0 => Su respectivo angulo es obtuso
a * b = 0 => Su respectivo angulo es 0
FinSobrecarga de operadores********************************************************************************************/
//Representaciones*****************************************************************************************************
const Vectores3d Vectores3d::Zero = Vectores3d(0,0,0);
double Vectores3d::productoEscalar(Vectores3d b){//Solo como recordatorio a * a = ||a||^2; siendo a un vector tridimensional
    return (getX() * b.getX()) + (getY() * b.getY()) + (getZ() * b.getZ());
}

double Vectores3d::norma(Vectores3d b){//O magnitud
    return std::sqrt(b.getX() * b.getX() + b.getY() * b.getY() + b.getZ() * b.getZ());
}

Vectores3d Vectores3d::unitario(Vectores3d v){//El vector unitario es un vector con magnitud uno de *this
    return Vectores3d(v.getX() / norma(v),v.getY() / norma(v),v.getZ() / norma(v));
}

double Vectores3d::comp_de(Vectores3d b){//El componente que forma parte de b, ver mejores visualizacion en Wikipedia para entenderlo
    return productoEscalar(Vectores3d::unitario(b));
}

//La distancia retorna un double representando la distancia entre dos vectores tridimensionales
double Vectores3d::distanciaPuntos(Vectores3d v){
    return std::sqrt(std::pow((v.getX() - getX()),2) + std::pow((v.getY() - getY()),2) + pow((v.getZ() - getZ()),2));
}

//Puntos medio entre dos vectores tridimensionales
Vectores3d Vectores3d::puntoMedio(Vectores3d b){
    return Vectores3d((getX() + b.getX())/2,(getY() + b.getY())/2,(getZ() + b.getZ())/2);
}

//Proyeccion de a sobre b
Vectores3d Vectores3d::proyeccion_sobre(Vectores3d b){
    return Vectores3d::unitario(b) * comp_de(b);
}

double Vectores3d::volumenFormadoPor(Vectores3d b,Vectores3d c){
    Vectores3d productoC = b.producto_cruz(c);
    return productoEscalar(productoC);
}
//Producto escalar de axb  = ||a||*||b|| * sen(theta) * n; donde n es el
Vectores3d Vectores3d::producto_cruz(Vectores3d b){
//Para evitarnos los problemas del angulo utilizaremos otra forma de calcular axb
/*
    double mcdA = MCD(getX(),getY(),getZ());
    double mcdB = MCD(b.getX(),b.getY(),b.getZ());
    double n = mcdA >= mcdB ? mcdA : mcdB;
    Vectores3d vn(n,n,n);
    double umbral = 0.01;//senos(x) con x < 0.1 producen angulos menores a 5 grados
    double angulo = std::abs(PI - anguloEntre(b)) < umbral ? 0 : anguloEntre(b);
    n = (norma() * b.norma() * std::sin(angulo));
//Los angulos que se generan entre dos vectores son obtusos y agudos por ende no hace falta preocuparnos por mayores a PI
    return vn * n;
*/
//La cual es de la siguiente manera utilizando los coefactores de la primera fila de la siguiente matriz
/*
i j k      i  j  k
a b c = > x1 y1 z1
d e f     x2 y2 z2
------------------------
=> i = b * f - c * e
=> i = y1 * z2 - z1 * y2
------------------------
=> j = -(a * f - c * d)
=> j = -(x1 * z2 - z1 * x2)
------------------------
=> k = a * e - b * d
=> k = x1 * y2 - y2 * x2
-----------------------
*/
    double i = getY() * b.getZ() - getZ() * b.getY();
    double j = getX() * b.getZ() - getZ() * b.getX();
    double k = getX() * b.getY() - getY() * b.getX();
    return Vectores3d(i,-j,k);
}

bool Vectores3d::paralela_con(Vectores3d b){
    return producto_cruz(b) == Zero ? true : false;
}

bool Vectores3d::perpendiculares(Vectores3d b){
    return productoEscalar(b) == 0 ? true : false;
}

double Vectores3d::anguloEntre(Vectores3d b){
    double numerador = productoEscalar(b);
    double denominador = std::sqrt(productoEscalar(*this)) * std::sqrt(b.productoEscalar(b));
    return std::acos(numerador / denominador);
}

double Vectores3d::areaFormadoPor(Vectores3d b){
    Vectores3d producto(producto_cruz(b));
    return norma(producto);
}
//Angulos directores*******************************************************************************
double Vectores3d::anguloDirectorAlpha(){//Marca el angulo entre i y la cordenada x del vector tridimensional
    double div = getX() / std::sqrt(productoEscalar(*this));
    return std::acos(div);
}
double Vectores3d::anguloDirectorBeta(){//Marca el angulo entre j y la cordenada y del vector tridimensional
    double div = getY() / std::sqrt(productoEscalar(*this));
    return std::acos(div);
}
double Vectores3d::anguloDirectorGamma(){//Marca el angulo entre k y la cordenada y el vector tridimensional
    double div = getZ() / std::sqrt(productoEscalar(*this));
    return std::acos(div);
}

//Fin angulos directores****************************************************************************
//Fin de representaciones***************************************************************************
