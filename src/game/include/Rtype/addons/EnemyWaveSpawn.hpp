/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_ENEMYWAVESPAWN_HPP_
#define _RTYPE_CLIENT_ADDONS_ENEMYWAVESPAWN_HPP_
#include "RNGine/RNGine.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include <vector>

namespace Client {
namespace Components {
struct EnemyWaveSpawn {
  RNGine::Core::Time startSpawn;
  RNGine::Core::Time durationWave;
  RNGine::Core::Time frequence;
  std::vector<
      std::pair<std::map<std::string, ValueFirstMap>, std::map<std::string, Value>>>
      enemiesType;
  RNGine::Core::Time lastUpdate = 0;
  RNGine::Core::Time actualDuration = 0;
  bool started = false;
};

void EnemyWaveSpawnSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif