//
// Created by robin on 14/01/16.
//
#include <SFML/Graphics.hpp>

#include "Ennemi.h"
#include <list>
#include <math.h>

/* --------Constructeurs-------- */
Ennemi::Ennemi(int hp, int mana, int vitesse, int defense) : Personnage(hp, mana, vitesse, defense)
{
    m_taille_sprite.largeur=50;
    m_taille_sprite.hauteur=60;

    m_image="Ennemi.png";

    // Initialisation du sprite
    Tex.loadFromFile(m_image);
    sprite.setTexture(Tex);
    sprite.setTextureRect(sf::Rect<int>(0,0,60,70));
    sprite.setPosition(m_pos.x,m_pos.y);
}

/* --------Autres Modalit�s-------- */

void Ennemi::IAEnnemiBase(Position PosPers,std::vector<std::vector<int> >* level, sf::Vector2u tileSize,int width) {

    if (fabs(m_pos.x-PosPers.x)>fabs(m_pos.y-PosPers.y))
    {
        if (m_pos.x>PosPers.x)
        {
            Sprite(LEFT);
            if ( not(Walkable(LEFT,m_pos.x-m_vitesse,m_pos.y,level,tileSize,width)) )
            {
                if (Walkable(DOWN,m_pos.x,m_pos.y+m_vitesse,level,tileSize,width))

                    m_pos.y+=m_vitesse;
                else if (Walkable(UP,m_pos.x,m_pos.y-m_vitesse,level,tileSize,width))
                    m_pos.y-=m_vitesse;
                else if (Walkable(RIGHT,m_pos.x+m_vitesse,m_pos.y,level,tileSize,width))
                    m_pos.x+=m_vitesse;
                else
                    m_pos.x+=m_vitesse;
            }
            else
            {
                m_pos.x-=m_vitesse;
            }
        }
        else
        {
            Sprite(RIGHT);
            if ( not(Walkable(RIGHT,m_pos.x+m_vitesse,m_pos.y,level,tileSize,width)) )
            {
                if (Walkable(DOWN,m_pos.x,m_pos.y+m_vitesse,level,tileSize,width))
                    m_pos.y+=m_vitesse;
                else if (Walkable(UP,m_pos.x,m_pos.y-m_vitesse,level,tileSize,width))
                    m_pos.y-=m_vitesse;
                else if (Walkable(LEFT,m_pos.x-m_vitesse,m_pos.y,level,tileSize,width))
                    m_pos.x-=m_vitesse;
                else
                    m_pos.x-=m_vitesse;
            }
            else
            {
                m_pos.x+=m_vitesse;
            }
        }
    }
    else
    {
        if (m_pos.y>PosPers.y)
        {

            Sprite(UP);

            if ( not(Walkable(UP,m_pos.x,m_pos.y-m_vitesse,level,tileSize,width)) )
            {
                if (Walkable(LEFT,m_pos.x-m_vitesse,m_pos.y,level,tileSize,width))
                    m_pos.x-=m_vitesse;
                else if (Walkable(RIGHT,m_pos.x+m_vitesse,m_pos.y,level,tileSize,width))
                    m_pos.x+=m_vitesse;
                else if (Walkable(DOWN,m_pos.x,m_pos.y+m_vitesse,level,tileSize,width))
                    m_pos.y+=m_vitesse;
                else
                    m_pos.y+=m_vitesse;
            }
            else
            {
                m_pos.y-=m_vitesse;
            }

        }
        else
        {

            Sprite(DOWN);
            if ( not(Walkable(DOWN,m_pos.x,m_pos.y+m_vitesse,level,tileSize,width)) )
            {
                if (Walkable(LEFT,m_pos.x-m_vitesse,m_pos.y,level,tileSize,width))
                    m_pos.x-=m_vitesse;
                else if (Walkable(RIGHT,m_pos.x+m_vitesse,m_pos.y,level,tileSize,width))
                    m_pos.x+=m_vitesse;
                else if (Walkable(UP,m_pos.x,m_pos.y-m_vitesse,level,tileSize,width))
                    m_pos.y-=m_vitesse;
                else
                    m_pos.y-=m_vitesse;
            }
            else
            {
                m_pos.y+=m_vitesse;
            }
        }
    }

}

int compare2nodes(noeud n1, noeud n2)
{
    if (n1.heuristique<n2.heuristique)
        return 1;

    else if (n1.heuristique==n2.heuristique)
        return 0;

    else
        return -1;

};

int calculHeur(noeud n1, noeud n2)
{
    return floor(sqrt( (n1.x-n2.x)*(n1.x-n2.x) + (n1.y-n2.y)*(n1.y-n2.y) ));
}

/* --------Destructeurs-------- */

Ennemi::~Ennemi() {

    sprite.~Drawable();

}
