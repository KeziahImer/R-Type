/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** EnemyShoot
*/

#include "EnemyShoot.hpp"

namespace RNGine {
namespace components {

EnemyShoot EnemyShoot::createEnemyShoot(float speedX, float speedY,
                                         int timeMillisecond, int64_t lastShoot,
                                         float power, bool ally) {
    EnemyShoot val;
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
