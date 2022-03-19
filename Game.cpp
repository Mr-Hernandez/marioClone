#include "Game.h"



Game::Game() : m_window(sf::Vector2u(1920,1080), "MariaClon"),
               m_stateManager(&m_context)
{
//    // I got the original size and store it, access like so
//    std::cout << m_window.GetOrigWinSize().x <<
//    " by " << m_window.GetOrigWinSize().y << std::endl;
    // Setting callbacks
//    m_window.GetEventManager()->AddCallback(StateType::Test, "Tester", &Game::Tester, this);
//    m_window.GetEventManager()->AddCallback(StateType::Test, "SetJump", &character::SetJump, &m_character); // this works
    // initializing time info
    m_timeInfo.push_back(sf::seconds(0.f));      // elapsed
    m_timeInfo.push_back(sf::seconds(1.f/60.f)); // frametime 1/60 prob
    m_timeInfo.push_back(sf::seconds(0.f));      // tick (sum of elapsed till > frametime)
//    std::cout << m_timeInfo[0].asSeconds() << std::endl;
//    std::cout << m_timeInfo[1].asSeconds() << std::endl;
//    std::cout << m_timeInfo[2].asSeconds() << std::endl;

    m_context.m_wind = &m_window;
    m_context.m_eventManager = m_window.GetEventManager();
    m_stateManager.SwitchTo(StateType::Test);
//    m_context.m_eventManager->AddCallback(StateType::Test, "Tester", &Game::Tester, this);
}

Game::~Game(){}


void Game::Update(){
    m_window.Update();
    m_stateManager.Update(m_timeInfo[0]);
//    m_character.SetPlatPosition(m_map.GetPlatSize());
//    m_character.Update(m_timeInfo);
}

void Game::Render(){
//    m_map.Render(*m_window.GetRenderWindow());
//    m_character.Render(*m_window.GetRenderWindow());
    m_window.BeginDraw();
    m_stateManager.Draw();
    m_window.Render();
}

void Game::LateUpdate(){
    m_stateManager.ProcessRequests();
    RestartClock();
}

void Game::Tester(EventDetails* l_details){
    std::cout << "Tester Access----------------------------" << std::endl;
}

// Getter Setters

Window* Game::GetWindow(){ return &m_window;}

void Game::RestartClock(){
    if(m_timeInfo[2] >= m_timeInfo[1]){ m_timeInfo[2] = sf::seconds(0);}
    m_timeInfo[0] = m_clock.restart(); // elapsed time
    m_timeInfo[2] += m_timeInfo[0]; // sum of elapsed time
//    std::cout << "elapsed: " << m_timeInfo[0].asSeconds() << std::endl;
//    std::cout << m_timeInfo[1].asSeconds() << std::endl;
//    std::cout << "tick:   " << m_timeInfo[2].asSeconds() << std::endl;

}

