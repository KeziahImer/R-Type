/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** MakeDamage
*/

#include "MakeDamage.hpp"

namespace RNGine {
namespace components {

MakeDamage MakeDamage::createMakeDamage(float Damage, bool ally) {
    MakeDamage val;
    val.Damage = Damage;
    val.ally = ally;
    return val;
}

} // namespace components
} // namespace RNGine
