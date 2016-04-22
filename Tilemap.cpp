#include <iostream>

#include "..\include\Tilemap.h"

using namespace std;

/* --------Modalités get-------- */

int Tilemap::getTileNumber(int x, int y, std::vector<std::vector<int> >* level,sf::Vector2u tileSize) {

    return level->at(y/tileSize.y).at(x/tileSize.x);
}

/* --------Autres Modalités-------- */

bool Tilemap::load(const std::string &tileset, sf::Vector2u tileSize, std::vector<std::vector<int> > *tiles, unsigned int width,
                   unsigned int height) {

    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;

    m_tableau.setPrimitiveType(sf::Quads);
    m_tableau.resize(height*width*4);


    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {

            // on récupère le numéro de tuile courant

            int tileNumber = tiles->at(j).at(i);

            // on en déduit sa position dans la texture du tileset
      /*      int tu = tileNumber*30;
            int tv = tileNumber*30;
      */
            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_tableau[(i+j*width)*4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i*tileSize.x,j*tileSize.y);
            quad[1].position = sf::Vector2f((i+1)*tileSize.x, j*tileSize.y);
            quad[2].position = sf::Vector2f((i+1)*tileSize.x,(j+1)* tileSize.y);
            quad[3].position = sf::Vector2f(i*tileSize.x, (j+1)* tileSize.y);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tileNumber*tileSize.x, 0);
            quad[1].texCoords = sf::Vector2f(tileSize.x +tileSize.x*tileNumber, 0);
            quad[2].texCoords = sf::Vector2f(tileSize.x + tileSize.x*tileNumber,tileSize.y);
            quad[3].texCoords = sf::Vector2f(tileSize.x*tileNumber,tileSize.y);

        }

    return true;
}

void Tilemap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // on applique la transformation

    // on applique la texture du tileset
    states.texture = &m_tileset;

    // et on dessine enfin le tableau de vertex
    target.draw(m_tableau, states);
}



void Tilemap::loadLevelFromText(int *width, int *height,std::vector<std::vector<int> >* level) {

    std::string mon_fichier = "map.txt";
    std::ifstream fichier;
    fichier.open(mon_fichier.c_str());

    std::string str;

    do {
        std::getline(fichier, str);
        std::cout << str << std::endl;
    }
    while (str != "test");

    fichier >> *width >> *height;

    int myint;

    for (int j = 0; j < *height; j++)
    {
        vector<int> myline;

        for (int i = 0; i < *width; i++) {
            fichier >> myint;
            myline.push_back(myint);
        };
    level->push_back(myline);
    }

   /* for (int j = 0; j <*height ; j++)
    {
        for (int i = 0; i < *width; i++) {
            cout << level[j][i];

        };
        cout<<endl;
    }*/


}
