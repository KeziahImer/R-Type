/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Sprite
*/

#include "Sprite.hpp"

namespace RNGine {
namespace components {

Sprite Sprite::createSprite(const std::string &path, bool reverse,
                           float sizeTileX, float sizeTileY, int tileX,
                           int tileY, int layer) {
    Sprite sprite;
    sprite.path = path;
    sprite.reverse = reverse;
    sprite.sizeTileX = sizeTileX;
    sprite.sizeTileY = sizeTileY;
    sprite.tileX = tileX;
    sprite.tileY = tileY;
    sprite.layer = layer;
    return sprite;
}

} // namespace components
} // namespace RNGine
