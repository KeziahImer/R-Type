#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow _window(sf::VideoMode(1920, 1080), "R-Type");
    while (_window.isOpen())
    {
        sf::Event event;
        if (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _window.display();
    }
    return 0;
}