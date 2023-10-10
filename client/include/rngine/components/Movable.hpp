/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_MOVABLE_HPP_
#define _RNGINE_COMPONENTS_MOVABLE_HPP_

#include <map>
#include <utility>

#include "../Keys.hpp"

namespace RNGine {
namespace components {
struct Movable {
  std::map<enum RNGine::Key, std::pair<float, float>> keybinds = {};

  static Movable
  createmovable(std::map<enum RNGine::Key, std::pair<float, float>> keybinds) {
    auto val = Movable();
    val.keybinds = keybinds;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
