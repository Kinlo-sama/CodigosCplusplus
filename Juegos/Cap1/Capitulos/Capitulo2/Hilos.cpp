#include <iostream>
#include <SFML/System.hpp>
using namespace std;

void funcion(){
    for(int i = 0; i < 10; ++i){
        cout << "Numero:"<<i<<endl;
    }
}

int main(){
    sf::Thread hilo(&funcion);

    hilo.launch();

    for(int i = 0; i < 3;++i){
        cout<<"Main numero:"<<1+i<<endl;
    }
}
