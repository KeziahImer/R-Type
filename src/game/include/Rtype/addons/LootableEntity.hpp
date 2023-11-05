/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_LOOTABLEENTITY_HPP_
#define _RTYPE_GAME_COMPONENTS_LOOTABLEENTITY_HPP_

#include "RNGine/RNGine.hpp"
#include <vector>

namespace Rtype {
namespace Components {

enum typeLoot { HEAL, ATTACKUP };
struct LootableEntity {
  std::map<enum typeLoot, float> lootChances = {{HEAL, 10}, {ATTACKUP, 10}};
};

}; // namespace Components
} // namespace Rtype

#endif