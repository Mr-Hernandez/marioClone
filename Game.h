#include "Window.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Map.h"
#include "character.h"
#include "EventManager.h"
#include "StateManager.h"
#include "SharedContext.h"



class Game{
public:
    Game(); //Will initialize a window instance and other probably
    ~Game();

    // Getters and Setters
    Window* GetWindow();

    // Loop
    void Update();
    void Render();
    void LateUpdate();

    // Timing
    void RestartClock();

    // Others
    void Tester(EventDetails* l_details);


private:
    Window m_window;
    Map m_map;
    character m_character;
    StateManager m_stateManager;
    SharedContext m_context;


    // Timing
    sf::Clock m_clock;
    std::vector<sf::Time> m_timeInfo; //elapsed, frametime, tick

//    sf::Time m_elapsed;
//    float frametime = 1.f / 60.f;


};
