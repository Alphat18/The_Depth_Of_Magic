#ifndef THE_DEPTHS_OF_MAGIC_TILEMAP_H
#define THE_DEPTHS_OF_MAGIC_TILEMAP_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <vector>
#include <fstream>

#include "Structures.h"

class Tilemap : public sf::Drawable {

public:

   bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<std::vector<int> >* tiles, unsigned int width, unsigned int height);
   static int getTileNumber(int x, int y,std::vector<std::vector<int> >* level,sf::Vector2u tileSize);
   static void loadLevelFromText(int* width, int* height,std::vector<std::vector<int> >* level);
private:

    virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    sf::VertexArray m_tableau;
    sf::Texture m_tileset;
};


#endif //THE_DEPTHS_OF_MAGIC_TILEMAP_H
