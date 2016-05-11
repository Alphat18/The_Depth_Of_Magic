#ifndef THE_DEPTHS_OF_MAGIC_HERO_H
#define THE_DEPTHS_OF_MAGIC_HERO_H

#include <vector>
#include <list>

#include "Personnage.h"
#include "Lance.h"
#include "Tilemap.h"
#include "Ennemi.h"

class Hero : public Personnage {

public:

    Hero(int hp, int mana, int vitesse, int defense);
    void gestionAttaque(std::list<Ennemi *> &ennemiList);
    void gestionAttaqueDistance(std::list<Ennemi *> &ennemiList, std::list<Projectile *> &projectileList);
    void move(std::vector<std::vector<int> >* level, sf::Vector2u tileSize,int width);
    int changementDeMap ( std::vector<std::vector<int> >* level,sf::Vector2u tileSize );
	std::string GestionMap( std::vector<std::vector<int> >* level,sf::Vector2u tileSize);

protected:
    std::string m_name;
    Map m_map;

};


#endif //THE_DEPTHS_OF_MAGIC_HERO_H
