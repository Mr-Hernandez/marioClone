#include "SFML/Graphics.hpp"
#include "Game.h"
#include <iostream>

struct myStruct{
    int x = 1;
};

int main(){

    Game game;
    while(!game.GetWindow()->IsDone()){
        game.Update();
        game.Render();
        game.LateUpdate();
    }
//for(int i = 0; i < 5; i++){
//    myStruct* S = new myStruct();
//    std::cout << S->x << std::endl;
//    S = nullptr;
//}
//myStruct* S = new myStruct();
//std::cout << S->x << std::endl;
//S = nullptr;
//myStruct* S = new myStruct();
//std::cout << S->x << std::endl;


//    Window window;
//    while(window.IsDone()){
//        window.Render();
//    }

//    sf::RenderWindow window(sf::VideoMode(800, 800), "marioClone");
//
//    while(window.isOpen()){
//        sf::Event event;
//        while(window.pollEvent(event)){
//            if(event.type == sf::Event::Closed){
//                window.close();
//            }
//        window.clear(sf::Color::Blue);
//        window.display();
//        }
//
//    }
}
