#include <SFML/System.hpp>
#include <SFML/System/Thread.hpp>
#include <iostream>

using namespace std;
sf::Mutex mutex;

void func(){
    mutex.lock();
    for(int i = 0; i < 10;++i){
        cout<<"Numero:"<<i<<endl;
    }
    mutex.unlock();
}

int main(){
    sf::Thread thread(&func);
    thread.launch();

    mutex.lock();
    for(int i = 0; i <10;++i){
        cout<<"Principal por "<<i+1<<" vez"<<endl;
    }
    mutex.unlock();
}
