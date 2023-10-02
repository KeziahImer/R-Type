/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Inputer
*/

#pragma once
#include <SFML/Graphics.hpp>

class Inputer {
    public:
        Inputer(sf::RenderWindow &window);
        ~Inputer();

        std::map<enum sf::Keyboard::Key, bool> getInputs();

    private:
        std::map<enum sf::Keyboard::Key, bool> keybinds;
        sf::RenderWindow &_window;
};
