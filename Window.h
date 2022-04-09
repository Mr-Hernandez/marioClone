#pragma once
#include "SFML/Graphics.hpp"
#include "EventManager.h"
//#include <string>


class Window{
public:
    Window();
    Window(const sf::Vector2u& l_size, const std::string& l_name);
    ~Window();

    // Getters
    sf::RenderWindow* GetRenderWindow();
    EventManager* GetEventManager();
    bool IsDone();
    sf::Vector2u GetOrigWinSize();
    sf::FloatRect GetViewSpace();

    // Loop
    void Update();
    void Render();

    // others
    void Draw(sf::Drawable& l_drawable);
    void BeginDraw();


private:
    sf::RenderWindow m_window;
    sf::Vector2u m_origWinSize;
    std::string m_windowName;
    EventManager m_eventManager;
    bool isDone;
    sf::Event event;

};
