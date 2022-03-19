#pragma once

#include "BaseState.h"
#include "EventManager.h"
#include "SFML/Graphics.hpp"



class Test : public BaseState{
public:
    Test(StateManager* l_stateManager);
    ~Test();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void Draw();

    void Tester(EventDetails* l_details);

};
