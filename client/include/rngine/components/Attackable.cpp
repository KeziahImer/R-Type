/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Attackable
*/

#include "Attackable.hpp"

namespace RNGine {
namespace components {

Attackable Attackable::createAttackable(int health, int points, bool ally) {
    Attackable val;
    val.health = health;
    val.ally = ally;
    val.points = points;
    return val;
}

} // namespace components
} // namespace RNGine
