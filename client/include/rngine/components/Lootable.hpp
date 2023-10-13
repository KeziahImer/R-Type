/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_LOOTABLE_HPP_
#define _RNGINE_COMPONENTS_LOOTABLE_HPP_
#include "../Entity.hpp"
#include "SFML/Graphics/Color.hpp"
#include "rngine/Registry.hpp"
#include "rngine/components/Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <string>
namespace RNGine {
namespace components {
struct Lootable {
  std::function<void(Registry &registry)> function;
  int percentLootChance = 0;
  RNGine::components::Sprite spriteLoot;
  static Lootable
  createLootable(std::function<void(Registry &registry)> function,
                 int percentLootChance, RNGine::components::Sprite spriteLoot) {
    auto val = Lootable();
    val.function = function;
    val.percentLootChance = percentLootChance;
    val.spriteLoot = spriteLoot;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
