#include "Rtype/addons/ShipFactory.hpp"
#include "RNGine/addons/Acceleration.hpp"
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
    scene.AddComponent(
        ship, RNGine::Components::Hitbox({32 * 2.5, 14 * 2.5, 32 / 2, 14 / 2}));
    scene.AddComponent(ship, RNGine::Addons::Collider());
    scene.AddComponent(ship, RNGine::Addons::Velocity());
    scene.AddComponent(ship, RNGine::Addons::Acceleration());
    scene.AddComponent(ship, RNGine::Addons::Limits(
                                 {1920, 1080, 0, 0, 1000, 1000, -1000, -1000}));
    scene.AddComponent(ship, Rtype::Addons::ShipController({}));
  }
  factory->creationRequests.clear();
}
