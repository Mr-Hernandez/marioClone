#pragma once

#include "BaseState.h"
#include "EventManager.h"
#include "SFML/Graphics.hpp"

class StateIntro : public BaseState{
public:
    StateIntro(StateManager* l_stateManager);
    ~StateIntro();

    void OnCreate();
    void OnDestroy();

    void Update(const sf::Time& l_time);
    void Draw();

    void Activate();
    void Deactivate();

    void Continue(EventDetails* l_details);
private:

};
