#include "Hero.h"

/* --------Constructeurs-------- */

Hero::Hero(int hp, int mana, int vitesse, int defense) : Personnage(hp, mana, vitesse, defense)
{
    m_pos.x = 200;
    m_pos.y = 200;

    m_image = "perso.png";
    m_arme = new Lance("lance en bois", 35, 5, m_pos);

    m_taille_sprite.hauteur=70;
    m_taille_sprite.largeur=50;

    // Initialisation du sprite
    Tex.loadFromFile(m_image);
    sprite.setTexture(Tex);
    sprite.setTextureRect(sf::Rect<int>(0,0,60,70));
    sprite.setPosition(m_pos.x,m_pos.y);

    m_pos_map.i=3;
    m_pos_map.j=3;

    std::string mon_fichier = "Map.txt";
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

sf::Sprite Hero::getspriteArme()
{
    return m_arme->getsprite();
}

Lance* Hero::getarme()
{
    return m_arme;
}

/* --------Autres Modalités-------- */

void Hero::gestionAttaque(sf::FloatRect ennemiBoundingBox, Ennemi &ennemi) {

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (m_arme->getCompteur() > m_arme->getCooldown())) {
        m_arme->zeroCompteur();
        ennemi.resetStatus();
    }

    if ((m_arme->getCompteur() == 0) || (m_arme->getCompteur() == 1) || (m_arme->getCompteur() == 2))
    {
        m_arme->changeSprite(m_dir);
        if (ennemi.getstatus() == NORMAL)
            attaquer(ennemiBoundingBox, ennemi);
      //  std::cout << ennemi.gethp() << std::endl;
      //  std::cout << ennemi.getstatus() << std::endl;
    }

    m_arme->incrCompteur(m_arme->getCooldown());
}

void Hero::attaquer(sf::FloatRect ennemiBoundingBox, Ennemi &ennemi) {
    if (m_arme->checkHitbox(ennemiBoundingBox)) //vérifier qu'un ennemi se trouve dans la hitbox de l'attaque
    {
		ennemi.estTouche(m_arme->getDamage());//enlever des pv à l'ennemi
    }
}

void Hero::move(std::vector<std::vector<int> >* level,sf::Vector2u tileSize, int width) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        Sprite(UP);
        if ( Tilemap::getTileNumber(m_pos.x+50,m_pos.y-5,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+15,m_pos.y-5,level,tileSize)==1 or (m_pos.y-m_vitesse<=5)   )
        {}
        else {
            m_pos.y-=m_vitesse;
        }

    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Sprite(DOWN);
        if ( Tilemap::getTileNumber(m_pos.x+50,m_pos.y+65,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+15,m_pos.y+65,level,tileSize)==1 or (m_pos.y+m_vitesse+m_taille_sprite.hauteur>=900) )
        {}
        else {
            m_pos.y+=m_vitesse;
        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Sprite(RIGHT);
        if ( Tilemap::getTileNumber(m_pos.x+55,m_pos.y+15,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+55,m_pos.y+60,level,tileSize)== 1 or (m_pos.x+m_vitesse+m_taille_sprite.largeur>=1195) )
        {}
        else {
            m_pos.x+=m_vitesse;
        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        Sprite(LEFT);
        if ( Tilemap::getTileNumber(m_pos.x+10,m_pos.y+15,level,tileSize)==1 or Tilemap::getTileNumber(m_pos.x+10,m_pos.y+60,level,tileSize)==1 or (m_pos.x-m_vitesse<=10) )
        {}
        else {
            m_pos.x-=m_vitesse;
        }
    }
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

std::string Hero::GestionMap(std::vector<std::vector<int> >* level,sf::Vector2u tile_size) {

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
    
}