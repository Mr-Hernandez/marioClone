#include "EventManager.h"

EventManager::EventManager(){

}




void EventManager::IssueCallback(){
    callback(&m_details);
}

void EventManager::HandleEvent(sf::Event l_event){
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
//        IssueCallback();
//    }

// Using this method of type checking the event, we can
// cleanly get a single input. This works best for actions that
// expect only a single input. Example, if this key is pressed and held
// there is a delay between reading the first and second input.
// for continuous input, it might be better to use the method of
// using sf::Keyboard isKeyPressed('Key') rather the type check method.
    if(l_event.type == sf::Event::KeyPressed){
        if(l_event.key.code == sf::Keyboard::S)
        {
            std::cout << "l_event is " << l_event.key.code <<
                " and type " << l_event.type << std::endl;
            IssueCallback();
        }
    }
}
