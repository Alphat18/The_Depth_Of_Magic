#include "Projectile.h"
#include "Arme.h"

/* --------Constructeurs-------- */

Projectile::Projectile(std::string name, int damage, int speed) : Arme(name, damage), m_speed(speed)
{
    m_image = "sprites/fleche.png";
    m_countSprite = 0;

    m_pos.x = 250;
    m_pos.y = 250;

    // Initialisation du sprite
    TexArme.loadFromFile(m_image);
    sprite.setTexture(TexArme);
    sprite.setTextureRect(sf::Rect<int>(0,0,14,32));
    sprite.setPosition(m_pos.x,m_pos.y);

    m_boundingBox = sprite.getGlobalBounds();
}

Projectile::Projectile(std::string name, int damage, int speed, int posX, int posY, Direction dir) : Arme(name, damage), m_speed(speed), m_dir(dir)
{
    m_image = "sprites/fleche.png";
    m_countSprite = 0;

    m_pos.x = posX;
    m_pos.y = posY;

    // Initialisation du sprite
    TexArme.loadFromFile(m_image);
    sprite.setTexture(TexArme);
    sprite.setTextureRect(sf::Rect<int>(0,0,14,32));
    sprite.setPosition(m_pos.x,m_pos.y);

    m_boundingBox = sprite.getGlobalBounds();
}

Projectile::~Projectile()
{

}

int Projectile::getspeed() {
    return m_speed;
}

void Projectile::setdir(Direction dir) {
    m_dir = dir;
}

/* --------Autres modalites-------- */

void Projectile::fly(int speed) {

    if (m_dir==DOWN)
    {
        m_pos.y = m_pos.y + speed;
        sprite.setTextureRect(sf::Rect<int>(0,0,14,32));
        sprite.setPosition(m_pos.x,m_pos.y);
    }
    if (m_dir==UP)
    {
        m_pos.y = m_pos.y - speed;
        sprite.setTextureRect(sf::Rect<int>(14,0,14,32));
        sprite.setPosition(m_pos.x,m_pos.y);
    }
    if (m_dir==LEFT)
    {
        m_pos.x = m_pos.x - speed;
        sprite.setTextureRect(sf::Rect<int>(28,0,32,14));
        sprite.setPosition(m_pos.x,m_pos.y);
    }
    if (m_dir==RIGHT)
    {
        m_pos.x = m_pos.x + speed;
        sprite.setTextureRect(sf::Rect<int>(28,18,32,14));
        sprite.setPosition(m_pos.x,m_pos.y);
    }

    m_boundingBox = sprite.getGlobalBounds();
}
