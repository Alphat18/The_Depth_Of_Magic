//
// Created by robin on 02/02/16.
//

#ifndef THE_DEPTHS_OF_MAGIC_HERO_H
#define THE_DEPTHS_OF_MAGIC_HERO_H


#include "Personnage.h"
#include "Lance.h"
#include "Tilemap.h"
#include "Ennemi.h"
#include <vector>

class Hero : public Personnage{

public:

    Hero(int hp, int mana, int vitesse, int defense);

    sf::Sprite getspriteArme();
	Lance* getarme();

    void gestionAttaque(sf::FloatRect ennemiBoundingBox, Ennemi &ennemi);
    void attaquer(sf::FloatRect ennemiBoundingBox, Ennemi &ennemi);
    void move(std::vector<std::vector<int> >* level, sf::Vector2u tileSize,int width);
    int changementDeMap ( std::vector<std::vector<int> >* level,sf::Vector2u tileSize );
	std::string GestionMap( std::vector<std::vector<int> >* level,sf::Vector2u tileSize);

protected:
    std::string m_name;
    Lance* m_arme;
    Map m_map;

};


#endif //THE_DEPTHS_OF_MAGIC_HERO_H
