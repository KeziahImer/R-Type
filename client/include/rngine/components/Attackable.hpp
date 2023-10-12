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
  bool ally;

  static Attackable createAttackable(int health, bool ally) {
    auto val = Attackable();
    val.health = health;
    val.ally = ally;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
