/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** SelfDestroy
*/

#include "SelfDestroy.hpp"

namespace RNGine {
namespace components {

Selfdestroy Selfdestroy::createSelfDestroy(float MaxX, float MaxY, float MinX, float MinY) {
    Selfdestroy val;
    val.MaxX = MaxX;
    val.MaxY = MaxY;
    val.MinX = MinX;
    val.MinY = MinY;
    return val;
}

} // namespace components
} // namespace RNGine
