#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Structures.h"
#include "Arme.h"

class Projectile : public Arme
{
    public:
        Projectile(std::string name, int damage, int speed);
        ~Projectile();

        int getspeed();

        void fly(Direction dir, int speed);

    protected:
        int m_speed;
};

#endif // PROJECTILE_H
