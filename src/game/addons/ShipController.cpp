#include "Rtype/addons/ShipController.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include <iostream>

void Rtype::Addons::ShipControllerSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &controllers = scene.GetComponents<ShipController>();
  auto &accelerations = scene.GetComponents<RNGine::Addons::Acceleration>();
  auto &velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &limits = scene.GetComponents<RNGine::Addons::Limits>();

  auto max = controllers.size();
  for (size_t i = 0; i < max; i++) {
    auto &controller = controllers[i];
    auto &acceleration = accelerations[i];
    auto &velocity = velocities[i];
    auto &limit = limits[i];
    auto &transform = transforms[i];
    if (!controller.has_value() || !acceleration.has_value() ||
        !limit.has_value() || !transform.has_value())
      continue;
    if (controller->movingUp)
      velocity->y = limit->minVY;
    if (controller->movingDown)
      velocity->y = limit->maxVY;
    if (!controller->movingUp && !controller->movingDown) {
      velocity->y = 0;
    }
    if (controller->movingLeft)
      velocity->x = limit->minVX;
    if (controller->movingRight)
      velocity->x = limit->maxVX;
    if (!controller->movingLeft && !controller->movingRight) {
      velocity->x = 0;
    }

    if (controller->shooting &&
        controller->lastShoot + 0.2 < core.currentTime) {
      controller->lastShoot = core.currentTime;
      auto entity = scene.CreateEntity();
      scene.AddComponent<RNGine::Components::Transform>(
          entity, {transform->x, transform->y, 0, 2, 2});
      scene.AddComponent(
          entity, RNGine::Components::Hitbox({32 * 2, 10 * 2, 32 / 2, 10 / 2}));
      scene.AddComponent(entity, RNGine::Addons::Collider());
      scene.AddComponent(entity, RNGine::Addons::Velocity({1200, 0}));
      controller->bullets.push_back(entity);
    }

    for (auto bullet : controller->bullets) {
      auto &bulletTransform = transforms[bullet];
      if (!bulletTransform.has_value())
        continue;
      if (bulletTransform->x > 2000)
        scene.RemoveEntity(bullet);
    }
  }
}