#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "Lance.h"

#define HLANCE 70
#define LLANCE 14

/* --------Constructeurs-------- */

Lance::Lance(std::string name, int damage, int cooldown, int posx, int posy) : Arme(name, damage, cooldown, posx, posy)
{

    m_image = "sprites/lance.png";
    m_countSprite = 0;

    // Initialisation du sprite
    TexArme.loadFromFile(m_image);
    sprite.setTexture(TexArme);
    sprite.setTextureRect(sf::Rect<int>(0,0,15,70));
    sprite.setPosition(m_pos.x,m_pos.y);

    m_boundingBox = sprite.getGlobalBounds();
}

/* --------Autres Modalités-------- */

void Lance::followHero(Position posHero, Direction dir) {

    if (dir==DOWN)
    {
        m_pos.x = posHero.x;
        m_pos.y = posHero.y;
    }
    if (dir==UP)
    {
        m_pos.x = posHero.x+50;
        m_pos.y = posHero.y;
    }
    if (dir==LEFT)
    {
        m_pos.x = posHero.x+4;
        m_pos.y = posHero.y;
    }
    if (dir==RIGHT)
    {
        m_pos.x = posHero.x+30;
        m_pos.y = posHero.y;
    }

    sprite.setTextureRect(sf::Rect<int>(0,0,LLANCE,HLANCE));
    sprite.setPosition(m_pos.x,m_pos.y);
    m_boundingBox = sprite.getGlobalBounds();
}

void Lance::changeSprite(Direction dir) {

    m_countSprite += HLANCE;
    if (m_countSprite >= 4*HLANCE)
        m_countSprite = HLANCE;

    if (dir == UP)
    {
        sprite.setTextureRect(sf::Rect<int>(0, m_countSprite, LLANCE, HLANCE));

        if (m_countSprite == HLANCE)
            sprite.setPosition(m_pos.x-28,m_pos.y-20);
        else if (m_countSprite == 2*HLANCE)
            sprite.setPosition(m_pos.x-28,m_pos.y-40);
        else if (m_countSprite == 3*HLANCE)
            sprite.setPosition(m_pos.x-28,m_pos.y-60);
    }
    else if (dir == DOWN)
    {
        sprite.setTextureRect(sf::Rect<int>(15, m_countSprite, LLANCE, HLANCE));

        if (m_countSprite == HLANCE)
            sprite.setPosition(m_pos.x+20,m_pos.y+20);
        else if (m_countSprite == 2*HLANCE)
            sprite.setPosition(m_pos.x+20,m_pos.y+40);
        else if (m_countSprite == 3*HLANCE)
            sprite.setPosition(m_pos.x+20,m_pos.y+60);
    }
    else if (dir == LEFT)
    {
        sprite.setTextureRect(sf::Rect<int>(30+m_countSprite-70, 10, HLANCE, LLANCE));

        if (m_countSprite == HLANCE)
            sprite.setPosition(m_pos.x-20,m_pos.y+45);
        else if (m_countSprite == 2*HLANCE)
            sprite.setPosition(m_pos.x-40,m_pos.y+45);
        else if (m_countSprite == 3*HLANCE)
            sprite.setPosition(m_pos.x-60,m_pos.y+45);
    }
    else if (dir == RIGHT)
    {
        sprite.setTextureRect(sf::Rect<int>(30+m_countSprite-70, -1, HLANCE, LLANCE));

            if (m_countSprite == HLANCE)
                sprite.setPosition(m_pos.x-30,m_pos.y+40);
            else if (m_countSprite == 2*HLANCE)
                sprite.setPosition(m_pos.x-10,m_pos.y+40);
            else if (m_countSprite == 3*HLANCE)
                sprite.setPosition(m_pos.x+10,m_pos.y+40);
    }
}
