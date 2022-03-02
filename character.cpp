#include "character.h"



character::character(){
    m_charTexture.loadFromFile("Resources/characters/gary.png");
    m_charSprite.setTexture(m_charTexture);

    // character properties
    friction = 0.5;
    m_P = sf::Vector2f(400.f, 508.f);
    m_dP = sf::Vector2f(0.f, 0.f);
    m_ddP = sf::Vector2f(0.f, 0.f);
    m_charSprite.setPosition(m_P);
}

character::~character(){}

void character::Move(){
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
//        m_ddP.x = -1.f;
//    }
//    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
//        m_ddP.x = 1.f;
//    } else {
//        m_ddP.x = 0.f;
//        if(m_dP.x != 0){
//            if(m_dP.x < 0){ m_dP.x += friction;}
//            else { m_dP.x -= friction;}
//        }
//    }
//
//    m_dP.x += m_ddP.x;
//    m_P.x += m_dP.x;
//    m_charSprite.setPosition(m_P);
//    if(m_dP.x > 10.f){ m_dP.x = 10.f;}
//    else if(m_dP.x < -10.f){ m_dP.x = -10.f;}

}

void character::SetJump(EventDetails* l_details){ isJump = true;}
void character::SetMoveRight(EventDetails* l_details){ isMoveR = true;}
void character::ResetActions(){
    isJump = false;
    isMoveR = false;
    isMoveL = false;
    isMoveU = false;
    isMoveD = false;
}

void character::Update(std::vector<sf::Time>& l_timeInfo){

    // Tick
    if(l_timeInfo[2].asSeconds() >= l_timeInfo[1].asSeconds())
    {
        // Jump
        if(m_P.y == 508 && isJump){ // if grounded, then jump
            m_dP.y = -10.f;
        }

        // MoveDirection
        if(isMoveR){ m_ddP.x = 1.f;}
        else if(isMoveL){ m_ddP.x = -1.f;}
        else {
        m_ddP.x = 0.f;
            if(m_dP.x != 0){
                if(m_dP.x < 0){ m_dP.x += friction;}
                else { m_dP.x -= friction;}
            }
        }

        // speed physics
        m_dP.x += m_ddP.x;
        m_P.x += m_dP.x;
//        m_charSprite.setPosition(m_P);
        m_ddP.y = 1.f; // gravity, always, could import from map eventually
        m_dP.y += m_ddP.y;
        m_P.y += m_dP.y;

        // x speed limit
        if(m_dP.x > 10.f){ m_dP.x = 10.f;}
        else if(m_dP.x < -10.f){ m_dP.x = -10.f;}

        // if off of platform, should fall
        if(m_P.x > m_platInfo.left &&
            m_P.x < m_platInfo.left + m_platInfo.width * 2){
            if(m_P.y > 508){m_P.y = 508; m_dP.y = 0.f;} // land on platform
        }

        // Set Position of character
        m_charSprite.setPosition(m_P);
    }

    ResetActions();

}

void character::Render(sf::RenderWindow& l_window){
    l_window.draw(m_charSprite);
}

void character::SetPlatPosition(sf::FloatRect l_platRect){
    m_platInfo = l_platRect;
}
