#ifndef THE_DEPTHS_OF_MAGIC_LANCE_H
#define THE_DEPTHS_OF_MAGIC_LANCE_H

#include "Arme.h"
#include "Structures.h"

class Lance : public Arme {

public:

    // constructeurs
    Lance(std::string name, int damage, int cooldown, int posx, int posy);

    // autres modalites
    void followHero(Position posHero, Direction dir);
    void changeSprite(Direction dir);

protected:

};


#endif //THE_DEPTHS_OF_MAGIC_LANCE_H
