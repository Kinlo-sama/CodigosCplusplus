#include <iostream>
#include <SFML/System/Time.hpp>
using namespace std;

int main(){
    sf::Time time= sf::seconds(23);
    sf::Int32 sec1 = time.asMicroseconds();//Micro como 10^6
    sf::Int64 sec2 = time.asMilliseconds();//mili como 10^3
    float sec3 = time.asSeconds();
    cout << "Segundos "<<sec3<<" como microsegundos:"<< sec1<<endl
         << "Segundos "<<sec3<<" como milisegundos:"<<  sec2<<endl;
    //Probemos ahora jugar con los valores de time
    sf::Time tiempo1 = sf::seconds(1);
    sf::Time tiempo2 = sf::milliseconds(1000);
    if( tiempo1 == tiempo2){
        cout<<"El tiempo1 con valor:"<<tiempo1.asSeconds()<<" segundos es igual a tiempo2 con valor:"<<tiempo2.asMilliseconds()<<" milisegundos"<<endl;
    }
    else{
        cout<<"Tiempo1 y tiempo2 no son iguales"<<endl;
    }
}

