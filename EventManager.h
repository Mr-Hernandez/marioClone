#pragma once
#include <functional>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <sstream> // necessary for stringstream
#include <string> // for stoi

struct EventDetails{
int m_code = -1;
sf::Event s_event;
};

class EventManager{
public:
    EventManager();
    template<class T>
    void AddCallback(void(T::*l_func)(EventDetails*), T* target){
        auto temp = std::bind(l_func, target, std::placeholders::_1);
        callback = temp;
    }

    void LoadBindings();
    void IssueCallback();
    void HandleEvent(sf::Event l_event);

    // getters and setters
    void SetEvent(sf::Event* l_event);
private:
    std::function<void(EventDetails*)> callback;
    EventDetails m_details;
};
