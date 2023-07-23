#include<iostream>
using namespace std;
int mcd(int a,int b){
    if(b == 0)
        return a;
    else
        return mcd(b,a % b);
}

struct fracc{
    int n;
    int d;
};
fracc irr_fracc(fracc f1){
    fracc final;
    int mcd_n_d = mcd(f1.d,f1.n);
    int a = f1.n / mcd_n_d, b = f1.d / mcd_n_d;
    final.n = a;
    final.d = b;
    return final;
}

void printFracc(fracc f1){
    if(f1.d == f1.n)
        cout<<1<<endl;
    else if(f1.d == 1)
        cout<<f1.n<<endl;
    else
        cout<<f1.n<<"/"<<f1.d<<endl;
}

int convertir(){
    string numero;
    cin>>numero;
    int numeroInt = stoi(numero);
    return numeroInt;
}
void binario(int a){
    if(a == 0)
        cout<<0;
    else{
        int aux = a;
        return binario(a / 2);
        cout<<aux % 2;
    }
}
// 18 -> 9 -> 4 -> 2 -> 1 -> 0
// 0 1 0 0 1 0
int main(){
    /*
    int x,y;
    while(cin>>x && cin>> y){
        if(x > 0 && y > 0){
            cout<<x<<":"<<y<<"->"<<mcd(x,y)<<endl;
        }
    }//Comprobacion*/
    //Fraccion irreducible
    /*//******************************************
    fracc f1,f2;
    f1.d = 28;
    f1.n = 21;
    f2 = irr_fracc(f1);
    printFracc(f1);
    printFracc(f2);
    //иииииииииииииииииииииииииииииииииииииииииии
    */
    //Lectura de cifra a cifra hasta encontrar espacio en blanco
    /*//******************************************
    int numero = convertir();
    cout<<numero;
    //ииииииииииииииииииииииииииииииииииииииииииии
    */
    cout<<9/2;
}
