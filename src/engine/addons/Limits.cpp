#include "RNGine/RNGine.hpp"

#include <iostream>

void RNGine::Addons::LimitsSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &limits = scene.GetComponents<RNGine::Addons::Limits>();
  auto &accelerations = scene.GetComponents<RNGine::Addons::Acceleration>();
  auto &velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();

  auto max = velocities.size();
  for (size_t i = 0; i < max; i++) {
    auto limit = limits[i];
    auto &acceleration = accelerations[i];
    auto &velocity = velocities[i];
    auto &transform = transforms[i];
    if (!limit.has_value() || !transform.has_value())
      continue;

    if (transform->x < limit->minX) {
      transform->x = limit->minX;
      velocity->x = 0;
      acceleration->x = 0;
    }
    if (transform->x > limit->maxX) {
      transform->x = limit->maxX;
      velocity->x = 0;
      acceleration->x = 0;
    }
    if (transform->y < limit->minY) {
      transform->y = limit->minY;
      velocity->y = 0;
      acceleration->y = 0;
    }
    if (transform->y > limit->maxY) {
      transform->y = limit->maxY;
      velocity->y = 0;
      acceleration->y = 0;
    }

    if (!velocity.has_value())
      continue;

    if (velocity->x > limit->maxVX) {
      velocity->x = limit->maxVX;
      acceleration->y = 0;
    }
    if (velocity->x < limit->minVX) {
      velocity->x = limit->minVX;
      acceleration->y = 0;
    }
    if (velocity->y > limit->maxVY) {
      velocity->y = limit->maxVY;
      acceleration->y = 0;
    }
    if (velocity->y < limit->minVY) {
      velocity->y = limit->minVY;
      acceleration->y = 0;
    }

    if (!acceleration.has_value())
      continue;

    if (acceleration->x > limit->maxAX) {
      acceleration->x = limit->maxAX;
    }
    if (acceleration->x < limit->minAX) {
      acceleration->x = limit->minAX;
    }
    if (acceleration->y > limit->maxAY) {
      acceleration->y = limit->maxAY;
    }
    if (acceleration->y < limit->minAY) {
      acceleration->y = limit->minAY;
    }
  }
}