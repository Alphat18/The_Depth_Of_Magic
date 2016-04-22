#ifndef ARC_H
#define ARC_H

#include <list>

#include "Arme.h"
#include "Projectile.h"

class Arc : public Arme
{
    public:
        Arc(std::string name, int damage, int cooldown);
        virtual ~Arc();

    protected:
};

#endif // ARC_H
