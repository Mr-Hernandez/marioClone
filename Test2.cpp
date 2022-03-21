#include "Test2.h"
#include "StateManager.h"

Test2::Test2(StateManager* l_stateManager)
    : BaseState(l_stateManager){}

Test2::~Test2(){}

void Test2::OnCreate(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Test2, "Continue", &Test2::Continue, this);
    evMgr->AddCallback(StateType::Test2, "Tester", &Test2::Tester, this);
    std::cout << "Test2::OnCreate Reached" << std::endl;
}

void Test2::OnDestroy(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Test2, "Continue");
    evMgr->RemoveCallback(StateType::Test2, "Tester");
}

void Test2::Update(const sf::Time& l_time){

}

void Test2::Draw(){
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
}

void Test2::Continue(EventDetails* l_details){
    std::cout << "switching to Test type" << std::endl;
    m_stateMgr->SwitchTo(StateType::Test);
}

void Test2::Tester(EventDetails* l_details){
    std::cout << "you called test2::Tester" << std::endl;
}

void Test2::Activate(){}
void Test2::Deactivate(){}
