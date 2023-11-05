/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_WINCONDITION_HPP_
#define _RTYPE_CLIENT_ADDONS_WINCONDITION_HPP_

#include <optional>
#include <vector>

#include "RNGine/Core.hpp"
#include "RNGine/RNGine.hpp"
#include "RNGine/Scene.hpp"

namespace Client {
namespace Components {
struct WinCondition {
  RNGine::Core::Time endGame = 0;
  bool boss = false;
  RNGine::Core::Time lastUpdate = 0;
  std::vector<RNGine::Scene::Entity> entities;
};

void WinConditionSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif