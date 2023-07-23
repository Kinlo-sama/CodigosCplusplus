#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int>cola;
    for(int i = 0; i < n;++i)
        cola.push_back(arr[i]);
    int mayor = cola.front();
    for(int i = 0; i < k;++i)
        if(mayor < cola[i])
            mayor = cola[i];
    //Tenemos dos casos
    //Si el elemento despues del pop era el mayor tendremos que buscar el mayor en el conjunto K
    //en caso contrario solo comparamos el mayor con el elemento k - 1                        3 4 6 3 4
    int frente_ant = cola.front();
    int lim_sup = k;
    int k_aux = k - 1;
    cola.pop_front();
    cout<<mayor<<" ";
    while(k_aux < n - 1){
        if(frente_ant == mayor){//Si se perdio al mayor al hacer pop entonces
            mayor = cola.front();
            for(int i = 0; i < k;++i){
                if(mayor < cola[i])
                    mayor = cola[i];
            }
        }else{
            if(mayor < cola[k-1])
                mayor = cola[k-1];
        }
        ++lim_sup;
        frente_ant = cola.front();
        ++k_aux;
        cola.pop_front();
        cout<<mayor<<" ";
    }
    cout<<endl;
}

int main(){

	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
