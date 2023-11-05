/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_PATTERNSHOOT_HPP_
#define _RTYPE_GAME_COMPONENTS_PATTERNSHOOT_HPP_

#include "RNGine/RNGine.hpp"
#include "EnemyFactory.hpp"
#include <vector>

namespace Rtype {
namespace Addons {

struct PatternShoot {
  bool loop;
  std::vector<std::pair<RNGine::Core::Time, std::pair<RNGine::Core::Time, std::pair<float, float>>>> pattern;
  RNGine::Core::Time lastUpdate = 0;
  size_t index = 0;
  bool end = false;
};

void PatternShootSystem(RNGine::Core &core);

}; // namespace Addons
} // namespace Rtype

#endif