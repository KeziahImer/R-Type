/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_CLICKABLE_HPP_
#define _RNGINE_COMPONENTS_CLICKABLE_HPP_
namespace RNGine {
namespace components {
struct Clickable {
  float x;
  float y;

  static Clickable createClickable(float x, float y) {
    auto val = Clickable();
    val.x = x;
    val.y = y;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
