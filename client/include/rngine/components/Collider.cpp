/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** *
*/

#include "Collider.hpp"

namespace RNGine {
namespace components {

Collider Collider::createCollider(float x, float y) {
    Collider val;
    val.x = x;
    val.y = y;
    return val;
}

} // namespace components
} // namespace RNGine

