#include "Map.h"


Map::Map()
{

    m_bg.loadFromFile("Resources/TilesetsRelease/JnRLayer01.png");
    m_texture.loadFromFile("Resources/TilesetsRelease/JnRTiles.png");
    m_bgSprite.setTexture(m_bg);
    m_bgSprite.scale(4.8f, 4.5f);

    m_textureSprite.setTexture(m_texture);
    m_textureSprite.setPosition(384.f, 540.f);


}

Map::~Map(){}


void Map::Render(sf::RenderWindow& l_window){
//    sf::View view(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
//    l_window.setView(view);
    l_window.draw(m_bgSprite);
    m_textureSprite.setPosition(384.f, 540.f);
    l_window.draw(m_textureSprite);
    m_textureSprite.setPosition(960.f, 540.f);
    l_window.draw(m_textureSprite);

}
