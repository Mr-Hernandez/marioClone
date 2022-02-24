#include "Window.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Map.h"
#include "character.h"


class Game{
public:
    Game(); //Will initialize a window instance and other probably
    ~Game();

    // Getters and Setters
    Window* GetWindow();

    // Loop
    void Update();
    void Render();

    // Timing
    void RestartClock();


private:
    Window m_window;
    Map m_map;
    character m_character;


    // Timing
    sf::Clock m_clock;
    std::vector<sf::Time> m_timeInfo; //elapsed, frametime, tick

//    sf::Time m_elapsed;
//    float frametime = 1.f / 60.f;


};
