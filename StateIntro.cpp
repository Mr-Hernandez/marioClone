#include "StateIntro.h"
#include "StateManager.h"

StateIntro::StateIntro(StateManager* l_stateManager)
    : BaseState(l_stateManager){}

StateIntro::~StateIntro(){}

void StateIntro::OnCreate(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::StateIntro, "Continue", &StateIntro::Continue, this);

    m_texture.loadFromFile("Resources/otherImages/introimage.jpg");
    m_sprite.setTexture(m_texture);
    float windX = static_cast<float>(m_stateMgr->GetContext()->m_wind->GetOrigWinSize().x);
    float windY = static_cast<float>(m_stateMgr->GetContext()->m_wind->GetOrigWinSize().y);
    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2,
                       m_sprite.getLocalBounds().height / 2);
    m_sprite.setPosition(windX / 2, windY / 2);
}

void StateIntro::OnDestroy(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::StateIntro, "Continue");
}

void StateIntro::Update(const sf::Time& l_time){

}

void StateIntro::Draw(){
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    window->draw(m_sprite);
}

//callables
void StateIntro::Continue(EventDetails* l_details){
    m_stateMgr->SwitchTo(StateType::StateGame);
    m_stateMgr->Remove(StateType::StateIntro);
}

void StateIntro::Activate(){}
void StateIntro::Deactivate(){}
