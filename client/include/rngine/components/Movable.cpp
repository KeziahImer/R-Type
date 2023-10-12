/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Movable
*/

#include "Movable.hpp"

namespace RNGine {
namespace components {

Movable Movable::createmovable(std::map<enum RNGine::Key, std::pair<float, float>> keybinds) {
    Movable val;
    val.keybinds = keybinds;
    return val;
}
} // namespace components
} // namespace RNGine
