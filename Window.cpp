#include "Window.h"
#include <iostream> // for testing

// Window::Window should initialize a RenderWindow member.
Window::Window() : m_window(sf::VideoMode(1920,1080), "marioClone")

{

    std::cout << "window class constructor reached" << std::endl;
    m_origWinSize = sf::Vector2u(1920, 1080);
//    isDone = false;

}

// Just messing around
Window::Window(const sf::Vector2u& l_size, const std::string& l_name)
    : m_origWinSize(l_size), m_windowName(l_name), isDone(false)
{
    std::cout << "second constructor" << std::endl;
     std::cout << "isDoneInit is:" << isDone << std::endl;
    m_window.create(sf::VideoMode(l_size.x, l_size.y), l_name);
}

Window::~Window(){}

// Getters and Setters -----------------------------------------

// GetWindow is used to get a pointer to the window. I send the
// address rather than copying the whole RenderWindow object.
sf::RenderWindow* Window::GetRenderWindow(){ return &m_window;}

// IsDone returns whether window is open or closed
bool Window::IsDone(){ return isDone;}

sf::Vector2u Window::GetOrigWinSize(){ return m_origWinSize;}

EventManager* Window::GetEventManager(){ return &m_eventManager;}


// Loop ----------------------------------------------------------------

// Draw should be called from Game cpp and can draw stuff one level down
// from Game class.
void Window::Draw(sf::Drawable& l_drawable){ m_window.draw(l_drawable);}

void Window::Update(){
//    sf::Event event; // probably better make event here
    while(m_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            isDone = true;
        }
        m_eventManager.HandleEvent(event);
    }
    m_eventManager.Update();

//    m_window.pollEvent(event);
//    if(event.type == sf::Event::Closed){
//        isDone = true;
//        std::cout << "closing" << std::endl;
//    }
////    std::cout << event.type << std::endl;
////    m_eventManager.SetEvent(&event);
//    m_eventManager.HandleEvent(event);
//    m_eventManager.Update();
}

void Window::Render(){
//    m_window.clear(sf::Color::Blue);
    m_window.display();
    // I can set up a begin draw and enddraw function
    // or something maybe.
}

void Window::BeginDraw(){
    m_window.clear(sf::Color::Blue);
}

// others


