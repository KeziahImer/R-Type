#include "Rtype/addons/ShipController.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/Damages.hpp"
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include <iostream>
#include <string>

void Rtype::Addons::ShipControllerSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &controllers = scene.GetComponents<ShipController>();
  auto &accelerations = scene.GetComponents<RNGine::Addons::Acceleration>();
  auto &velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &limits = scene.GetComponents<RNGine::Addons::Limits>();
  auto &hitboxs = scene.GetComponents<RNGine::Components::Hitbox>();
  auto &damages = scene.GetComponents<RNGine::Components::Damages>();
  auto &isNetwork =
      scene.GetComponents<Rtype::Components::IsNetwork>()[scene.GetEntity(
          "network")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
  auto &sender =
      scene.GetComponents<Client::Components::SendPacket>()[scene.GetEntity(
          "sender")];

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

    if (!controller->chargedAttack && controller->charging != 0) {
      if (!hitboxs[i].has_value())
        continue;
      auto entity = scene.CreateEntity();
      scene.AddComponent(
          entity, RNGine::Addons::Collider(
                      {false, RNGine::Addons::CollisionAction::Explosion}));
      scene.AddComponent(entity, RNGine::Addons::Velocity({1200, 0}));
      scene.AddComponent<RNGine::Addons::destroyLimit>(entity, {-100, 2020});
      if (controller->charging < 1) {
        if (!isNetwork.has_value() && sender.has_value() &&
            networkId.has_value()) {
          sender->packets.push_back(
              {"SHOOT", std::to_string(networkId->id) + ":" + "1:CHARGED"});
        }
        scene.AddComponent<RNGine::Components::Transform>(
            entity, {transform->x + hitboxs[i]->width, transform->y, 0, 2, 2});
        scene.AddComponent(entity,
                           RNGine::Components::Hitbox({33 * 2, 33 * 2, 0, 0}));
        scene.AddComponent<RNGine::Components::MakeDamage>(
            entity, {damages[i]->damages, true, i});
      } else if (controller->charging < 2) {
        if (!isNetwork.has_value() && sender.has_value() &&
            networkId.has_value()) {
          sender->packets.push_back(
              {"SHOOT", std::to_string(networkId->id) + ":" + "2:CHARGED"});
        }
        scene.AddComponent<RNGine::Components::Transform>(
            entity, {transform->x + hitboxs[i]->width, transform->y, 0, 3, 3});
        scene.AddComponent(entity,
                           RNGine::Components::Hitbox({33 * 3, 33 * 3, 0, 0}));
        scene.AddComponent<RNGine::Components::MakeDamage>(
            entity, {damages[i]->damages * 2, true, i});
      } else if (controller->charging < 3) {
        if (!isNetwork.has_value() && sender.has_value() &&
            networkId.has_value()) {
          sender->packets.push_back(
              {"SHOOT", std::to_string(networkId->id) + ":" + "3:CHARGED"});
        }
        scene.AddComponent<RNGine::Components::Transform>(
            entity,
            {transform->x + hitboxs[i]->width, transform->y, 0, 4.5, 4.5});
        scene.AddComponent(
            entity, RNGine::Components::Hitbox({33 * 4.5, 33 * 4.5, 0, 0}));
        scene.AddComponent<RNGine::Components::MakeDamage>(
            entity, {damages[i]->damages * 3, true, i});
      } else {
        if (!isNetwork.has_value() && sender.has_value() &&
            networkId.has_value()) {
          sender->packets.push_back(
              {"SHOOT", std::to_string(networkId->id) + ":" + "4:CHARGED"});
        }
        scene.AddComponent<RNGine::Components::Transform>(
            entity, {transform->x + hitboxs[i]->width, transform->y, 0, 6, 6});
        scene.AddComponent(entity,
                           RNGine::Components::Hitbox({33 * 6, 33 * 6, 0, 0}));
        scene.AddComponent<RNGine::Components::MakeDamage>(
            entity, {damages[i]->damages * 4, true, i});
      }
      controller->bullets.push_back(entity);
      controller->charging = 0;
    }
    if (controller->chargedAttack) {
      controller->charging += core.deltaTime;
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
        if (!isNetwork.has_value() && sender.has_value() &&
            networkId.has_value()) {
          sender->packets.push_back(
              {"SHOOT", std::to_string(networkId->id) + ":" + "BASIC"});
        }
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
        if (!isNetwork.has_value() && sender.has_value() &&
            networkId.has_value()) {
          sender->packets.push_back(
              {"SHOOT", std::to_string(networkId->id) + ":" + "LASER"});
        }
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