/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_ENEMYINFO_HPP_
#define _RTYPE_GAME_COMPONENTS_ENEMYINFO_HPP_

#include <vector>
#include "Rtype/addons/EnemyFactory.hpp"

namespace Rtype {
namespace Components {

struct enemyInformation {
  std::map<std::string, Value> informations;
};

}; // namespace Addons
} // namespace Rtype

#endif