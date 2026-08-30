#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode({800,600}), "SFML Works!");

    while(window.isOpen()){

        while(const optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>())
            window.close();
        }

        window.clear(sf::Color::Green);
        window.display();
    }

    return 0;
}