#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow ventana(sf::VideoMode(250,250),"Graficos");

    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                ventana.close();
            }
        }
        ventana.clear(sf::Color::White);
        ventana.display();
    }
}
