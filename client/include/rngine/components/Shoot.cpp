/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Shoot
*/

#include "Shoot.hpp"

namespace RNGine {
namespace components {

Shoot Shoot::createShoot(enum RNGine::Key Input, float speedX, float speedY,
                         int timeMillisecond, int64_t lastShoot, float power,
                         bool ally) {
    Shoot val;
    val.Input = Input;
    val.speedX = speedX;
    val.speedY = speedY;
    val.timeMillisecond = timeMillisecond;
    val.lastShoot = lastShoot;
    val.power = power;
    val.ally = ally;
    return val;
}

} // namespace components
} // namespace RNGine
