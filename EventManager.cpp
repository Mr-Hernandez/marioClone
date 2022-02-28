#include "EventManager.h"

EventManager::EventManager(){

}




void EventManager::IssueCallback(){
    callback(&m_details);
}

void EventManager::HandleEvent(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        IssueCallback();
    }

}
