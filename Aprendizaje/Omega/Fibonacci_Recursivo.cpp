#include <iostream>
using namespace std;

int Fib(int n,int &i){
    if( !n)
        return 0;
    if( n == 1)
        return 1;
    else
        return Fib(n-1,++i) + Fib(n-2,++i);
}

int main(){
    int N; cin>>N;
    int i = 0;
    cout<<Fib(N,i)<<" "<<++i;
}
