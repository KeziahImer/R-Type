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
  int speedX;
  bool canShoot;
  int timeMillisecond;
  int64_t lastShoot;
};
} // namespace components
} // namespace RNGine

#endif
