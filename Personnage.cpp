//
// Created by robin on 23/12/15.
//

#include "Personnage.h"
#include "Tilemap.h"

/* --------Constructeurs-------- */
Personnage::Personnage()
{
    m_pos.x = 100;
    m_pos.y = 100;

    m_status = NORMAL;
    m_compteurPerso = 0;
    m_boundingBox = sprite.getGlobalBounds();
}

Personnage::Personnage(int hp, int mana, int vitesse, int defense) : m_hp(hp), m_mana(mana), m_vitesse(vitesse), m_defense(defense)
{
    m_pos.x = 100;
    m_pos.y = 100;
    m_status = NORMAL;
    m_compteurPerso = 0;
    m_boundingBox = sprite.getGlobalBounds();
}
/* --------Modalit�s get-------- */

std::string Personnage::getimage() {
	return m_image;
}

int Personnage::gethp() {
    return m_hp;
}

Position Personnage::getpos() {
    return m_pos;
}

sf::Sprite Personnage::getsprite() {
    return sprite;
}

Direction Personnage::getdir() {
    return m_dir;
}

sf::FloatRect Personnage::gethitbox() {
    return m_boundingBox;
}

Status Personnage::getstatus() {
    return m_status;
}

PosMap Personnage::getPosMap() {
    return m_pos_map;
}

void Personnage::resetStatus() {
    m_status = NORMAL;
}

/* --------Autres Modalit�s-------- */

void Personnage::estTouche(int damages) {
    m_hp -= (damages-m_defense);
    m_status = TOUCHE;
}

bool Personnage::persoIsDead() {
    return (m_hp <= 0);
}

void Personnage::setPos(int x, int y){
    this->m_pos.x=x;
    this->m_pos.y=y;
}

void Personnage::Sprite(Direction dir) {

    if (dir==DOWN)
    {
        m_compteurPerso+=60;
        m_dir = DOWN;

        sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,0,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    if (dir==RIGHT)
    {
        m_compteurPerso+=60;
        m_dir = RIGHT;

        sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,70,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    if (dir==LEFT)
    {
        m_compteurPerso+=60;
        m_dir = LEFT;

        sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,140,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    if (dir==UP)
    {
        m_compteurPerso+=60;
        m_dir = UP;

        sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,210,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    sprite.setPosition(m_pos.x,m_pos.y);
	m_boundingBox = sprite.getGlobalBounds();

}

bool Personnage::Walkable(Direction dir, int x, int y, std::vector<std::vector<int> >* level,  sf::Vector2u tileSize,int width) {

    switch (dir)
    {
        case UP : return not((Tilemap::getTileNumber(m_pos.x,m_pos.y,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur,m_pos.y,level,tileSize)==1));

        case DOWN: return not((Tilemap::getTileNumber(m_pos.x-5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1));

        case RIGHT: return not((Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-3,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-3,m_pos.y,level,tileSize)==1));

        case LEFT: return not ((Tilemap::getTileNumber(m_pos.x+5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+5,m_pos.y,level,tileSize)==1));
    }
}
