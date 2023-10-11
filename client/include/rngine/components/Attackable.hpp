/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_ATTACKABLE_HPP_
#define _RNGINE_COMPONENTS_ATTACKABLE_HPP_
#include <chrono>
namespace RNGine {
namespace components {
struct Attackable {
  int health;
  int points;
  bool ally;
  bool _Attackable;
  int invinsibilityTime = 50;
  int64_t lastShoot = 0;

  static Attackable createAttackable(int health, int points, bool ally,
                                     bool _Attackable) {
    auto val = Attackable();
    val.health = health;
    val.ally = ally;
    val.points = points;
    val._Attackable = _Attackable;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
