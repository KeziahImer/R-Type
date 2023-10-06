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
};
} // namespace components
} // namespace RNGine

#endif
