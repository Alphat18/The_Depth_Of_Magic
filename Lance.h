//
// Created by root on 2/16/16.
//

#ifndef THE_DEPTHS_OF_MAGIC_LANCE_H
#define THE_DEPTHS_OF_MAGIC_LANCE_H

#include "Arme.h"

class Lance : public Arme {

public:

    Lance(std::string name, int damage, int cooldown, Position posHero);

    void followHero(Position posHero, Direction dir);
    void changeSprite(Direction dir);
    bool checkHitbox(sf::FloatRect ennemiBoundingBox);

protected:

};


#endif //THE_DEPTHS_OF_MAGIC_LANCE_H
