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
  int points;
  bool ally;

  static Attackable createAttackable(int health, int points, bool ally);
  };
} // namespace components
} // namespace RNGine

#endif
