#include <SFML/Graphics.hpp>
class TileMap : public sf::Drawable, public sf::Transformable{
private:
    sf::Texture m_tileset;
    sf::VertexArray m_vertices;
public:
    /*
    tileset ->Nombre del archivo donde se almacenan los mosaicos
    tileSize->Tamaño de cada mosaico
    tiles   ->Arreglo de como estara organizado los mosaicos
    width   ->Ancho de tiles
    height  ->Altura de tiles
    */
    bool load(const std::string &tileset,sf::Vector2u tileSize,const int *tiles, unsigned int width,unsigned int height){

        if(!m_tileset.loadFromFile(tileset))//Cargamos la textura de una ubicacion dada por tileset
            return false;
        m_vertices.setPrimitiveType(sf::Triangles);//Como vamos a dibujar los vertices, con base a triangulos
        m_vertices.resize(width * height * 6);//cada punto en tiles tiene 6 vertices los cuales forman el cuadrado

        //Regularmente nos movemos con el primer for por las filas y con el segundo por las columnas, aqui sera diferente
        for(int i = 0; i < width; ++i){
            for(int j = 0; j < height; ++j){
                //Primero obtener lugar que se ocupa en tiles actualmente con i y j
                int numero_en_tile = tiles[i + j * width];
                //Ahora ubicamos la posicion del tile actual en la textura
                int tu = numero_en_tile % (m_tileset.getSize().x / tileSize.x);
                int tv = numero_en_tile / (m_tileset.getSize().x / tileSize.x);
                //Obtenemos un puntero al lugar donde dibujaremos el cuadrado actual
                sf::Vertex *triangulo = &m_vertices[(i + j * width) * 6];
                //Ubicamos donde dibujaremos los vertices en la pantalla
                triangulo[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);//Encontramos el vertice izquierdo superior
                triangulo[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);//Vertice derecho superior
                triangulo[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);//Vertice izquierdo inferior
                triangulo[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);//Empezamos el nuevo triangulo
                triangulo[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);//Vertice derecho superior
                triangulo[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);//Vertice derecho inferior
                //Abora ubicaremos que parte de la textura usaremos para este mosaico o tile
                triangulo[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                triangulo[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangulo[2].texCoords = sf::Vector2f((tu * tileSize.x), (tv + 1) * tileSize.y);
                triangulo[3].texCoords = sf::Vector2f((tu * tileSize.x), (tv + 1) * tileSize.y);
                triangulo[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                triangulo[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x,(tv + 1) * tileSize.y);
                //Fin para el posicionamiento de vertices y obtencion de una imagen de la textura
            }
        }
        return true;
    }
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const{
        states.transform *= getTransform();
        states.texture = &m_tileset;
        target.draw(m_vertices,states);
    }
};
