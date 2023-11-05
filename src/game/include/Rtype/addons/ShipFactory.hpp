/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_SHIPFACTORY_HPP_
#define _RTYPE_GAME_COMPONENTS_SHIPFACTORY_HPP_

#include "RNGine/RNGine.hpp"
#include <vector>

namespace Rtype {
namespace Addons {

struct ShipCreationRequest {
  int id;
  float x;
  float y;
  // std::function<void(RNGine::Core &core)> onCreation;

  static ShipCreationRequest createShipCreationRequest(int id, float x,
                                                       float y);
};

struct ShipFactory {
  std::vector<ShipCreationRequest> creationRequests;
  std::vector<RNGine::Scene::Entity> ships;
};

void ShipFactorySystem(RNGine::Core &core);

}; // namespace Addons
} // namespace Rtype

#endif