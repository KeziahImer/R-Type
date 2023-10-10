/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_TEXT_HPP_
#define _RNGINE_COMPONENTS_TEXT_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
namespace RNGine {
namespace components {
struct Text {
  std::string text;
  sf::Color color;
  int CharacterSize;

  static Text createText(std::string text, sf::Color color, int CharacterSize) {
    auto val = Text();
    val.text = text;
    val.color = color;
    val.CharacterSize = CharacterSize;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
