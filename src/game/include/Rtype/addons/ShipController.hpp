/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_SHIPCONTROLLER_HPP_
#define _RTYPE_GAME_COMPONENTS_SHIPCONTROLLER_HPP_

#include "RNGine/RNGine.hpp"
#include <vector>

namespace Rtype {
namespace Addons {

struct ShipController {
  bool movingUp = false;
  bool movingDown = false;
  bool movingLeft = false;
  bool movingRight = false;
  bool shooting = false;

  float lastShoot = 0;
  std::vector<RNGine::Scene::Entity> bullets;
};

void ShipControllerSystem(RNGine::Core &core);

}; // namespace Addons
} // namespace Rtype

#endif