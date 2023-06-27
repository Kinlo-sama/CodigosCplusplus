#ifndef VECTORMAT
#define VECTORMAT
#include <iostream>
#include <cmath>
class Vector{
private:
    double x;
    double y;

public:
    Vector(double x_,double y_){
        x = x_;
        y = y_;
    }
    Vector(const Vector &b){
        setX(b.getX());
        setY(b.getY());
    }
    //Setters
    void setX(double x_){
        x = x_;
    }
    void setY(double y_){
        y = y_;
    }
    //Getters
    double getX()const{   return x;   }
    double getY()const{   return y;   }
    //**************************************OPERACIONES ARITMETICAS CON VECTORES
    //Suma de vectores
    Vector operator +(Vector otroV){
        return Vector(x + otroV.getX(), y + otroV.getY());
    }
    //Multiplicacion por escalar
    Vector operator *(double esc){
        return Vector(getX() * esc,getY() * esc);
    }
    //Igualdad
    bool operator ==(Vector otroV){
        return (x == otroV.getX()) && (y == otroV.getY());
    }
    //Resta
    Vector operator -(Vector otroV){
        return Vector(x - otroV.getX(),y - otroV.getY());
    }
    friend std::ostream& operator <<(std::ostream& os,Vector v){
        os << "<" << v.getX() << "i," << v.getY() << "j>";
        return os;
    }
    Vector operator-(){
        return Vector(-x,-y);
    }
    //***************************************FIN OPERACIONES ARITMETICAS CON VECTORES
    virtual double norma(){//Magnitud o longitud
        return std::sqrt(x*x + y*y);
    }
    static Vector unitario(Vector b){
        Vector resultado(b.getX() / b.norma(),b.getY() / b.norma());
        return resultado;
    }

    Vector unitarioNegativo(Vector b){
        return -Vector::unitario(b);
    }
};
#endif
