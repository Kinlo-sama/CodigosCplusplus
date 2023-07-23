#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);//Formatear para salidas en mayusculas
	cout << setw(0xf) << internal;//0xf para reaizar un espacio de 15 espacios, internal para alineacion a la derecha
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout<<resetiosflags(ios::uppercase);//Desactivamos la bandera que activa la mayuscula
        cout<<showbase<<hex<<left<<static_cast<long>(A)<<endl;//showbase para mostrar signos, manemos long porque usaremos numeros grandes
        cout<<setw(0xf)<<right<<setfill('_')<<showpos<<fixed<<setprecision(2)<<B<<endl;//Falla si no agregamos de nuevo el setw
        cout<<setiosflags(ios::uppercase);//Pone de nuevo la bandera para las mayusculas
        cout<<noshowpos<<setprecision(9)<<scientific<<C<<endl;//Ahora con noshowpos no mostramos el signo
        cout<<defaultfloat;//con defaultfloat quitamos la notacion cientifica
	}
