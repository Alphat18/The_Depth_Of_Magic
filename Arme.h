#ifndef THE_DEPTHS_OF_MAGIC_ARME_H
#define THE_DEPTHS_OF_MAGIC_ARME_H

#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Structures.h"

class Personnage;

class Arme {

public:
    // constructeurs
    Arme(std::string name, int damage);
    Arme(std::string name, int damage, int cooldown);

    // get and set
    sf::Sprite getsprite();
    const int getDamage();
    void incrCompteur(int cooldown);
    void zeroCompteur();
    int getCompteur();
    int getCooldown();

    // autres modalites
    bool checkHitbox(sf::FloatRect ennemiBoundingBox);
    void followHero(Position posHero, Direction dir);
    void changeSprite(Direction dir);

protected:

    // attributs
    std::string m_name;
    int m_damage;
    int m_cooldown;
    int m_compteurArme;
    int m_countSprite;
    std::string m_image;

    Position m_pos;
    sf::Sprite sprite;
    sf::Texture TexArme;
    sf::FloatRect m_boundingBox;
};

#endif //THE_DEPTHS_OF_MAGIC_ARME_H
