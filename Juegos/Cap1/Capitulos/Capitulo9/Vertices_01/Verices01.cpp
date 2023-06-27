#include <SFML/Graphics.hpp>
#include <vector>
int main(){
    sf::ContextSettings configuracion;
    configuracion.antialiasingLevel = 8;
    //Para crear un vertice
    sf::Vertex vertice(sf::Vector2f(10.f,15.f),sf::Color(12,34,34),sf::Vector2f(100.f,100.f));
    //Para definir una primitiva
    sf::VertexArray triangulo(sf::Triangles,3);
    //Definimos las caracteristicas de cada vertice
    triangulo[0].position = sf::Vector2f(10.f,10.f);
    triangulo[1].position = sf::Vector2f(100.f,10.f);
    triangulo[2].position = sf::Vector2f(100.f,100.f);

    triangulo[0].color = sf::Color(23,324,24);
    triangulo[1].color = sf::Color(43,43,21);
    triangulo[2].color = sf::Color(39,24,48);
    //Existen otras dos maneras de crear arreglos de vertices, una es a traves de vectores y otra es a traves de matrices
    //Para un vector
    /*
    std::vector<sf::Vertex> verticeVector;
    verticeVector.push_back(sf::Vertex(sf::Vector2f(10.f,15.f),sf::Color(23,23,42),sf::Vector2f(100.f,100.f)));
    verticeVector.push_back(sf::Vertex(sf::Vector2f(100.f,15.f),sf::Color(35,34,43),sf::Vector2f(100.f,100.f)));
    verticeVector.push_back(sf::Vertex(sf::Vector2f(100.f,100.f),sf::Color(34,66,24),sf::Vector2f(10.f,15.f)));
    */
    //Para un array que es un poco mas de codigo
    sf::Vertex vertices[3] = {
        sf::Vertex(sf::Vector2f(10.f,15.f),sf::Color(43,32,32),sf::Vector2f(100.f,15.f)),
        sf::Vertex(sf::Vector2f(100.f,15.f),sf::Color(23,53,64),sf::Vector2f(100.f,100.f)),
        sf::Vertex(sf::Vector2f(100.f,100.f),sf::Color(52,53,53),sf::Vector2f(10.f,15.f))
    };

    sf::RenderWindow ventana(sf::VideoMode(500,500),"Ventana para vertices",sf::Style::Default,configuracion);
    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){
            if(evento.type == sf::Event::Closed)
                ventana.close();
            ventana.clear(sf::Color::White);
            //ventana.draw(triangulo);//Usando VertexArray
            //ventana.draw(&verticeVector[0],verticeVector.size(),sf::Triangles); //Usando  un vector
            ventana.draw(vertices,3,sf::Triangles);
            ventana.display();
        }
    }
}
