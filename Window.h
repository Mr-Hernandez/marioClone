#pragma once
#include "SFML/Graphics.hpp"
//#include <string>


class Window{
public:
    Window();
    Window(const sf::Vector2u& l_size, const std::string& l_name);
    ~Window();

    // Getters
    sf::RenderWindow* GetRenderWindow();
    void Draw(sf::Drawable& l_drawable);
    bool IsDone();
    sf::Vector2u GetOrigWinSize();

    // Loop
    void Update();
    void Render();

    // others



private:
    sf::RenderWindow m_window;
    sf::Vector2u m_origWinSize;
    std::string m_windowName;

};
