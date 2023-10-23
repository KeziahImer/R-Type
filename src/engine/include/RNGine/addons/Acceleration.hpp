/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_ENGINE_ADDONS_ACCELERATION_HPP_
#define _RTYPE_ENGINE_ADDONS_ACCELERATION_HPP_

#include <vector>

#include "../Core.hpp"
#include "../Scene.hpp"

namespace RNGine {
namespace Addons {
struct Acceleration {
  float x;
  float y;
};

void AccelerationSystem(RNGine::Core &core);

}; // namespace Addons
} // namespace RNGine

#endif