#ifndef VECTORES3D
#define VECTORES3D
#include "Vectores.h"

class Vectores3d : public Vector{

private:
    double z;
    double const PI = std::atan(1.0) * 4.0;
    static int MCD(int a,int b);
    static double MCD(double a,double b,double c);

public:
    //Constructores
    Vectores3d(double x,double y,double z_): Vector(x,y){ z = z_;}
    //Copia
    Vectores3d(const Vectores3d &b): Vector(b){
        setZ(b.getZ());
    }
    //Getter
    double getZ()const{ return z;    }
    //Setter
    void setZ(double z_){ z = z_; }
    //**********************************************Operaciones aritmeticas con vectores tridimensionales
    Vectores3d operator =(Vectores3d b);
    Vectores3d operator +(Vectores3d b);
    Vectores3d operator *(double esc);
    Vectores3d operator -(Vectores3d b);
    Vectores3d operator -();
    bool operator ==(Vectores3d b);
    friend std::ostream & operator <<(std::ostream& os,Vectores3d v){
        os << "<" << v.getX() <<"i," << v.getY() <<"j," << v.getZ() <<"k>";
        return os;
    }
    //***************************************Fin operaciones aritmeticas
    //***************************************************Representaciones
    static const Vectores3d Zero;
    double productoEscalar(Vectores3d b);
    Vectores3d producto_cruz(Vectores3d b);
    double static norma(Vectores3d b);
    static Vectores3d unitario(Vectores3d v);
    double comp_de(Vectores3d b);
    double distanciaPuntos(Vectores3d v);
    Vectores3d puntoMedio(Vectores3d b);
    Vectores3d proyeccion_sobre(Vectores3d b);
    bool paralela_con(Vectores3d b);
    bool perpendiculares(Vectores3d b);
    double anguloEntre(Vectores3d b);
    double areaFormadoPor(Vectores3d b);
    double volumenFormadoPor(Vectores3d b,Vectores3d c);
    //*********************************************Angulos directores
    double anguloDirectorAlpha();
    double anguloDirectorBeta();
    double anguloDirectorGamma();
    //**********************************************Fin angulos directores
    //**********************************************Fin de representaciones*****************************
};
#endif // VECTORES3D
