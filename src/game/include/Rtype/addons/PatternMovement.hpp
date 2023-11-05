/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_PATTERNMOVEMENT_HPP_
#define _RTYPE_GAME_COMPONENTS_PATTERNMOVEMENT_HPP_

#include "EnemyFactory.hpp"
#include "RNGine/RNGine.hpp"
#include <vector>

namespace Rtype {
namespace Addons {

struct PatternMovement {
  bool loop;
  std::vector<std::pair<RNGine::Core::Time, std::pair<float, float>>> pattern;
  int loopFrames;
  RNGine::Core::Time lastUpdate = 0;
  size_t index = 0;
  bool end = false;
};

void PatternMovementSystem(RNGine::Core &core);

}; // namespace Addons
} // namespace Rtype

#endif