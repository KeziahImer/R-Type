/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Inputer
*/

#include "Inputer.hpp"

Inputer::Inputer(sf::RenderWindow &window) : _window(window) {}

Inputer::~Inputer() {}

std::map<enum sf::Keyboard::Key, bool> Inputer::getInputs() {
  sf::Event event;
  while (_window.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      keybinds[event.key.code] = true;
      break;
    case sf::Event::KeyReleased:
      keybinds[event.key.code] = false;
      break;
    case sf::Event::Closed:
      _window.close();
      break;
    default:
      break;
    }
  }
  return keybinds;
}