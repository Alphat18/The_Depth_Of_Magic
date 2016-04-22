#include <iostream>

#include "..\include\Hero.h"
#include "..\include\Lance.h"


/* --------Constructeurs-------- */

Hero::Hero(int hp, int mana, int vitesse, int defense) : Personnage(hp, mana, vitesse, defense)
{
    m_pos.x = 200;
    m_pos.y = 200;

    m_image = "sprites/perso.png";

    m_arme = new Arc("arc en bois", 10, 5);

    // Initialisation du sprite
    m_tex.loadFromFile(m_image);
    m_sprite.setTexture(m_tex);
    m_sprite.setTextureRect(sf::Rect<int>(0,0,60,70));
    m_sprite.setPosition(m_pos.x,m_pos.y);

}

/* --------Modalités get-------- */

/* --------Autres Modalités-------- */

void Hero::gestionAttaque(std::list<Ennemi *> &ennemiList) {

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (m_arme->getCompteur() > m_arme->getCooldown())) {
        m_arme->zeroCompteur();

        for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor)
        {
            (*itor)->resetStatus();
        }
    }

    if ((m_arme->getCompteur() == 0) || (m_arme->getCompteur() == 1) || (m_arme->getCompteur() == 2))
    {
        m_arme->changeSprite(m_dir);

        for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor)
        {
            if ((*itor)->getstatus() == NORMAL)
                attaquer((**itor));
            std::cout << (*itor)->gethp() << std::endl;
            std::cout << (*itor)->getstatus() << std::endl;
        }
    }

    m_arme->incrCompteur(m_arme->getCooldown());
}

void Hero::gestionAttaqueDistance(std::list<Ennemi *> &ennemiList, std::list<Projectile *> &projectileList) {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (m_arme->getCompteur() > m_arme->getCooldown())) {
        m_arme->zeroCompteur();

        for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor)
        {
            (*itor)->resetStatus();
        }
    }

    if (m_arme->getCompteur() == 0)
    {
        m_arme->changeSprite(m_dir);
        projectileList = tirer(projectileList);

        for (std::list<Ennemi *>::iterator itor = ennemiList.begin(); itor != ennemiList.end(); ++itor)
        {
            if ((*itor)->getstatus() == NORMAL)
            {

            }
        }
    }
    m_arme->incrCompteur(m_arme->getCooldown());
}

void Hero::move(std::vector<std::vector<int> >* level,sf::Vector2u tileSize,int width) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        Sprite(UP);
        if ( Tilemap::getTileNumber(m_pos.x+50,m_pos.y-5,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+15,m_pos.y-5,level,tileSize)==1 )
        {}
        else {
            m_pos.y-=m_vitesse;
        }

    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Sprite(DOWN);
        if ( Tilemap::getTileNumber(m_pos.x+50,m_pos.y+65,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+15,m_pos.y+65,level,tileSize)==1 )
        {}
        else {
            m_pos.y+=m_vitesse;
        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Sprite(RIGHT);
        if ( Tilemap::getTileNumber(m_pos.x+55,m_pos.y+15,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+55,m_pos.y+60,level,tileSize)==1 )
        {}
        else {
            m_pos.x+=m_vitesse;
        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        Sprite(LEFT);
        if ( Tilemap::getTileNumber(m_pos.x+10,m_pos.y+15,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+10,m_pos.y+60,level,tileSize)==1 )
        {}
        else {
            m_pos.x-=m_vitesse;
        }
    }
}

bool Hero::changementDeMap ( std::vector<std::vector<int> >* level,sf::Vector2u tileSize )
{
    bool MyBool=false;
    MyBool=(((Tilemap::getTileNumber(m_pos.x,m_pos.y,level,tileSize)==2) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur,m_pos.y,level,tileSize)==2)) or ((Tilemap::getTileNumber(m_pos.x-5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==2) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==2)) or((Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-3,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==2) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-3,m_pos.y,level,tileSize)==2)) or ((Tilemap::getTileNumber(m_pos.x+5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==2) or (Tilemap::getTileNumber(m_pos.x+5,m_pos.y,level,tileSize)==2))) ;
    return MyBool;
}
