#include "Test.h"
#include "StateManager.h"

Test::Test(StateManager* l_stateManager)
    : BaseState(l_stateManager){}

Test::~Test(){}

void Test::OnCreate(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Test, "Tester", &Test::Tester, this);
    evMgr->AddCallback(StateType::Test, "GoBack", &Test::GoBack, this);
    std::cout << "Test::OnCreate Reached" << std::endl;
    evMgr->AddCallback(StateType::Test, "SetJump", &character::SetJump, &m_character);
//    evMgr->AddCallback(StateType::Test, "Tester", &Test::Tester, this);
}

void Test::OnDestroy(){
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Test,"Tester");
    evMgr->RemoveCallback(StateType::Test,"GoBack");
}

void Test::Update(const sf::Time& l_time){
//    std::cout << "Test::Update reached" << std::endl;
    m_character.SetPlatPosition(m_map.GetPlatSize());
    m_character.Update(l_time);
}

void Test::Draw(){
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
//    window->Draw(someDrawable);
    m_map.Render(*window);
    m_character.Render(*window);

}

void Test::Tester(EventDetails* l_details){
    std::cout << "Test::Tester reached: ";
    obj1.printTally();
    std::cout << " -> ";
    obj1.AddOne();
    obj1.printTally();
}

void Test::GoBack(EventDetails* l_details){
    std::cout << "going back to Test2 type" << std::endl;
    m_stateMgr->SwitchTo(StateType::Test2);
//    m_stateMgr->Remove(StateType::Test); // can be used to destroy the class obj
}

void Test::Activate(){}
void Test::Deactivate(){}
