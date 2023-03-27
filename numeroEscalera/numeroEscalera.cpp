#include <iostream>
#include <cmath>
using namespace std;

bool esc(int a)//Ejemplo de numeros escaleras -1-  -12321-  -121- -1234321-	
{
	int auxA = a,cont = 0;//auxA sirve para no modificar el valor de a mientras se ejecuta la funcion y cont es para ver cantidad de digitos 
	while(auxA != 0)
	{
		++cont;
		auxA/= 10;//Para conocer la cantidad de digitos de una cifra de N digitos solo dividiremos el numero hasta que este sea 0 mientras cont aunmenta en 1
	}
	int aux,otroA=a;//otro aux para no perder el valor de a y otro auxA usado como auxiliar
	bool verdad = true;//Empezamos suponiendo que el numero dado ->a<- es escalera
	for(int i = 1; i <= cont/2+1;++i)//ejecutaremos un ciclo pero solo a la mitad de la cantidad de digitos del numero
	{
		aux = otroA - (otroA/10) * 10;//esta operacion obtiene el digito de la derecha
		otroA = otroA/10;//modificamos a otroA usado una linea antes para que en la otra pasada este tome un nuevo valor sin el digito anterior derecha
		if(aux != i)//verificamos que el primer digito de la derecha sea 1 y si no lo es entonces no es necesario seguir
		{
			verdad = false;
			break;
		}//Una vez verificado que le primer digito de la derecha forma parte de un numero escalera
		if(i == (cont/2+1))//si llegamos al punto medio del numero
		for(int j = i-1;j>0;--j)//verificamos los siguientes digitos con otro forma desde n/2 + 1,...,3,2,1
		{
			aux = otroA - (otroA/10) * 10;//seguimos obteniendo digito tras digito del numero de la misma manera que en lineas posteriores
			otroA = otroA/10;
			if(j != aux)//verificacion de que el digiyto del numero forma parte de la estructura de un numero escalera
			{
				verdad = false;//si no forma parte de la estructura de un numero escalera entonces no es necesario seguir
				break;
			}
		}
	}
	return verdad;
}
int main()
{
	//Ejercicio de la pagina Omega
	/*
	Si el número es escalera, imprimir el mensaje "es escalera inicialmente". En caso de que no lo sea pero se
	pueda arreglar después del primer intento, imprimir el mensaje "es escalera despues del primer intento". En
	caso de que hasta el segundo intento se pueda obtener un número escalera, imprimir el mensaje "es escalera
	despues del segundo intento". En caso de que no sea posible obtener un número escalera, imprimir el mensaje "nos rendimos".
	*/
	int N,A,B;//A y B son dos numero dados para poder corregir en caso de que el numero N no sea escalera
	cin>>N>>A>>B;//como solo estoy practicando las instrucciones estaran en los cometarios xd
	if(esc(N))
		cout<<"es escalera inicialmente";
	else
	{
		N = (N-A)/(B+1);
		if(esc(N))
			cout<<"es escalera despues del primer intento";
		else
		{
			N = N - (A+B) + 1;
			if(esc(N))
				cout<<"es escalera despues del segundo intento";
			else
				cout<<"nos rendimos";
		}
	}
}
