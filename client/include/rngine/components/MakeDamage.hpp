/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_MAKEDAMAGE_HPP_
#define _RNGINE_COMPONENTS_MAKEDAMAGE_HPP_
namespace RNGine {
namespace components {
struct MakeDamage {
  float Damage;
  bool ally;

  static MakeDamage createMakeDamage(float Damage, bool ally);
};
} // namespace components
} // namespace RNGine

#endif
