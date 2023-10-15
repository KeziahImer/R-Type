/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_BUTTON_HPP_
#define _RNGINE_COMPONENTS_BUTTON_HPP_
#include "SFML/Graphics/Color.hpp"
#include "text.hpp"
#include <functional>
#include <string>
namespace RNGine {
namespace components {
struct Button {
  float x;
  float y;
  std::function<void(void)> function;
  std::string buttonText;
  std::string font;
  sf::Color color;
  int CharacterSize;

  static Button createClickable(float x, float y,
                                std::function<void(void)> function,
                                std::string buttonText, sf::Color color,
                                std::string font, int CharacterSize) {
    auto val = Button();
    val.x = x;
    val.y = y;
    val.function = function;
    val.buttonText = buttonText;
    val.color = color;
    val.font = font;
    val.CharacterSize = CharacterSize;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
