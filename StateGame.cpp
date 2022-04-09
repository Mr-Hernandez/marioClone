#include "StateGame.h"
#include "StateManager.h"

StateGame::StateGame(StateManager* l_stateManager)
    : BaseState(l_stateManager){}

StateGame::~StateGame(){}

void StateGame::OnCreate(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::StateGame, "SetJump", &character::SetJump, &m_character);
//    evMgr->AddCallback(StateType::Test, "Tester", &Test::Tester, this);
}

void StateGame::OnDestroy(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::StateGame, "SetJump");
//    evMgr->RemoveCallback(StateType::Test,"Tester");
}

void StateGame::Update(const sf::Time& l_time){
    m_character.SetPlatPosition(m_map.GetPlatSize());
    m_character.Update(l_time);
}

void StateGame::Draw(){
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
//    window->Draw(someDrawable);
    m_map.Render(*window);
    m_character.Render(*window);
}

// callables

void StateGame::Activate(){}
void StateGame::Deactivate(){}

