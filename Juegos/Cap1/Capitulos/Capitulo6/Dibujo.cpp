#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
int main(){
    int cont = 0;
    sf::Texture textura;
    sf::Sprite sprite;

    while(!textura.loadFromFile("../../Recursos/Imagenes/JasGame2.png")){
        //Error
        break;
    }
    textura.setSmooth(true);
    sf::RenderWindow ventana(sf::VideoMode(1200,700),"Ventana");
    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                ventana.close();
            }
        }
        //sprite.setTextureRect(sf::IntRect(0,0,300,244));

        //sprite.setColor(sf::Color(0,255,0,44));
        if(evento.type == sf::Event::MouseMoved){
        sprite.setTexture(textura);
        sprite.scale(sf::Vector2f(.9f,.9f));
        sprite.move(sf::Vector2f(30.f,19.f));
        sprite.rotate(90.f);
        ventana.clear(sf::Color::Black);
        ventana.draw(sprite);
        sf::sleep(sf::milliseconds(100.0f));
        ventana.display();
        ++cont;
        if(cont%40 == 0){
            sprite.setPosition(sf::Vector2f(0.0f,0.0f));
            sprite.setScale(sf::Vector2f(1.0f,1.0f));
        }

        }



     }
     std::cout<<cont;
}

