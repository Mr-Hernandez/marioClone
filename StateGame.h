#pragma once

#include "BaseState.h"
#include "EventManager.h"
#include "SFML/Graphics.hpp"

#include "character.h"
#include "Map.h"

class StateGame : public BaseState{
public:
    StateGame(StateManager* l_stateManager);
    ~StateGame();

    void OnCreate();
    void OnDestroy();

    void Update(const sf::Time& l_time);
    void Draw();

    void Activate();
    void Deactivate();
private:
    character m_character;
    Map m_map;
};
