#include <iostream>
using namespace std;

void for_i(int i){
    if(i == 0)
        return;
    else{
        for(int j = 0; j < 3;++i){
            cout<<j<<" ";
            for_i(--i);
        }
    }
}

int main(){
    for_i(3);
}
