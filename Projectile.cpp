#include "..\include\Projectile.h"
#include "..\include\Arme.h"

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

Projectile::~Projectile()
{

}

int Projectile::getspeed() {
    return m_speed;
}


/* --------Autres modalites-------- */

void Projectile::fly(Direction dir, int speed) {
    if (dir==DOWN)
    {
        m_pos.y = m_pos.y - speed;
    }
    if (dir==UP)
    {
        m_pos.y = m_pos.y + speed;
    }
    if (dir==LEFT)
    {
        m_pos.x = m_pos.x - speed;
    }
    if (dir==RIGHT)
    {
        m_pos.x = m_pos.x + speed;
    }

    sprite.setTextureRect(sf::Rect<int>(0,0,14,32));
    sprite.setPosition(m_pos.x,m_pos.y);
    m_boundingBox = sprite.getGlobalBounds();
}
