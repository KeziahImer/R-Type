/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_LOOT_HPP_
#define _RTYPE_GAME_COMPONENTS_LOOT_HPP_

#include "RNGine/RNGine.hpp"
#include "Rtype/addons/LootableEntity.hpp"
#include <vector>

namespace Rtype {
namespace Addons {

struct IsLoot {
  enum Rtype::Components::typeLoot type;
  float value;
};

void IsLootSystem(RNGine::Core &core);

}; // namespace Addons
} // namespace Rtype

#endif