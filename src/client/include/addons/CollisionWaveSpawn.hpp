/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_COLLISIONWAVESPAWN_HPP_
#define _RTYPE_CLIENT_ADDONS_COLLISIONWAVESPAWN_HPP_
#include "RNGine/RNGine.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include <vector>

namespace Client {
namespace Components {
struct CollisionWaveSpawn {
  RNGine::Core::Time startSpawn;
  RNGine::Core::Time durationWave;
  RNGine::Core::Time frequence;
  std::vector<
      std::pair<std::map<std::string, ValueFirstMapCollision>, std::map<std::string, ValueCollision>>>
      collisionsType;
  RNGine::Core::Time lastUpdate = 0;
  RNGine::Core::Time actualDuration = 0;
  bool started = false;
};

void CollisionWaveSpawnSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif