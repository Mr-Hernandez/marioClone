#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

struct TimeInfo;

class character{
public:
    character();
    ~character();

    void Update(std::vector<sf::Time>& l_timeInfo);
    void Render(sf::RenderWindow& l_window);

private:
    sf::Texture m_charTexture;
    sf::Sprite m_charSprite;

    // character actions
    void Move();
    void Jump();

    // character properties
    sf::Vector2f m_P;
    sf::Vector2f m_dP;
    sf::Vector2f m_ddP;
    float friction;

};
