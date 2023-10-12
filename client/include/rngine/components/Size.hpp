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
  double scaleX = 0;
  double scaleY = 0;

  static Size createSize(double scaleX, double scaleY);
};
} // namespace components
} // namespace RNGine

#endif