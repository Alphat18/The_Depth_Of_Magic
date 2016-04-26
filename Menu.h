//
// Created by robin on 20/04/16.
//

#ifndef THE_DEPTHS_OF_MAGIC_MENU_H
#define THE_DEPTHS_OF_MAGIC_MENU_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum Etat {PLAY,LEAVE,OPTION,NONE};

class Menu  {
public :
    Menu();
    Etat GestionMenu(sf::Window &window);
    void setEtat(Etat state);
    Etat getEtat();

    sf::Sprite getSprite();
    void Sprite (sf::Window &window);
private :

    sf::Texture m_texture;
    Etat m_etat;
    sf::Sprite m_sprite;
    sf::Sound bruit_bouton;
    sf::SoundBuffer buffer_bouton;



};


#endif //THE_DEPTHS_OF_MAGIC_MENU_H
