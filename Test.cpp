#include "Test.h"
#include "StateManager.h"

Test::Test(StateManager* l_stateManager)
    : BaseState(l_stateManager){}

Test::~Test(){}

void Test::OnCreate(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Test, "Tester", &Test::Tester, this);
//    evMgr->AddCallback(StateType::Test, "Tester", &Test::Tester, this);
}

void Test::OnDestroy(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Test,"Tester");
}

void Test::Update(const sf::Time& l_time){
//    std::cout << "Test::Update reached" << std::endl;
}

void Test::Draw(){
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
//    window->Draw(someDrawable);
}

void Test::Tester(EventDetails* l_details){
    std::cout << "Test::Tester reached" << std::endl;
}

void Test::Activate(){}
void Test::Deactivate(){}
