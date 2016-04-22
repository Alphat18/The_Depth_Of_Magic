#include <list>

#include "..\include\Personnage.h"
#include "..\include\Arme.h"
#include "..\include\Tilemap.h"

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

void Personnage::resetStatus() {
    m_status = NORMAL;
}

sf::Sprite Personnage::getspriteArme() {
    return m_arme->getsprite();
}

Arc* Personnage::getarme() {
    return m_arme;
}

/* --------Autres Modalit�s-------- */

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

        perso.resetStatus();
    }

    if ((m_arme->getCompteur() == 0) || (m_arme->getCompteur() == 1) || (m_arme->getCompteur() == 2)) {
        m_arme->changeSprite(m_dir);

        if (perso.getstatus() == NORMAL)
            attaquer(perso);
            std::cout << perso.gethp() << std::endl;
            std::cout << perso.getstatus() << std::endl;
        }

    m_arme->incrCompteur(m_arme->getCooldown());
}

void Personnage::attaquer(Personnage &ennemi) {
    if (getarme()->checkHitbox(ennemi.gethitbox())) //vérifier qu'un ennemi se trouve dans la hitbox de l'attaque
    {
		ennemi.estTouche(getarme()->getDamage());//enlever des pv à l'ennemi
    }
}

std::list<Projectile *> Personnage::tirer(std::list<Projectile *> &projectileList) {
    projectileList.push_back (new Projectile("fleche", 10, 5));
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
