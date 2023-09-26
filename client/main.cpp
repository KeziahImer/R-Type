/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "Parsing.hpp"
#include "SpriteManager.hpp"

int main()
{
    Parsing parser;
    std::unique_ptr<SceneManager> sceneManager;
    parser.parseJsonFiles();
    std::cout << parser.getAllData() << std::endl;

    if (parser.getAllData().size() != 0)
        sceneManager = std::make_unique<SceneManager>(parser.getAllData());
    else {
        std::cerr << "Pas de json disponible" << std::endl;
        return 0;
    }

    sceneManager.get()->loadScene(sceneManager.get()->getAllScenes().front());
    sf::RenderWindow _window(sf::VideoMode(1920, 1080), "R-Type");
    while (_window.isOpen()) {
        sf::Event event;
        if (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }
        _window.clear();
        _window.display();
    }
    return 0;
}
