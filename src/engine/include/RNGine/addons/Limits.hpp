/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_ENGINE_ADDONS_LIMITS_HPP_
#define _RTYPE_ENGINE_ADDONS_LIMITS_HPP_

#include <vector>

#include "../Core.hpp"
#include "../Scene.hpp"

namespace RNGine {
namespace Addons {
struct Limits {
  float maxX;
  float maxY;
  float minX;
  float minY;

  float maxVX;
  float maxVY;
  float minVX;
  float minVY;

  float maxAX;
  float maxAY;
  float minAX;
  float minAY;
};

void LimitsSystem(RNGine::Core &core);

}; // namespace Addons
} // namespace RNGine

#endif