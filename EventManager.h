#pragma once
#include <functional>
#include "SFML/Graphics.hpp"

struct EventDetails{
int tmp = 1;
};

class EventManager{
public:
    EventManager();
    template<class T>
    void AddCallback(void(T::*l_func)(EventDetails*), T* target){
        auto temp = std::bind(l_func, target, std::placeholders::_1);
        callback = temp;
    }

    void IssueCallback();
    void HandleEvent();
private:
    std::function<void(EventDetails*)> callback;
    EventDetails m_details;
};
