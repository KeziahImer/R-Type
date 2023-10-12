/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_ENEMYSHOOT_HPP_
#define _RNGINE_COMPONENTS_ENEMYSHOOT_HPP_

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <map>
#include <utility>

#include "../Keys.hpp"
namespace RNGine {
namespace components {
struct EnemyShoot {
  float speedX = 0;
  float speedY = 0;
  int timeMillisecond = 0;
  int64_t lastShoot = 0;
  float power = 0;
  bool ally = false;

  static EnemyShoot createEnemyShoot(float speedX, float speedY,
                                     int timeMillisecond, int64_t lastShoot,
                                     float power, bool ally);
};
} // namespace components
} // namespace RNGine

#endif
