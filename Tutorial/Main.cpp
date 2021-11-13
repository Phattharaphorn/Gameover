#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include <vector>

#include "Gameover.h"

using namespace std;
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game", Style::Titlebar | Style::Close);

    Gameover gameover(window.getSize().x, window.getSize().y);
    window.setVerticalSyncEnabled(true);
    srand(time(NULL));

    float deltaTime = 0;
    Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                     gameover.MoveUp();
                     break;

                case sf::Keyboard::Down:
                     gameover.MoveDown();
                     break;
                }                
                break;
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        gameover.draw(window);
        window.display();
    }
    return 0;
}