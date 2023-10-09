/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_SIZE_HPP_
#define _RNGINE_COMPONENTS_SIZE_HPP_
namespace RNGine {
namespace components {
struct Size {
  double scaleX;
  double scaleY;

  static Size createSize(double scaleX, double scaleY) {
    auto val = Size();
    val.scaleX = scaleX;
    val.scaleY = scaleY;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
