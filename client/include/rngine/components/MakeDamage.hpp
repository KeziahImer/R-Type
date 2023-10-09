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

  static MakeDamage createMakeDamage(float Damage) {
    auto val = MakeDamage();
    val.Damage = Damage;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
