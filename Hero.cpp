#include <iostream>

#include "Hero.h"
#include "Lance.h"


/* --------Constructeurs-------- */

Hero::Hero(int hp, int mana, int vitesse, int defense) : Personnage(hp, mana, vitesse, defense)
{
    m_pos.x = 200;
    m_pos.y = 200;

    m_image = "sprites/perso.png";
    m_status = NORMAL;

    m_arme = new Arc("arc en bois", 40, 8, m_pos.x, m_pos.y);
    m_taille_sprite.hauteur=70;
    m_taille_sprite.largeur=50;

    // Initialisation du sprite
    m_tex.loadFromFile(m_image);
    m_sprite.setTexture(m_tex);
    m_sprite.setTextureRect(sf::Rect<int>(0,0,60,70));
    m_sprite.setPosition(m_pos.x,m_pos.y);

	m_pos_map.i=3;
    m_pos_map.j=3;

    std::string mon_fichier = "../Map.txt";
    std::ifstream fichier;
    fichier.open(mon_fichier.c_str());

    for (int i=0;i<8;i++)
    {
        for (int j = 0; j < 8; ++j)
        {
           fichier >> m_map[i][j];
        }
    }
	/*for (int i=0;i<8;i++)
    {
        for (int j = 0; j < 8; ++j)
        {
            std::cout << m_map[i][j];
        }
        std::cout<<std::endl;
    }*/

    fichier.close();
}

/* --------Modalités get-------- */

/* --------Autres Modalités-------- */

void Hero::gestionAttaque(std::list<Ennemi *> &ennemiList) {

    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) && (m_arme->getCompteur() > m_arme->getCooldown())) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            m_dir = UP;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            m_dir = DOWN;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            m_dir = LEFT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            m_dir = RIGHT;

        m_arme->zeroCompteur();
        for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor) {
            (*itor)->resetStatus();
        }
    }


    if (m_arme->getCompteur() <= 2) {
        m_status = ATTAQUE;
        m_arme->changeSprite(m_dir);

        for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor) {
            if ((*itor)->getstatus() != TOUCHE)
                attaquer((**itor));
        }
    }
}

void Hero::gestionAttaqueDistance(std::list<Ennemi *> &ennemiList, std::list<Projectile *> &projectileList) {

    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) && (m_arme->getCompteur() > m_arme->getCooldown())) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            m_dir = UP;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            m_dir = DOWN;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            m_dir = LEFT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            m_dir = RIGHT;

        m_arme->zeroCompteur();

        for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor)
        {
            (*itor)->resetStatus();
        }
    }

    if (m_arme->getCompteur() <= 0) {
        m_status = ATTAQUE;
        m_arme->changeSprite(m_dir);
        projectileList = tirer(projectileList, m_dir);
    }
    else
        resetStatus();

    for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor)
    {
        if ((*itor)->getstatus() != TOUCHE)
            attaquerDistance(**itor, projectileList);
    }

    m_arme->incrCompteur(m_arme->getCooldown());
}

void Hero::move(std::vector<std::vector<int> >* level, sf::Vector2u tileSize, int width) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if (m_status != ATTAQUE)
            m_dir = UP;
        if ( Tilemap::getTileNumber(m_pos.x+50,m_pos.y-5,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+15,m_pos.y-5,level,tileSize)==1 )
        {}
        else {
            m_pos.y-=m_vitesse;
        }
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (m_status != ATTAQUE)
            m_dir = DOWN;
        if ( Tilemap::getTileNumber(m_pos.x+50,m_pos.y+65,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+15,m_pos.y+65,level,tileSize)==1 )
        {}
        else {
            m_pos.y+=m_vitesse;
        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (m_status != ATTAQUE)
            m_dir = RIGHT;
        if ( Tilemap::getTileNumber(m_pos.x+55,m_pos.y+15,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+55,m_pos.y+60,level,tileSize)==1 )
        {}
        else {
            m_pos.x+=m_vitesse;
        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        if (m_status != ATTAQUE)
            m_dir = LEFT;
        if ( Tilemap::getTileNumber(m_pos.x+10,m_pos.y+15,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+10,m_pos.y+60,level,tileSize)==1 )
        {}
        else {
            m_pos.x-=m_vitesse;
        }
    }
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
        Sprite(m_dir);
}

int Hero::changementDeMap ( std::vector<std::vector<int> >* level,sf::Vector2u tileSize ) {

    int myint=0;

    if (this->m_dir == RIGHT) {
        if (((Tilemap::getTileNumber(m_pos.x, m_pos.y, level, tileSize) == 3) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y, level, tileSize) == 3)) or
            ((Tilemap::getTileNumber(m_pos.x - 5, m_pos.y + m_taille_sprite.hauteur, level, tileSize) == 3) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y + m_taille_sprite.hauteur, level,
                                     tileSize) == 3)))
            myint = 3;

    }

    if (this->m_dir == LEFT) {
        if (((Tilemap::getTileNumber(m_pos.x, m_pos.y, level, tileSize) == 5) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y, level, tileSize) == 5)) or
            ((Tilemap::getTileNumber(m_pos.x - 5, m_pos.y + m_taille_sprite.hauteur, level, tileSize) == 5) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y + m_taille_sprite.hauteur, level,
                                     tileSize) == 5)))
            myint = 5;
    }

    if (this->m_dir == UP) {
        if (((Tilemap::getTileNumber(m_pos.x, m_pos.y, level, tileSize) == 2) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y, level, tileSize) == 2)) or
            ((Tilemap::getTileNumber(m_pos.x - 5, m_pos.y + m_taille_sprite.hauteur, level, tileSize) == 2) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y + m_taille_sprite.hauteur, level,
                                     tileSize) == 2)))
            myint = 2;
    }

    if (this->m_dir == DOWN) {
        if (((Tilemap::getTileNumber(m_pos.x, m_pos.y, level, tileSize) == 4) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y, level, tileSize) == 4)) or
            ((Tilemap::getTileNumber(m_pos.x - 5, m_pos.y + m_taille_sprite.hauteur, level, tileSize) == 4) or
             (Tilemap::getTileNumber(m_pos.x + m_taille_sprite.largeur, m_pos.y + m_taille_sprite.hauteur, level,
                                     tileSize) == 4)))
            myint = 4;

    }
    return myint;

}

/*std::string Hero::GestionMap(std::vector<std::vector<int> >* level,sf::Vector2u tile_size) {

    std::string NomCase="test";

    switch (changementDeMap(level,tile_size)) {
        case 2 :
            m_pos_map.i -= 1;
            NomCase+= std::to_string(m_map[m_pos_map.i][m_pos_map.j]);
            m_pos.y+=700;
            break;
        case 3 :
            m_pos_map.j += 1;
            NomCase+= std::to_string(m_map[m_pos_map.i][m_pos_map.j]);
            m_pos.x-=1050;
            break;
        case 4 :
            m_pos_map.i += 1;
            NomCase+= std::to_string(m_map[m_pos_map.i][m_pos_map.j]);
            m_pos.y-=700;
            break;
        case 5 :
            m_pos_map.j -= 1;
            NomCase+= std::to_string(m_map[m_pos_map.i][m_pos_map.j]);
            m_pos.x+=1050;
            break;
    }


    return NomCase;

}*/
