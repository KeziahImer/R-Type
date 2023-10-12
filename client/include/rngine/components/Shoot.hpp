/*
** EPITECH PROJECT, 2023
** Rtype
** File description:
** Components
*/

#ifndef _RNGINE_COMPONENTS_SHOOT_HPP_
#define _RNGINE_COMPONENTS_SHOOT_HPP_

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <map>
#include <utility>

#include "../Keys.hpp"
namespace RNGine {
namespace components {
struct Shoot {
  enum RNGine::Key Input;
  float speedX;
  float speedY;
  int timeMillisecond;
  int64_t lastShoot;
  float power;

  static Shoot createShoot(enum RNGine::Key Input, float speedX, float speedY,
                           int timeMillisecond, int64_t lastShoot,
                           float power) {
    auto val = Shoot();
    val.Input = Input;
    val.speedX = speedX;
    val.speedY = speedY;
    val.timeMillisecond = timeMillisecond;
    val.lastShoot = lastShoot;
    val.power = power;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
