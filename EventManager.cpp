#include "EventManager.h"

EventManager::EventManager()
{
    LoadBindings();

}

void EventManager::LoadBindings(){

    // open a file and check if it was opened
    std::ifstream bindFile("Resources/files/keys.cfg");
    if(bindFile.is_open()){
        std::cout << "Loaded keys.cfg" << std::endl;
    } else {
        std::cout << "Failed to load keys.cfg" << std::endl;
        return;
    }

    std::string delimiter = ":";
    std::string line;
    while(std::getline(bindFile, line)){
        std::stringstream keystream(line);
        std::string callbackName;
        keystream >> callbackName;
        // create new binding here
        std::cout << "callbackName: " << callbackName;

        // now while not at end of file of keystream
        // we get event and key input codes in the form (#:# #:# ....)
        while(!keystream.eof()){
            std::string keyVal;
            keystream >> keyVal;
            if(keystream.fail()){
                keystream.clear();
                break;
            }
            int start = 0;
            int last = keyVal.find(delimiter);
            int type = std::stoi(keyVal.substr(start, last - start));
            int code = std::stoi(keyVal.substr(last + delimiter.length(),
                keyVal.find(delimiter, last + delimiter.length())));
            std::cout << " type: " << type << " code: " << code << std::endl;
        }


    }
    bindFile.close();
}



void EventManager::IssueCallback(){
    callback(&m_details);
}

void EventManager::HandleEvent(sf::Event l_event){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        IssueCallback();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        IssueCallback();
    }

// Using this method of type checking the event, we can
// cleanly get a single input. This works best for actions that
// expect only a single input. Example, if this key is pressed and held
// there is a delay between reading the first and second input.
// for continuous input, it might be better to use the method of
// using sf::Keyboard isKeyPressed('Key') rather the type check method.
//    if(l_event.type == sf::Event::KeyPressed){
//        if(l_event.key.code == sf::Keyboard::S)
//        {
//            std::cout << "S Pressed---------------------------" << std::endl;
//            IssueCallback();
//        }
//        if(l_event.key.code == sf::Keyboard::Space)
//        {
//            std::cout << "l_event is " << l_event.key.code <<
//                " and type " << l_event.type << std::endl;
//            IssueCallback();
//        }
//    }

}

// Setters and Getters
void EventManager::SetEvent(sf::Event* l_event){ m_details.s_event = *l_event;}
