/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_ATTACKABLE_HPP_
#define _RNGINE_COMPONENTS_ATTACKABLE_HPP_
namespace RNGine {
namespace components {
struct Attackable {
  int health;

  static Attackable createAttackable(int health) {
    auto val = Attackable();
    val.health = health;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
