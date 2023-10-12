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
                             int tileY, int layer);
};
} // namespace components
} // namespace RNGine

#endif
