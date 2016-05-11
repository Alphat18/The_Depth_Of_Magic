#include "Troll.h"

/* --------Constructeurs-------- */

Troll::Troll(int posX, int posY) :  Ennemi(150, 0, 3, 10)
{
    m_pos.x = posX;
    m_pos.y = posY;
}
