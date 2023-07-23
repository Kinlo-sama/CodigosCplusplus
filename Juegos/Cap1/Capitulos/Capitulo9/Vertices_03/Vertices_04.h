#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

class Particula : public sf::Transformable, public sf::Drawable{
private:
    struct particula{
        sf::Vector2f velocidad;
        sf::Time tiempoVida;
    };
    std::vector<particula> m_particulas;
    sf::VertexArray m_vertices;
    sf::Time m_tiempoVida;
    sf::Vector2f emision;

    void resetarParticula(size_t index){
        float angulo =(std::rand() % 360 ) * 3.1415 / 180.f;
        float vel = (std::rand() % 50 ) + 50.f;
        m_particulas[index].velocidad = sf::Vector2f(std::cos(angulo) * vel,std::sin(angulo) * vel);
        m_particulas[index].tiempoVida = sf::milliseconds((std::rand()%2000) + 1000);

        m_vertices[index].position = emision;
    }
public:
    Particula(size_t cont):
        m_vertices(sf::Points,cont),
        m_particulas(cont),
        m_tiempoVida(sf::seconds(3.f)),
        emision(0.f,0.f)
        {

        }
    void setEmision(sf::Vector2f posicion){
        emision = posicion;
    }

    void actualizar(sf::Time transcurrido){
        for(size_t i = 0; i < m_particulas.size(); ++i){
            //Primero obtener un puntero a la particula actual
            particula &p = m_particulas[i];
            p.tiempoVida -= transcurrido;
            //Si la particula esta muerta entonces reseteamos
            if( p.tiempoVida <= sf::Time::Zero)
                resetarParticula(i);
            //Ajuste de la transparencia con respecto a su tiempo transcurrido
            m_vertices[i].position += p.velocidad * transcurrido.asSeconds();
            float radio = p.tiempoVida.asSeconds() / m_tiempoVida.asSeconds();
            m_vertices[i].color.a = static_cast<sf::Uint8>(radio * 255);
        }
    }
private:
    virtual void draw(sf::RenderTarget &target,sf::RenderStates states)const{
        states.transform *= getTransform();
        states.texture = nullptr;
        target.draw(m_vertices,states);
    }
};
