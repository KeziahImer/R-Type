/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_POSITION_HPP_
#define _RNGINE_COMPONENTS_POSITION_HPP_
namespace RNGine {
namespace components {
struct Position {
  float x = 0;
  float y = 0;

  static Position createPosition(float x, float y);
};
} // namespace components
} // namespace RNGine
#endif
