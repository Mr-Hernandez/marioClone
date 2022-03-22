#include "StateIntro.h"
#include "StateManager.h"

StateIntro::StateIntro(StateManager* l_stateManager)
    : BaseState(l_stateManager){}

StateIntro::~StateIntro(){}

void StateIntro::OnCreate(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::StateIntro, "Continue", &StateIntro::Continue, this);
}

void StateIntro::OnDestroy(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::StateIntro, "Continue");
}

void StateIntro::Update(const sf::Time& l_time){

}

void StateIntro::Draw(){
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
//    window->Draw(somedrawable);
}

//callables
void StateIntro::Continue(EventDetails* l_details){
    m_stateMgr->SwitchTo(StateType::StateGame);
    m_stateMgr->Remove(StateType::StateIntro);
}

void StateIntro::Activate(){}
void StateIntro::Deactivate(){}
