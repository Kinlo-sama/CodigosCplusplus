/*Inicializacion de un arreglo bidimensional de n*n dimensiones*/
#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

int main()
{
int **a,n;
cout<<"Digite el tamaño del arreglo n*n que desea crear:";
cin>>n;
a = new int*[n];
for(int i = 0; i < n; ++i)
	{	
	a[i] = new int[n];
	for(int j = 0; j < n; ++j)
		a[i][j] = 10 * i + j;
	}
cout<<"La matriz de"<<n<<"*"<<n<<" ha sido inicializada con algunas valores y ahora sera visualizada..."<<endl
	<<"			USANDO LA FORMA DE INDEXISACION"<<endl;
for(int i = 0; i < n; ++i)
{
	for(int j = 0; j < n; ++j)
		cout<<a[i][j]<<" ";
	cout<<endl;
}
cout<<"			USANDO LA ARITMETICA DE PUNTERO"<<endl;
for(int i = 0; i < n; ++i)
{
	for(int j = 0; j < n; ++j)
		cout<<*(*(a + i) + j)<<" ";
	cout<<endl;
}
return 0;
}

