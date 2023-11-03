/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** CheckSolidCollider
*/

#include "systems/CheckSolidCollider.hpp"
#include "RNGine/addons/Collider.hpp"
#include "components/SoundComponent.hpp"
#include <iostream>

void PushingForce(RNGine::Core &core, size_t i, size_t col) {
  auto &scene = core.GetActualScene();
  auto &Collisions = scene.GetComponents<RNGine::Addons::Collider>();
  auto &Velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &Transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &Hitboxes = scene.GetComponents<RNGine::Components::Hitbox>();

  if (Collisions[col].has_value() && !Collisions[col]->solidCollider &&
      Velocities[col].has_value() && Velocities[i].has_value() &&
      Transforms[col].has_value()) {
    if (Collisions[col]->action ==
        RNGine::Addons::CollisionAction::PushingForce) {
      scene.AddComponent<Client::Components::SoundComponent>(
          i, {"./assets/sounds/collision.wav", true, false, false});
      if (Transforms[col]->x > Transforms[i]->x &&
          Transforms[col]->x + Hitboxes[col]->width <
              Transforms[i]->x + Hitboxes[i]->width) {
        if (Transforms[col]->y >= Transforms[i]->y) {
          Transforms[col]->y = Transforms[i]->y - 40;
        } else {
          Transforms[col]->y = Transforms[i]->y + Hitboxes[i]->height + 10;
        }
      } else {
        if (Transforms[col]->x <= Transforms[i]->x) {
          Transforms[col]->x = Transforms[i]->x - Hitboxes[col]->width - 10;
        } else {
          Transforms[col]->x = Transforms[i]->x + Hitboxes[i]->width + 20;
        }
      }
      Collisions[i]->collisions.clear();
      Collisions[col]->collisions.clear();
    }
  }
}

void BulletExplode(RNGine::Core &core, size_t i, size_t col) {
  auto &scene = core.GetActualScene();
  auto &Collisions = scene.GetComponents<RNGine::Addons::Collider>();
  auto &Velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &Transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &Hitboxes = scene.GetComponents<RNGine::Components::Hitbox>();

  if (Collisions[col].has_value() && !Collisions[col]->solidCollider &&
      Velocities[col].has_value() && Velocities[i].has_value() &&
      Transforms[col].has_value()) {
    if (Collisions[col]->action == RNGine::Addons::CollisionAction::Explosion) {
      Collisions[i]->collisions.clear();
      Collisions[col]->collisions.clear();
      scene.RemoveEntity(col);
    }
  }
}

void Client::Systems::CheckSolidCollider(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &Collisions = scene.GetComponents<RNGine::Addons::Collider>();
  auto &Velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &Transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &Hitboxes = scene.GetComponents<RNGine::Components::Hitbox>();

  for (size_t i = 0; i < Collisions.size(); i++) {
    if (!Collisions[i].has_value() || !Velocities[i].has_value() ||
        !Transforms[i].has_value() || !Hitboxes[i].has_value())
      continue;
    if (!Collisions[i]->solidCollider)
      continue;

    for (auto col : Collisions[i]->collisions) {
      PushingForce(core, i, col);
      BulletExplode(core, i, col);
    }
  }
}
