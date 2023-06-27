#include <SFML/Window.hpp>

int main(){
    sf::Window window;
    window.create(sf::VideoMode(250,250),"Mi ventana");
    //Corremos el programa mientras la ventana este abierta
    while(window.isOpen()){
            //Verificamos cada evento desde la ultima iteracion del bucle
        sf::Event evento;
            while(window.pollEvent(evento)){//Si el evento es para cerrarlo entonces lo cerramos
                if(evento.type == sf::Event::Closed){
                    window.close();
                }
                if(evento.type == sf::Event::MouseEntered){
                    window.setSize(sf::Vector2u(500,500));
                    window.setPosition(sf::Vector2i(0,0));
                    window.setTitle("Me movi poque me tocaron >-<");
                }
            }

    }

}
