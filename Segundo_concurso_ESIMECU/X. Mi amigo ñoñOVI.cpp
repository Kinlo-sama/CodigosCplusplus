#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N; cin >> N;
    while(N--){
        int x,y;    cin >> x >> y;
        int div_n = x / y;
        int div_a = ceil(static_cast<double>(x) / y);
        cout << div_a <<  " " << div_n << endl;
        int factor_a = x - div_a * y;
        int factor_n = x - div_n * y;
        if( factor_a < factor_n)
            cout << y * div_n << endl;
        else
            cout << y * div_a << endl;
    }
}
