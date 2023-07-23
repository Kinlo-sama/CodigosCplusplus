#include "Vertices_03.h"
#include "Vertices_04.h"
#include <SFML/System.hpp>
int main(){
    TileMap tile;
    sf::RenderWindow ventana(sf::VideoMode(512,256),"Particulas");
    Particula particulas(1000);
    sf::Clock clock;
    const int nivel[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        4, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    if(!tile.load("../../../Recursos/Imagenes/Tileset.png",sf::Vector2u(32,32),nivel,16,8))
        return -1;
    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                ventana.close();
        }
        sf::Vector2i mouse = sf::Mouse::getPosition(ventana);
        particulas.setEmision(ventana.mapPixelToCoords(mouse));

        sf::Time transcurrido = clock.restart();
        particulas.actualizar(transcurrido);
        ventana.clear();
        ventana.draw(particulas);
        ventana.display();

    }
}
