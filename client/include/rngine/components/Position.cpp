/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Position
*/

#include "Position.hpp"

namespace RNGine {
namespace components {

Position Position::createPosition(float x, float y) {
    Position sprite;
    sprite.x = x;
    sprite.y = y;
    return sprite;
}

} // namespace components
} // namespace RNGine

