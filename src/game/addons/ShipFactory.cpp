#include "Rtype/addons/ShipFactory.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Collider.hpp"
#include "RNGine/components/Attackable.hpp"
#include "RNGine/components/Damages.hpp"
#include "RNGine/components/Score.hpp"
#include "Rtype/addons/ShipController.hpp"

#include <iostream>

void Rtype::Addons::ShipFactorySystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto entity = scene.GetEntity("ship-factory");
  auto &factory = scene.GetComponents<ShipFactory>()[entity];
  if (!factory.has_value())
    return;
  for (auto &request : factory->creationRequests) {
    auto ship = scene.CreateEntity("ship-" + std::to_string(request.id));
    factory->ships.push_back(ship);
    scene.AddComponent<RNGine::Components::Transform>(
        ship, {request.x, request.y, 0, 2.5, 2.5});
    scene.AddComponent(ship,
                       RNGine::Components::Hitbox({32 * 2.5, 14 * 2.5, 0, 0}));
    scene.AddComponent(
        ship, RNGine::Addons::Collider(
                  {false, RNGine::Addons::CollisionAction::PushingForce}));
    scene.AddComponent(ship, RNGine::Addons::Velocity());
    scene.AddComponent(ship, RNGine::Addons::Acceleration());
    scene.AddComponent(ship, RNGine::Components::Attackable({500, true}));
    scene.AddComponent(ship, RNGine::Addons::Limits(
                                 {1920, 1080, 0, 0, 1000, 1000, -1000, -1000}));
    scene.AddComponent(ship, Rtype::Addons::ShipController({}));
    scene.AddComponent(ship, RNGine::Components::Score({0}));
    scene.AddComponent(ship, RNGine::Components::Damages({25}));
    request.onCreation(core);
  }
  factory->creationRequests.clear();
}

Rtype::Addons::ShipCreationRequest
Rtype::Addons::ShipCreationRequest::createShipCreationRequest(
    int id, float x, float y,
    std::function<void(RNGine::Core &core)> onCreation) {
  auto val = ShipCreationRequest();
  val.id = id;
  val.x = x;
  val.y = y;
  val.onCreation = onCreation;
  return val;
}
