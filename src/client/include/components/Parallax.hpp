/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_COMPONENTS_PARALLAX_HPP_
#define _RTYPE_CLIENT_COMPONENTS_PARALLAX_HPP_

#include "RNGine/RNGine.hpp"
namespace r
{
#include "raylib.h"
}
#include <iostream>
#include <ostream>

namespace Client {
namespace Components {
struct Parallax {
  std::pair<float, float> position = {0, 0};
};

void ParallaxSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif