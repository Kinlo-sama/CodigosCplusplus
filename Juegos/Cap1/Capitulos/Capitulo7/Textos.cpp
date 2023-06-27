//Creacion de textos
#include <SFML/Graphics.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window.hpp>
#include <iostream>
int main(){
    sf::Font fuente;
    if(!fuente.loadFromFile("../../Recursos/Fuentes/arial.ttf")){
        std::cout<<"Error..."<<std::endl;
    }
    sf::Text texto;
    texto.setFont(fuente);
    texto.setString("Hola mundo");
    texto.setFillColor(sf::Color::Red);
    texto.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::RenderWindow ventana(sf::VideoMode(300,300),"Ventana");
    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                ventana.close();
            }
            ventana.clear(sf::Color::White);
            ventana.draw(texto);
            ventana.display();
        }
    }
}

