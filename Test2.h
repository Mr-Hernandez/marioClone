#pragma once

#include "BaseState.h"
#include "EventManager.h"
#include "SFML/Graphics.hpp"

class Test2 : public BaseState{
public:
    Test2(StateManager* l_stateManager);
    ~Test2();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void Draw();

    void Continue(EventDetails* l_details);
    void Tester(EventDetails* l_details);
private:

};
