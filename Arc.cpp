#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "Arc.h"

Arc::Arc(std::string name, int damage, int cooldown, int posx, int posy) : Arme(name, damage, cooldown, posx, posy)
{
    m_image = "sprites/arc.png";
    m_countSprite = 0;

    // Initialisation du sprite
    TexArme.loadFromFile(m_image);
    sprite.setTexture(TexArme);
    sprite.setTextureRect(sf::Rect<int>(0,0,40,40));
    sprite.setPosition(m_pos.x,m_pos.y);

    m_boundingBox = sprite.getGlobalBounds();
}

Arc::~Arc()
{
    //dtor
}
