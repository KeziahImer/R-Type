#include "Rtype/addons/ShipController.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/Damages.hpp"
#include "RNGine/components/MakeDamage.hpp"
#include <iostream>

void Rtype::Addons::ShipControllerSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &controllers = scene.GetComponents<ShipController>();
  auto &accelerations = scene.GetComponents<RNGine::Addons::Acceleration>();
  auto &velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &limits = scene.GetComponents<RNGine::Addons::Limits>();
  auto &hitboxs = scene.GetComponents<RNGine::Components::Hitbox>();
  auto &damages = scene.GetComponents<RNGine::Components::Damages>();

  auto max = controllers.size();
  for (size_t i = 0; i < max; i++) {
    auto &controller = controllers[i];
    auto &acceleration = accelerations[i];
    auto &velocity = velocities[i];
    auto &limit = limits[i];
    auto &transform = transforms[i];
    if (!controller.has_value() || !acceleration.has_value() ||
        !limit.has_value() || !transform.has_value() ||
        !damages[i].has_value() || !velocity.has_value())
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
        controller->lastShoot +
                (controller->weapon == Rtype::Addons::WeaponType::Basic ? 0.2
                                                                        : 1) <
            core.currentTime) {
      controller->lastShoot = core.currentTime;
      auto entity = scene.CreateEntity();
      if (!hitboxs[i].has_value())
        continue;
      if (controller->weapon == Rtype::Addons::WeaponType::Basic) {
        scene.AddComponent<RNGine::Components::Transform>(
            entity, {transform->x + hitboxs[i]->width, transform->y, 0, 2, 2});
        scene.AddComponent(entity,
                           RNGine::Components::Hitbox({32 * 2, 10 * 2, 0, 0}));
        scene.AddComponent(
            entity, RNGine::Addons::Collider(
                        {false, RNGine::Addons::CollisionAction::Explosion}));
        scene.AddComponent(entity, RNGine::Addons::Velocity({1200, 0}));
        scene.AddComponent<RNGine::Components::MakeDamage>(
            entity, {damages[i]->damages, true, i});
        scene.AddComponent<RNGine::Addons::destroyLimit>(entity, {-100, 2020});
      } else if (controller->weapon == Rtype::Addons::WeaponType::Laser) {
        scene.AddComponent<RNGine::Components::Transform>(
            entity,
            {transform->x + hitboxs[i]->width, transform->y - 30, 0, 2, 2});
        scene.AddComponent(entity,
                           RNGine::Components::Hitbox({32 * 2, 10 * 2, 0, 0}));
        scene.AddComponent(entity,
                           RNGine::Addons::Collider(
                               {false, RNGine::Addons::CollisionAction::None}));
        scene.AddComponent(entity, RNGine::Addons::Velocity({2000, 0}));
        scene.AddComponent<RNGine::Components::MakeDamage>(
            entity, {damages[i]->damages + 20,
                     true,
                     i,
                     "./assets/beam.png",
                     {91.0f, 0.0f},
                     {91.0f, 48.0f},
                     "./assets/sounds/beam.wav"});
        scene.AddComponent<RNGine::Addons::destroyLimit>(entity, {-100, 2020});
      }
      controller->bullets.push_back(entity);
    }
  }
}