#pragma once
// The Event Manager is meant to achieve the following goals
// 1. Ability to couple any mix of keys, buttons, or events with the
//    desired functionality identified by a string.
// 2. Binding said functionalities to methods that get called if all
//    the conditions for the bindings are met.
// 3. A way through which the event manager cna deal with actual
//    SFML events being polled
// 4. Loading the bindings from a configuration file

#include <functional> // Defines std::function and std::bind
#include <unordered_map> // Had to add this to use std::unordered_map
#include <fstream> // For "ifstream"
#include <iostream> // for std::cout
#include <sstream> // for std::stringstream
#include "SFML/Graphics.hpp"

enum class EventType{
    KeyDown = sf::Event::KeyPressed,
    KeyUp = sf::Event::KeyReleased,
    MButtonDown = sf::Event::MouseButtonPressed,
    MButtonUp = sf::Event::MouseButtonReleased,
    MouseWheel = sf::Event::MouseWheelMoved,
    WindowResized = sf::Event::Resized,
    GainedFocus = sf::Event::GainedFocus,
    LostFocus = sf::Event::LostFocus,
    MouseEntered = sf::Event::MouseEntered,
    MouseLeft = sf::Event::MouseLeft,
    Closed = sf::Event::Closed,
    TextEntered = sf::Event::TextEntered,
    Keyboard = sf::Event::Count + 1, Mouse, Joystick
};

struct EventInfo{
    EventInfo(){ m_code = 0;}
    EventInfo(int l_event){ m_code = l_event;}
    union{
        int m_code;
    };
};

using Events = std::vector<std::pair<EventType, EventInfo>>;

struct EventDetails{
    EventDetails(const std::string& l_bindName)
        : m_name(l_bindName)
    {
        Clear();
    }
    std::string m_name;

    sf::Vector2i m_size;
    sf::Uint32 m_textEntered;
    sf::Vector2i m_mouse;
    int m_mouseWheelDelta;
    int m_keyCode; // single key code

    void Clear(){
        m_size = sf::Vector2i(0,0);
        m_textEntered = 0;
        m_mouse = sf::Vector2i(0, 0);
        m_mouseWheelDelta = 0;
        m_keyCode = -1;
    }
};

struct Binding{
    Binding(const std::string& l_name)
        : m_name(l_name), m_details(l_name), c(0){}
    void BindEvent(EventType l_type,
        EventInfo l_info = EventInfo())
    {
        m_events.emplace_back(l_type, l_info);
    }

    Events m_events;
    std::string m_name;
    int c; // Count of events that are "happening"

    EventDetails m_details;
};

using Bindings = std::unordered_map<std::string, Binding*>;
using Callbacks = std::unordered_map<std::string,
    std::function<void(EventDetails*)>>;



class EventManager{
public:
    EventManager();
    ~EventManager();

    bool AddBinding(Binding *l_binding);
    bool RemoveBinding(std::string l_name);
    void SetFocus(const bool& l_focus);

    // Needs to be defined in the header
    template<class T>
    bool AddCallback(const std::string& l_name,
        void(T::*l_func)(EventDetails*), T* l_instance)
    {
        std::cout << "Adding Callback: " << l_name << std::endl;
        auto temp = std::bind(l_func, l_instance, // The "_1" is the number one.
            std::placeholders::_1);
        return m_callbacks.emplace(l_name, temp).second;
    }

    void RemoveCallback(const std::string& l_name){
        m_callbacks.erase(l_name);
    }

    void HandleEvent(sf::Event& l_event);
    void Update();

    sf::Vector2i GetMousePos(sf::RenderWindow* l_wind = nullptr){
        return (l_wind ? sf::Mouse::getPosition(*l_wind)
                : sf::Mouse::getPosition());
    }

private:
    void LoadBindings();

    Bindings m_bindings;
    Callbacks m_callbacks;
    bool m_hasFocus;

};


