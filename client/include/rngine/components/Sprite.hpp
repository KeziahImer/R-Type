/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_SPRITE_HPP_
#define _RNGINE_COMPONENTS_SPRITE_HPP_

#include <string>
namespace RNGine {
namespace components {
struct Sprite {
  std::string path;
  bool reverse;
  float sizeTileX;
  float sizeTileY;
  int tileX;
  int tileY;

  static Sprite createSprite(const std::string &path, bool reverse,
                             float sizeTileX, float sizeTileY, int tileX,
                             int tileY) {

    auto sprite = RNGine::components::Sprite();
    sprite.path = path;
    sprite.reverse = reverse;
    sprite.sizeTileX = sizeTileX;
    sprite.sizeTileY = sizeTileY;
    sprite.tileX = tileX;
    sprite.tileY = tileY;
    return sprite;
  }
};
} // namespace components
} // namespace RNGine

#endif
