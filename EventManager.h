#pragma once
#include <functional>
#include <unordered_map>


struct EventDetails{
    EventDetails(const std::string& l_bindName)
        : m_name(l_bindName){}
    std::string m_name;
};

using Callbacks = std::unordered_map<std::string,
    std::function<void(EventDetails*)>>;

class EventManager{
public:

//    EventManager();
//    ~EventManager();

    //Template
    template<class T>
    bool AddCallback(const std::string& l_name,
        void(T::*l_func)(EventDetails*),T* l_instance)
    {
        auto temp = std::bind(l_func, l_instance,
            std::placeholders::_1);
        return m_callbacks.emplace(l_name, temp).second;
    }

    void HandleEvent();
private:
    Callbacks m_callbacks;
};

