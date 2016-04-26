#ifndef THE_DEPTHS_OF_MAGIC_ARME_H
#define THE_DEPTHS_OF_MAGIC_ARME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Personnage.h"

class Arme {

public:

    Arme(std::string name, int damage, int cooldown);

    sf::Sprite getsprite();
    const int getDamage();

    void changer(std::string name, int damage, int cooldown);
    bool checkHitbox(Direction dir, Position posJoueur, Position posEnnemi);

    void incrCompteur(int cooldown);
    void zeroCompteur();
    int getCompteur();
    int getCooldown();

protected:

    int m_damage;
    int m_cooldown;
    int m_compteurArme;
    int m_countSprite;
    std::string m_name;
    std::string m_image;
    Position m_pos;
    sf::Sprite sprite;
    sf::Texture TexArme;
    sf::FloatRect m_boundingBox;
};

#endif //THE_DEPTHS_OF_MAGIC_ARME_H
