/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_ENGINE_ADDONS_VELOCITY_HPP_
#define _RTYPE_ENGINE_ADDONS_VELOCITY_HPP_

#include <vector>

#include "../Core.hpp"
#include "../Scene.hpp"

namespace RNGine {
namespace Addons {
struct Velocity {
  float x;
  float y;
};

void VelocitySystem(RNGine::Core &core);

}; // namespace Addons
} // namespace RNGine

#endif