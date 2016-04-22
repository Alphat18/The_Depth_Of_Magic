#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

struct Position {
    int x;
    int y;
};

enum Direction {RIGHT,LEFT,UP,DOWN};
enum Status {NORMAL, TOUCHE};

struct Taille {
    int largeur,hauteur;
};

#endif // STRUCTURES_H_INCLUDED
