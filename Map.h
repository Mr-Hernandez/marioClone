#pragma once
#include "SFML/Graphics.hpp"



class Map{
public:
    Map();
    ~Map();

    void Update();
    void Render(sf::RenderWindow& l_window);

    //Getters Setters
    sf::FloatRect GetPlatSize();

private:
    // initialized by creator
    sf::Vector2u m_origWinSize;

    // Drawables
    sf::Texture m_texture;
    sf::Sprite m_textureSprite;
    sf::FloatRect m_textureOrigCoord;
    sf::Texture m_bg;
    sf::Sprite m_bgSprite;



};
