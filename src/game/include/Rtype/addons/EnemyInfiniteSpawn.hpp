/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype game
*/

#ifndef _RTYPE_CLIENT_ADDONS_ENEMYSPAWN_HPP_
#define _RTYPE_CLIENT_ADDONS_ENEMYSPAWN_HPP_

#include "Rtype/addons/EnemyFactory.hpp"

namespace Client {
namespace Components {
struct EnemySpawn {
  RNGine::Core::Time frequence;
  std::vector<std::pair<std::map<std::string, ValueFirstMap>,
                        std::map<std::string, Value>>>
      enemiesType;
  RNGine::Core::Time lastUpdate = 0;
};

void EnemySpawnSystem(RNGine::Core &core);
} // namespace Components
} // namespace Client

#endif