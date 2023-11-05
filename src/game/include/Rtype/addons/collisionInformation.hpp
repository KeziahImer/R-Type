/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_COLLISIONINFO_HPP_
#define _RTYPE_GAME_COMPONENTS_COLLISIONINFO_HPP_

#include <vector>
#include "Rtype/addons/CollisionFactory.hpp"

namespace Rtype {
namespace Components {

struct collisionInformation {
  std::map<std::string, ValueCollision> informations;
};

}; // namespace Addons
} // namespace Rtype

#endif