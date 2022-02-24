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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        m_ddP.x = -1.f;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        m_ddP.x = 1.f;
    } else {
        m_ddP.x = 0.f;
        if(m_dP.x != 0){
            if(m_dP.x < 0){ m_dP.x += friction;}
            else { m_dP.x -= friction;}
        }
    }

    m_dP.x += m_ddP.x;
    m_P.x += m_dP.x;
    m_charSprite.setPosition(m_P);
    if(m_dP.x > 10.f){ m_dP.x = 10.f;}
    else if(m_dP.x < -10.f){ m_dP.x = -10.f;}




}

void character::Jump(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        // if I make a list of m_platInfo of all platforms
        // Then I could check if char is grounded on any platform
        if(m_P.y == 508){ // if grounded, then jump
            m_dP.y = -10.f;
        }

    }
    m_ddP.y = 1.f; // gravity, always, could import from map eventually
    m_dP.y += m_ddP.y;
    m_P.y += m_dP.y;

    // if off of platform, should fall
    if(m_P.x > m_platInfo.left &&
       m_P.x < m_platInfo.left + m_platInfo.width * 2){
            if(m_P.y > 508){m_P.y = 508; m_dP.y = 0.f;} // land on platform
       }

}

void character::Update(std::vector<sf::Time>& l_timeInfo){

    // Tick
    if(l_timeInfo[2].asSeconds() >= l_timeInfo[1].asSeconds())
    {
//        std::cout << "moving" << std::endl;

        Move();
        Jump();
    }


}

void character::Render(sf::RenderWindow& l_window){
    l_window.draw(m_charSprite);
}

void character::SetPlatPosition(sf::FloatRect l_platRect){
    m_platInfo = l_platRect;
}
//void character::SetPlatPosition(const sf::Vector2f& l_size,
//    const std::vector<sf::Vector2f>& l_positions)
//    {
//        m_platSize = l_size;
//        m_platPositions = l_positions;
//    }
