#ifndef THE_DEPTHS_OF_MAGIC_PERSONNAGE_H
#define THE_DEPTHS_OF_MAGIC_PERSONNAGE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

#include "Structures.h"
#include "Projectile.h"
#include "Arc.h"

class Arme;

class Personnage {

public:
    // constructeurs et destructeurs
    Personnage();
    Personnage(int hp, int mana, int vitesse, int defense);
    virtual ~Personnage();

    // get and set
    std::string getimage();
    int gethp();
    PosMap getPosMap();
    Position getpos();
	void setPos(int x, int y);
    Direction getdir();
    sf::Sprite getsprite();
    sf::FloatRect gethitbox();
    Status getstatus();
    void resetStatus();
    sf::Sprite getspriteArme();

	Arc* getarme();

	// autres modalites
	void estTouche(int damages);
    bool persoIsDead();
    void gestionAttaque(Personnage &perso);
    void attaquer(Personnage &ennemi);
    void attaquerDistance(Personnage &ennemi, std::list<Projectile *> &projectileList);
    std::list<Projectile *> tirer(std::list<Projectile *> &projectileList, Direction dir);

protected:

    void Sprite(Direction dir);
    bool Walkable(Direction dir, int x, int y, std::vector<std::vector<int> >* level, sf::Vector2u tileSize, int width);

    // attributs
    int m_hp;
    int m_mana;
    int m_compteurPerso;
    int m_vitesse;
    int m_attaque;
    int m_defense;

    Arc *m_arme;

    Status m_status;
    std::string m_image;
    Direction m_dir;
    Position m_pos;
    sf::Sprite m_sprite;
    sf::Texture m_tex;
    Taille m_taille_sprite;
    sf::FloatRect m_boundingBox;
    PosMap m_pos_map;

};


#endif //THE_DEPTHS_OF_MAGIC_PERSONNAGE_H
