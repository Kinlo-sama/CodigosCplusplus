#ifndef PUNTO
#define PUNTO
//ADT Punto 
//Tiene cordenada 'x' y 'y'
#include <iostream>
using namespace std;
class Punto{
	private:
		int x,y;
	public:
		Punto(int x_,int y_){
			x = x_;
			y = y_;
		}
		Punto(){
		x=0,y=0;
		}
		int puntX() { return x;	}
		int puntY() { return y;	}
		void setX(int _x) { x = _x; }
		void setY(int _y) { y = _y; }
		void verPunto(){
		cout<<"("<<x<<","<<y<<")";
		}
};
#endif
//BY KINLO_SAMA :3