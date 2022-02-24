#include "SFML/Graphics.hpp"
#include "Game.h"

int main(){

    Game game;
    while(game.GetWindow()->IsDone()){
        game.Update();
        game.Render();
        game.RestartClock();
    }
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
