#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <vector>
#include <list>
#include <SFML/Audio.hpp>

#include "Personnage.h"
#include "Tilemap.h"
#include "Troll.h"
#include "Ennemi.h"
#include "Hero.h"
#include "Menu.h"

using namespace std;


std::list<Ennemi *> creerTroll(std::list<Ennemi *> &ennemiList);

int main() {


    // Création de la fenêtre graphique
    sf::RenderWindow window(sf::VideoMode(1200,900),"The dephts of Magic",sf::Style::Default);
    sf::Clock clock;
    int height_level=0;
    int width_level=0;

    // Chargement de la map
    sf::Vector2u tile_size;
    bool mybool=true;
    int compteur=0;
    vector<vector<int> > level;

    string str;
    Menu menu;

    /* --------- Intialisation Musique ------------ */
    sf::Music music_menu;
    sf::Music music_jeu;

    music_jeu.openFromFile("sounds/FreeSwitzerland.ogg");
    music_menu.openFromFile("sounds/music_menu.ogg");

    // Création du premier node
    std::list<Ennemi *> ennemiList;
    std::list<Ennemi *>::iterator itor;

    std::list<Projectile *> projectileList;
    std::list<Projectile *>::iterator projItor;

    // Création des entités
    Hero perso(100, 150, 5, 3);
    ennemiList = creerTroll(ennemiList);

    /* --------- Intialisation Map ------------ */
    tile_size.y=60;
    tile_size.x=60;

    Tilemap Case_map;
    Case_map.loadLevelFromText(&width_level,&height_level,&level,"test1",perso.getPosMap());
    Case_map.load("sprites/tileset.png",tile_size,&level,width_level,height_level);

    // Boucle des évènements
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        if (menu.getEtat()==NONE) {

            if (menu.GestionMenu(window)==1)
            {
                window.close();
            }
            else
            {
                /* --------Gestion de la musique-------- */
                if (music_menu.getStatus()==music_menu.Stopped)
                    music_menu.play();

                /* --------Actions Principales-------- */
                menu.Sprite(window);

                window.clear(sf::Color::Black);
                window.draw(menu.getSprite());
                window.display();

            }

        }
        else if (menu.getEtat()==PLAY)
        {
            sf::Time elapsed = clock.restart();

            /* --------Gestion de la musique-------- */
            if(music_menu.getStatus()==music_jeu.Playing)
                music_menu.stop();
            if(music_jeu.getStatus()==music_jeu.Stopped)
                music_jeu.play();

            /* --------Actions Principales-------- */
            perso.move(&level,tile_size,20);

            perso.getarme()->followHero(perso.getpos(), perso.getdir());

            for (projItor = projectileList.begin (); projItor != projectileList.end (); ++projItor) {
                (*projItor)->fly((*projItor)->getspeed());
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                /*if(music_jeu.getStatus()==music_jeu.Playing)
                    music_jeu.stop();*/
                menu.setEtat(NONE);
            }

            perso.gestionAttaqueDistance(ennemiList, projectileList);
            //perso.gestionAttaque(ennemiList);

            for (itor = ennemiList.begin(); itor != ennemiList.end(); ++itor) {
                (*itor)->IAEnnemiBase(perso.getpos(),&level,tile_size,20);

                if ((*itor)->persoIsDead())
                {
                    (*itor)->~Ennemi();
                    ennemiList.erase(itor);
                }
            }

			/* --------Gestion Deplacement Map-------- */
            if (perso.changementDeMap(&level,tile_size)!=0 and mybool)
            {
				mybool=false;
                //str = perso.GestionMap(&level,tile_size);
                Case_map.loadLevelFromText(&width_level,&height_level,&level,str,perso.getPosMap());
                Case_map.load("tileset.png",tile_size,&level,width_level,height_level);
			}
            compteur++;
            if (compteur>20 and not(mybool))
            {
                mybool=true;
                compteur=0;
            }

            /* --------Affichage à l'écran-------- */
            window.clear(sf::Color::Black);
            window.draw(Case_map,sf::RenderStates::Default);
            window.draw(perso.getsprite());
            window.draw(perso.getspriteArme());

            // On dessine la liste d'entités
            for (itor = ennemiList.begin (); itor != ennemiList.end (); ++itor) {
                window.draw((*itor)->getsprite());
            }
            for (projItor = projectileList.begin(); projItor != projectileList.end(); ++projItor) {
                window.draw((*projItor)->getsprite());
            }
            window.display();


            /* --------Boucle temporelle-------- */
            elapsed=clock.getElapsedTime();
            if (clock.getElapsedTime().asMilliseconds()<70)
                usleep(70000-elapsed.asMilliseconds());
        }
    }
    return 0;
}

std::list<Ennemi *> creerTroll(std::list<Ennemi *> &ennemiList) {
    ennemiList.push_back(new Troll (100, 100));
    return ennemiList;
}
