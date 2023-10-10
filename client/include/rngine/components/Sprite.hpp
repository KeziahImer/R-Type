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
  std::string path = "";
  bool reverse = false;
  float sizeTileX = 0;
  float sizeTileY = 0;
  int tileX = 0;
  int tileY = 0;
  int layer = 0;

  static Sprite createSprite(const std::string &path, bool reverse,
                             float sizeTileX, float sizeTileY, int tileX,
                             int tileY, int layer) {

    auto sprite = RNGine::components::Sprite();
    sprite.path = path;
    sprite.reverse = reverse;
    sprite.sizeTileX = sizeTileX;
    sprite.sizeTileY = sizeTileY;
    sprite.tileX = tileX;
    sprite.tileY = tileY;
    sprite.layer = layer;
    return sprite;
  }
};
} // namespace components
} // namespace RNGine

#endif
