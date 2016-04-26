#include "Arme.h"
#include "Personnage.h"

using namespace std;

/* --------Constructeurs-------- */

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

void Arme::changer(string name, int damage, int cooldown) {

    m_name = name;
    m_damage = damage;
    m_cooldown = cooldown;
}

bool Arme::checkHitbox(Direction dir, Position posJoueur, Position posEnnemi) {
	return 0;
}
