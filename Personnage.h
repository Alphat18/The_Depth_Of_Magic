#ifndef THE_DEPTHS_OF_MAGIC_PERSONNAGE_H
#define THE_DEPTHS_OF_MAGIC_PERSONNAGE_H

#include <iostream>
#include <SFML/Graphics.hpp>


struct Position {
    int x;
    int y;
};

enum Direction {RIGHT,LEFT,UP,DOWN};
enum Status {NORMAL, TOUCHE};

struct Taille {
    int largeur,hauteur;
};

struct PosMap {
    int i,j;
};


class Personnage {

public:

    Personnage();
    Personnage(int hp, int mana, int vitesse, int defense);

    std::string getimage();
    int gethp();
    PosMap getPosMap();
    Position getpos();
    Direction getdir();
    sf::Sprite getsprite();
    sf::FloatRect gethitbox();
    Status getstatus();
    void resetStatus();

    void estTouche(int damages);
    bool persoIsDead();
    void setPos(int x, int y);
protected:

    void Sprite(Direction dir);
    bool Walkable(Direction dir, int x, int y, std::vector<std::vector<int> >* level, sf::Vector2u tileSize, int width);

    int m_hp;
    int m_mana;
    int m_compteurPerso;
    int m_vitesse;
    int m_attaque;
    int m_defense;

    Status m_status;
    std::string m_image;
    Direction m_dir;
    Position m_pos;
    sf::Sprite sprite;
    sf::Texture Tex;
    Taille m_taille_sprite;
    sf::FloatRect m_boundingBox;
    PosMap m_pos_map;

};


#endif //THE_DEPTHS_OF_MAGIC_PERSONNAGE_H
