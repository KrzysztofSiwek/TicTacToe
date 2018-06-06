#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "GameBoard.hpp"
class TileMap: public sf::Drawable, public sf::Transformable
{
public:
    //constructs graphiscal game map representation
    TileMap(int x,std::string tileSetName,sf::Vector2u tileSize, unsigned int w, unsigned int h):
       m_level(x),m_width(w),m_height(h){m_tileSize=tileSize;m_tileset.loadFromFile(tileSetName);};

    bool load();
    void update();
    GameBoard& getLevel(){return m_level;};
   private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    GameBoard m_level;
    sf::Vector2u m_tileSize;
    unsigned int m_width;
    unsigned int m_height;
};



#endif
