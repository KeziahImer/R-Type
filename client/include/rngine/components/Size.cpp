/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Size
*/

#include "Size.hpp"

namespace RNGine {
namespace components {

Size Size::createSize(double scaleX, double scaleY) {
    Size val;
    val.scaleX = scaleX;
    val.scaleY = scaleY;
    return val;
}

} // namespace components
} // namespace RNGine
