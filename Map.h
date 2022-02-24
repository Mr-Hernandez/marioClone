#pragma once
#include "SFML/Graphics.hpp"



class Map{
public:
    Map();
    ~Map();

    void Update();
    void Render(sf::RenderWindow& l_window);

private:
    // initialized by creator
    sf::Vector2u m_origWinSize;

    // Drawables
    sf::Texture m_texture;
    sf::Texture m_bg;
    sf::Sprite m_bgSprite;
    sf::Sprite m_textureSprite;

};
