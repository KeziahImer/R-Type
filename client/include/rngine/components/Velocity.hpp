/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_VELOCITY_HPP_
#define _RNGINE_COMPONENTS_VELOCITY_HPP_
namespace RNGine {
namespace components {
struct Velocity {
  float x;
  float y;

  static Velocity createVelocity(float x, float y) {
    auto val = Velocity();
    val.x = x;
    val.y = y;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
