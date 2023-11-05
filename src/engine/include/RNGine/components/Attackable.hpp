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
namespace Components {
struct Attackable {
  int health;
  bool ally;
  int points = 0;
  bool _Attackable = true;
  int invinsibilityTime = 300;
  int64_t lastShoot = 0;
};
} // namespace Components
} // namespace RNGine

#endif
