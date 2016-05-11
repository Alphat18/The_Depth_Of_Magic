#include <list>

#include "Personnage.h"
#include "Arme.h"
#include "Projectile.h"
#include "Tilemap.h"

/* --------Constructeurs-------- */
Personnage::Personnage()
{
    m_status = NORMAL;
    m_compteurPerso = 0;
    m_boundingBox = m_sprite.getGlobalBounds();
}

Personnage::Personnage(int hp, int mana, int vitesse, int defense) : m_hp(hp), m_mana(mana), m_vitesse(vitesse), m_defense(defense)
{
    m_status = NORMAL;
    m_compteurPerso = 0;
    m_boundingBox = m_sprite.getGlobalBounds();
}

Personnage::~Personnage()
{
   delete m_arme;
   m_sprite.~Drawable();
   m_tex.~Texture();

}

/* --------Modalites get-------- */

std::string Personnage::getimage() {
	return m_image;
}

int Personnage::gethp() {
    return m_hp;
}

Position Personnage::getpos() {
    return m_pos;
}

sf::Sprite Personnage::getsprite() {
    return m_sprite;
}

Direction Personnage::getdir() {
    return m_dir;
}

sf::FloatRect Personnage::gethitbox() {
    return m_boundingBox;
}

Status Personnage::getstatus() {
    return m_status;
}

PosMap Personnage::getPosMap() {
    return m_pos_map;
}

void Personnage::resetStatus() {
    m_status = NORMAL;
}

sf::Sprite Personnage::getspriteArme() {
    return m_arme->getsprite();
}

Arc* Personnage::getarme() {
    return m_arme;
}

void Personnage::setPos(int x, int y){
    this->m_pos.x=x;
    this->m_pos.y=y;
}

/* --------Autres Modalites-------- */

void Personnage::estTouche(int damages) {
    m_hp -= (damages-m_defense);
    m_status = TOUCHE;
}

bool Personnage::persoIsDead() {
    return (m_hp <= 0);
}

void Personnage::gestionAttaque(Personnage &perso) {

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (m_arme->getCompteur() > m_arme->getCooldown())) {
        m_arme->zeroCompteur();
    }

    if (m_arme->getCompteur() <= 2) {
        m_status = ATTAQUE;
        m_arme->changeSprite(m_dir);

        if (perso.getstatus() == NORMAL)
            attaquer(perso);
    }
    else
        resetStatus();

    m_arme->incrCompteur(m_arme->getCooldown());
}

void Personnage::attaquer(Personnage &ennemi) {
    if (getarme()->checkHitbox(ennemi.gethitbox())) //vérifier qu'un ennemi se trouve dans la hitbox de l'attaque
    {
		ennemi.estTouche(getarme()->getDamage());//enlever des pv à l'ennemi
    }
}

void Personnage::attaquerDistance(Personnage &ennemi, std::list<Projectile *> &projectileList) {
    for (std::list<Projectile *>::iterator projItor = projectileList.begin (); projItor != projectileList.end (); ++projItor) {
        if ((*projItor)->checkHitbox(ennemi.gethitbox())) //vérifier qu'un ennemi se trouve dans la hitbox de l'attaque
        {
            ennemi.estTouche(getarme()->getDamage());//enlever des pv à l'ennemi
            //projectileList.erase(projItor);
        }
    }
}

std::list<Projectile *> Personnage::tirer(std::list<Projectile *> &projectileList, Direction dir) {
    projectileList.push_back (new Projectile("fleche", 1, 8, m_pos.x, m_pos.y, dir));
    return projectileList;
}

void Personnage::Sprite(Direction dir) {

    if (dir==DOWN)
    {
        m_compteurPerso+=60;
        m_dir = DOWN;

        m_sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,0,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    if (dir==RIGHT)
    {
        m_compteurPerso+=60;
        m_dir = RIGHT;

        m_sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,70,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    if (dir==LEFT)
    {
        m_compteurPerso+=60;
        m_dir = LEFT;

        m_sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,140,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    if (dir==UP)
    {
        m_compteurPerso+=60;
        m_dir = UP;

        m_sprite.setTextureRect(sf::Rect<int>(m_compteurPerso,210,60,70));

        if (m_compteurPerso==180)
            m_compteurPerso=0;
    }

    m_sprite.setPosition(m_pos.x,m_pos.y);
	m_boundingBox = m_sprite.getGlobalBounds();

}

bool Personnage::Walkable(Direction dir, int x, int y, std::vector<std::vector<int> >* level,  sf::Vector2u tileSize,int width) {

    switch (dir)
    {
        case UP : return not((Tilemap::getTileNumber(m_pos.x,m_pos.y,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur,m_pos.y,level,tileSize)==1));

        case DOWN: return not((Tilemap::getTileNumber(m_pos.x-5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1));

        case RIGHT: return not((Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-3,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+m_taille_sprite.largeur-3,m_pos.y,level,tileSize)==1));

        case LEFT: return not ((Tilemap::getTileNumber(m_pos.x+5,m_pos.y+m_taille_sprite.hauteur,level,tileSize)==1) or (Tilemap::getTileNumber(m_pos.x+5,m_pos.y,level,tileSize)==1));
    }
}
