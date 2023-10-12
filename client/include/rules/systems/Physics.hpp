/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Menu Scene
*/

#ifndef _RTYPE_SYSTEMS_PHYSICS_HPP_
#define _RTYPE_SYSTEMS_PHYSICS_HPP_

#include "rngine/Keys.hpp"
#include "rngine/Registry.hpp"
#include "rngine/Scene.hpp"
#include "rngine/components/Movable.hpp"
#include "rngine/components/Position.hpp"
#include "rngine/components/Size.hpp"
#include "rngine/components/Sprite.hpp"
#include "rngine/components/Velocity.hpp"

#include <cstddef>

namespace Rtype {

RNGine::Registry::System velocitySystem = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Velocity> &Velocities =
      registry.getComponents<RNGine::components::Velocity>();
  RNGine::SparseArray<RNGine::components::Position> &Positions =
      registry.getComponents<RNGine::components::Position>();

  float deltaTime = registry.clock.getDeltaTimeMilliseconds();
  for (size_t i = 0; i < Velocities.size(); i++) {
    if (!Positions[i].has_value() || !Velocities[i].has_value())
      continue;
    Positions[i]->x = Positions[i]->x + (Velocities[i]->x * deltaTime);
    Positions[i]->y = Positions[i]->y + (Velocities[i]->y * deltaTime);
  }
};

RNGine::Registry::System MovableSystem = [](RNGine::Registry &registry) {
  RNGine::SparseArray<RNGine::components::Movable> &Movables =
      registry.getComponents<RNGine::components::Movable>();
  RNGine::SparseArray<RNGine::components::Velocity> &Velocities =
      registry.getComponents<RNGine::components::Velocity>();
  std::map<enum RNGine::Key, bool> inputs = registry.inputs;
  for (size_t i = 0; i < Movables.size(); i++) {
    if (!Movables[i].has_value() || !Velocities[i].has_value())
      continue;
    Velocities[i]->x = 0;
    Velocities[i]->y = 0;
    for (auto inputPress : inputs) {
      for (auto inputRequire : Movables[i]->keybinds) {
        if ((inputPress.first == inputRequire.first) && inputPress.second) {
          Velocities[i]->x += inputRequire.second.first;
          Velocities[i]->y += inputRequire.second.second;
        }
      }
    }
  }
};

RNGine::Registry::SystemBundle physicsSystems = {
    velocitySystem, MovableSystem}; // namespace Rtype
} // namespace Rtype
#endif