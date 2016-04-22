#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <vector>
#include <list>

#include "..\include\Personnage.h"
#include "..\include\Tilemap.h"
#include "..\include\Troll.h"
#include "..\include\Ennemi.h"
#include "..\include\Hero.h"

using namespace std;

int main() {

    // Création de la fenêtre graphique
    sf::RenderWindow window(sf::VideoMode(1200,900),"The dephts of Magic",sf::Style::Default);
    sf::Clock clock;
    int height_level=0;
    int width_level=0;

    int phase = 0;

    // Chargement de la map
    sf::Vector2u tile_size;
    vector<vector<int> > level;
    Tilemap::loadLevelFromText(&width_level,&height_level,&level);
    tile_size.y=60;
    tile_size.x=60;

    Tilemap map;
    map.load("sprites/tileset.png",tile_size,&level,width_level,height_level);

    // Création du premier node
    std::list<Ennemi *> ennemiList;
    std::list<Ennemi *>::iterator itor;

    std::list<Projectile *> projectileList;
    std::list<Projectile *>::iterator projItor;

    // Création des entités
    Hero perso(100, 150, 5, 3);
    Troll *troll1 = new Troll (100, 100);
    Troll *troll2 = new Troll (200, 200);
    Troll *troll3 = new Troll (300, 300);
    Troll *troll4 = new Troll (400, 400);
    Troll *troll5 = new Troll (500, 500);

    // On place les entités dans la liste
    ennemiList.push_back (troll1);
    ennemiList.push_back (troll2);
    ennemiList.push_back (troll3);
    ennemiList.push_back (troll4);
    ennemiList.push_back (troll5);

    // Boucle des évènements
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        if (phase == 0)
        {
            /* --------Menu-------- */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                phase = 1;

            /* --------Affichage à l'écran-------- */
            window.clear(sf::Color::Black);
            window.draw(map,sf::RenderStates::Default);

            window.display();
        }
        else if (phase == 1)
        {
            /* --------Actions Principales-------- */
            perso.move(&level,tile_size,20);

            perso.getarme()->followHero(perso.getpos(), perso.getdir());

            for (projItor = projectileList.begin (); projItor != projectileList.end (); ++projItor) {
                (*projItor)->fly(perso.getdir(), (*projItor)->getspeed());
            }

            perso.gestionAttaqueDistance(ennemiList, projectileList);

            for (itor = ennemiList.begin(); itor != ennemiList.end(); ++itor)
            {
                (*itor)->IAEnnemiBase(perso.getpos(),&level,tile_size,20);

                if ((*itor)->persoIsDead())
                {
                    ennemiList.erase(itor);
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                phase = 0;

            /* --------Affichage à l'écran-------- */
            window.clear(sf::Color::Black);
            window.draw(map,sf::RenderStates::Default);

            window.draw(perso.getsprite());
            window.draw(perso.getspriteArme());
            // On dessine la liste d'entités
            for (itor = ennemiList.begin (); itor != ennemiList.end (); ++itor) {
                window.draw((*itor)->getsprite());
            }
            for (projItor = projectileList.begin (); projItor != projectileList.end (); ++projItor) {
                window.draw((*projItor)->getsprite());
            }

            window.display();
        }

        elapsed=clock.getElapsedTime();

        if (clock.getElapsedTime().asMilliseconds()<70)
                usleep(70000-elapsed.asMicroseconds());
    }

    return 0;
}
