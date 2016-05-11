#include "Arme.h"
#include "Personnage.h"

/* --------Constructeurs-------- */

Arme::Arme(std::string name, int damage) : m_name(name), m_damage(damage)
{
    m_compteurArme = 10;
    m_boundingBox = sprite.getGlobalBounds();
}

Arme::Arme(std::string name, int damage, int cooldown, int posx, int posy) : m_name(name), m_damage(damage), m_cooldown(cooldown)
{
    m_compteurArme = 10;
    m_boundingBox = sprite.getGlobalBounds();
}

/* --------Modalit�s get-------- */

const int Arme::getDamage() {
    return m_damage;
}

sf::Sprite Arme::getsprite() {
    return sprite;
}

void Arme::incrCompteur(int cooldown) {
    if (m_compteurArme <= cooldown)
        m_compteurArme++;
}

int Arme::getCompteur() {
    return m_compteurArme;
}

void Arme::zeroCompteur() {
    m_compteurArme = 0;
}

int Arme::getCooldown() {
    return m_cooldown;
}

/* --------Autres Modalites-------- */

bool Arme::checkHitbox(sf::FloatRect ennemiBoundingBox) {
    return (m_boundingBox.intersects(ennemiBoundingBox));
}

void Arme::followHero(Position posHero, Direction dir) {

    if (dir==DOWN)
    {
        m_pos.x = posHero.x;
        m_pos.y = posHero.y;
    }
    if (dir==UP)
    {
        m_pos.x = posHero.x;
        m_pos.y = posHero.y;
    }
    if (dir==LEFT)
    {
        m_pos.x = posHero.x;
        m_pos.y = posHero.y;
    }
    if (dir==RIGHT)
    {
        m_pos.x = posHero.x;
        m_pos.y = posHero.y;
    }

    sprite.setTextureRect(sf::Rect<int>(0,0,40,40));
    sprite.setPosition(m_pos.x,m_pos.y);
    m_boundingBox = sprite.getGlobalBounds();
}

void Arme::changeSprite(Direction dir) {
}
