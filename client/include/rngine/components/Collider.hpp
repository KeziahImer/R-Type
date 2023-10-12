/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_COLLIDER_HPP_
#define _RNGINE_COMPONENTS_COLLIDER_HPP_
namespace RNGine {
namespace components {
struct Collider {
  float x;
  float y;

  static Collider createCollider(float x, float y);
};
} // namespace components
} // namespace RNGine

#endif
