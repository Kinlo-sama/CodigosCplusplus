#include <SFML/Graphics.hpp>

int main(){
    sf::ContextSettings configuracion;
    configuracion.antialiasingLevel = 8;

    sf::RenderWindow ventana(sf::VideoMode(500,500),"Ventana para formas convexas",sf::Style::Default,configuracion);
    sf::ConvexShape convexa;
    convexa.setPointCount(5);

    convexa.setPoint(0,sf::Vector2f(10,30));
    convexa.setPoint(1,sf::Vector2f(100,50));
    convexa.setPoint(2,sf::Vector2f(120,90));
    convexa.setPoint(3,sf::Vector2f(40,50));
    convexa.setPoint(4,sf::Vector2f(10,50));
    convexa.setFillColor(sf::Color::Blue);
    //Para el dado de las lineas no hay clases definidas asi que usamos RectatangShape para dibujarlas cuando la linea no tiene grosor, en caso de tenerla se le llama
    //rectangulo
    sf::RectangleShape lineaR(sf::Vector2f(300.f,5.f));//Esto es una linea con relleno
    sf::Vertex lineaSR[] =
    {
        sf::Vector2f(10.f,10.f),
        sf::Vector2f(150.f,150.f)
    };
    lineaR.setFillColor(sf::Color::Black);
    lineaR.setPosition(sf::Vector2f(100,100));
    lineaR.setRotation(45.f);
    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed){
                ventana.close();
            }
            ventana.clear(sf::Color::Cyan);
            ventana.draw(convexa);
            ventana.draw(lineaR);
            ventana.draw(lineaSR,2,sf::Lines);
            ventana.display();
        }
    }
}
