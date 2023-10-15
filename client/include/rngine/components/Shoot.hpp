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
  enum RNGine::Key Input = RNGine::Key::KeyCount;
  float speedX = 0;
  float speedY = 0;
  int timeMillisecond = 0;
  int64_t lastShoot = 0;
  float power = 0;
  bool ally = true;

  static Shoot createShoot(enum RNGine::Key Input, float speedX, float speedY,
                           int timeMillisecond, int64_t lastShoot, float power,
                           bool ally) {
    auto val = Shoot();
    val.Input = Input;
    val.speedX = speedX;
    val.speedY = speedY;
    val.timeMillisecond = timeMillisecond;
    val.lastShoot = lastShoot;
    val.power = power;
    val.ally = ally;
    return val;
  }
};
} // namespace components
} // namespace RNGine

#endif
