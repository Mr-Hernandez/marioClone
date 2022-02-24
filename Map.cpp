#include "Map.h"


Map::Map()
{
    // background image
    m_bg.loadFromFile("Resources/TilesetsRelease/JnRLayer01.png");
    m_bgSprite.setTexture(m_bg);
    m_bgSprite.scale(4.8f, 4.5f);

    // platform image
    m_texture.loadFromFile("Resources/TilesetsRelease/JnRTiles.png");
    m_textureSprite.setTexture(m_texture);
    m_textureOrigCoord = sf::FloatRect(384.f, 540.f,
        m_textureSprite.getGlobalBounds().width,
        m_textureSprite.getGlobalBounds().height);
    m_textureSprite.setPosition(m_textureOrigCoord.left,
                                m_textureOrigCoord.top);


}

Map::~Map(){}

sf::FloatRect Map::GetPlatSize(){ return m_textureOrigCoord;}


void Map::Render(sf::RenderWindow& l_window){
//    sf::View view(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
//    l_window.setView(view);

    l_window.draw(m_bgSprite);
    for (int i = 0; i < 2; i++){
        m_textureSprite.setPosition(m_textureOrigCoord.left +
            m_textureOrigCoord.width * i,
            m_textureOrigCoord.top);
        l_window.draw(m_textureSprite);
    }
//    m_textureSprite.setPosition(384.f, 540.f);
//    l_window.draw(m_textureSprite);
//    m_textureSprite.setPosition(384.f, 540.f);
//    l_window.draw(m_textureSprite);

}
