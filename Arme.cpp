#include "..\include\Arme.h"
#include "..\include\Personnage.h"

/* --------Constructeurs-------- */

Arme::Arme(std::string name, int damage) : m_name(name), m_damage(damage)
{
    m_compteurArme = 0;
    m_boundingBox = sprite.getGlobalBounds();
}

Arme::Arme(std::string name, int damage, int cooldown) : m_name(name), m_damage(damage), m_cooldown(cooldown)
{
    m_compteurArme = 0;
    m_boundingBox = sprite.getGlobalBounds();
}

/* --------Modalités get-------- */

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

/* --------Autres Modalités-------- */

bool Arme::checkHitbox(sf::FloatRect ennemiBoundingBox) {
    return (m_boundingBox.intersects(ennemiBoundingBox));
}

void Arme::followHero(Position posHero, Direction dir) {
}

void Arme::changeSprite(Direction dir) {
}
