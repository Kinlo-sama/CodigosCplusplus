#include <SFML/Graphics.hpp>
#include <iostream>
int main(){
    sf::RenderWindow ventana(sf::VideoMode(700,700),"VENTANA PARA VERTICES 02");
    sf::VertexArray camino_triangulos(sf::TriangleStrip,4);
    sf::Texture textura;
    if(!textura.loadFromFile("../../../Recursos/Imagenes/JasGame2.png"))
        std::cout<<"Error";

    //La figura que formaremos con el strip de triangulos sera un rectangulo con vertice izquierda superior en 10,10
    camino_triangulos[0].position = sf::Vector2f(10.f,10.f);
    camino_triangulos[1].position = sf::Vector2f(10.f,210.f);
    camino_triangulos[2].position = sf::Vector2f(210.f,10.f);
    camino_triangulos[3].position = sf::Vector2f(210.f,210.f);

    camino_triangulos[0].color = sf::Color::White;
    camino_triangulos[0].color = sf::Color::White;
    camino_triangulos[0].color = sf::Color::White;
    camino_triangulos[0].color = sf::Color::White;
    //Estas texCoords definen que parte de la textura se usara dentro de la forma creada
    camino_triangulos[0].texCoords = sf::Vector2f(0.f,0.f);
    camino_triangulos[1].texCoords = sf::Vector2f(0.f,424.f);
    camino_triangulos[2].texCoords = sf::Vector2f(300.f,0.f);
    camino_triangulos[3].texCoords = sf::Vector2f(300.f,424.f);



    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                ventana.close();
            //Para para el manejo de otro eventos que no sea cerrar la ventana
            ventana.clear(sf::Color::Blue);
            ventana.draw(camino_triangulos,&textura);
            ventana.display();
        }
    }

}
