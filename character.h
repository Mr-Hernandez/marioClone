#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include "EventManager.h"

struct TimeInfo;

class character{
public:
    character();
    ~character();

//    void Update(std::vector<sf::Time>& l_timeInfo);
    void Update(const sf::Time& l_time);
    void Render(sf::RenderWindow& l_window);

    //Getter Setters
    void SetPlatPosition(sf::FloatRect l_platRect);

    // character actions
    void SetJump(EventDetails* l_details);
    void SetMove();
    void ResetActions();


private:
    sf::Texture m_charTexture;
    sf::Sprite m_charSprite;

    // character actions
    void Move();

    // character properties
    sf::Vector2f m_P;
    sf::Vector2f m_dP;
    sf::Vector2f m_ddP;
    float friction;

    // imported map properties
    sf::FloatRect m_platInfo;
    sf::Vector2f m_platSize;
    std::vector<sf::Vector2f> m_platPositions;

    // bools
    bool isJump = false;
    bool isMoveR;
    bool isMoveL;
    bool isMoveU;
    bool isMoveD;

};
