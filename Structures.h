#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

struct Position {
    int x;
    int y;
};

enum Direction {RIGHT,LEFT,UP,DOWN};
enum Status {NORMAL, TOUCHE, ATTAQUE};

struct Taille {
    int largeur,hauteur;
};

struct PosMap {
    int i,j;
};

struct noeud {
    int x,y,cout,heuristique;
};


#endif // STRUCTURES_H_INCLUDED
