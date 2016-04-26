//
// Created by robin on 20/04/16.
//

#include "Menu.h"


Menu::Menu() {
    m_texture.loadFromFile("menu.png");

    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::Rect<int>(0,0,1200,900));

    m_etat=NONE;
    buffer_bouton.loadFromFile("bruit_bouton.ogg");
    bruit_bouton.setBuffer(buffer_bouton);

}



Etat Menu::GestionMenu(sf::Window &window) {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i localPos = sf::Mouse::getPosition(window);
        if ( (localPos.x>456 and localPos.x<712 ) and (localPos.y>250 and localPos.y<364) )
        {
            bruit_bouton.play();
            m_etat=PLAY;
        }

        if ( (localPos.x>180 and localPos.x<1075) and (localPos.y>590 and localPos.y<716) )
        {
            m_etat=LEAVE;
            bruit_bouton.play();
        }
    }


    return m_etat;
}

void Menu::setEtat(Etat state) {
    m_etat=state;
}

sf::Sprite Menu::getSprite() {
    return m_sprite;
}

void Menu::Sprite(sf::Window &window ) {

    sf::Vector2i localPos = sf::Mouse::getPosition(window);

    m_sprite.setTextureRect(sf::Rect<int>(0,0,1200,900));

    if ( (localPos.x>456 and localPos.x<712 ) and (localPos.y>250 and localPos.y<364) )
        m_sprite.setTextureRect(sf::Rect<int>(1200,0,1200,900));



    if ( (localPos.x>180 and localPos.x<1075) and (localPos.y>590 and localPos.y<716) )
        m_sprite.setTextureRect(sf::Rect<int>(3600,0,1200,900));

}

Etat Menu::getEtat() {
    return m_etat;
}