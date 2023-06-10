#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;

int main()
{
const int N = 1000;
int i,j,a[N+1];
for(a[1] = 0, i = 2; i <= N; ++i)
a[i] = 1;
//1 no es primero y despues del 2 supondremos que son primos
for(i = 2; i <= N/2; ++i)
	for(j = 2; j <= N/i; ++j)
	a[i * j] = 0;
/*
Aqui es simple ver que los primos son numero que solo pueden ser divididos entre si mismo y la unidad 
por ende si hay un par de numeros que multiplicados den ese numero no se considera primo, entonces
si al multiplicar pares de numeros entre 1 y 1000 se encontraran los numeros no primos y los numeros que no se 
encuentren en las multiplicaciones seran los primos ya que no es posibl obtenerlos si no hasta que se multipliquen 
por 1 por dicho numero y cada numero multiplicado obtendra un 0 que dentro del if representa un false  
*/
for( i = 1; i <= N; ++i)
	if(a[i])
	cout<<i<<endl;

return 0;
}
