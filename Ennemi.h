//
// Created by robin on 14/01/16.
//

#ifndef THE_DEPTHS_OF_MAGIC_Ennemi_H
#define THE_DEPTHS_OF_MAGIC_Ennemi_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tilemap.h"
#include "Personnage.h"

struct noeud {
    int x,y,cout,heuristique;
};

class Ennemi: public Personnage {

public :

    Ennemi(int hp, int mana, int vitesse, int defense);
    ~Ennemi();
    void IAEnnemiBase(Position PosPers,std::vector<std::vector<int> >* level, sf::Vector2u tileSize,int width);

protected :

};

int calculHeur(noeud n1, noeud n2);


#endif //THE_DEPTHS_OF_MAGIC_Ennemi_H
