#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Structures.h"
#include "Arme.h"

class Projectile : public Arme
{
    public:
        Projectile(std::string name, int damage, int speed);
        Projectile(std::string name, int damage, int speed, int posX, int posY, Direction dir);
        ~Projectile();

        int getspeed();

        void setdir(Direction dir);
        void fly(int speed);

    protected:
        int m_speed;
        Direction m_dir;
};

#endif // PROJECTILE_H
