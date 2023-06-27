#include <SFML/Graphics.hpp>
#include <iostream>
int main(){
    //La clase CircleShape no es mas que un radio con muchos lados a lo cual no lleva a la posibilidad de crear poligonos regulares con esta clase definienoo
    //n lados para el poligono regular, 3 para el rectangulo 4 para el cuadrado, 5 para el pentagono, etc...
    sf::RenderWindow ventana(sf::VideoMode(500,500),"Ventana para formas");
    sf::CircleShape forma(50.f);
    sf::CircleShape triangulo(50.f,3);
    sf::CircleShape cuadrado(50.f,4);
    sf::CircleShape pentagono(50.f,5);
    triangulo.setFillColor(sf::Color::Yellow);
    triangulo.setPosition(100,0);
    cuadrado.setFillColor(sf::Color::Black);
    cuadrado.setPosition(200,0);
    pentagono.setFillColor(sf::Color::Blue);
    pentagono.setPosition(300,0);
    //forma.setFillColor(sf::Color::Red);
    forma.setOutlineThickness(1.f);
    forma.setOutlineColor(sf::Color::Black);
    sf::Texture textura;
    if(!textura.loadFromFile("../../Recursos/Imagenes/JasGame2.png")){
        std::cout<<"Error:"<<std::endl;
    }
    textura.setSmooth(true);
    forma.setTexture(&textura);
    forma.setTextureRect(sf::IntRect(0,0,300,424));
    forma.setPointCount(800);
    while(ventana.isOpen()){
        sf::Event evento;

        while(ventana.pollEvent(evento)){
                if(evento.type == sf::Event::Closed){
                    ventana.close();
                }
            ventana.clear(sf::Color::White);
            ventana.draw(forma);
            ventana.draw(triangulo);
            ventana.draw(cuadrado);
            ventana.draw(pentagono);
            ventana.display();
        }

    }
}
