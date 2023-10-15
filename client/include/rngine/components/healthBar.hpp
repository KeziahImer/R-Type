/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_HEALTH_HPP_
#define _RNGINE_COMPONENTS_HEALTH_HPP_
#include "../Entity.hpp"
#include "SFML/Graphics/Color.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
namespace RNGine {
namespace components {
struct healthBar {
  float hp;
  float maxHp;
  std::string textHealth;
  RNGine::Entity entity;
  std::string font;
  sf::Color color;
  int CharacterSize;

  static healthBar createhealthBar(float hp, float maxHp, RNGine::Entity entity,
                                   std::string font, sf::Color color,
                                   int CharacterSize) {
    auto val = healthBar();
    val.hp = hp;
    val.maxHp = maxHp;
    val.entity = entity;
    val.color = color;

    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
