#include "RNGine/RNGine.hpp"

#include <iostream>

void RNGine::Addons::AccelerationSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &accelerations = scene.GetComponents<RNGine::Addons::Acceleration>();
  auto &velocities = scene.GetComponents<RNGine::Addons::Velocity>();

  auto max = accelerations.size();
  for (size_t i = 0; i < max; i++) {
    auto acceleration = accelerations[i];
    auto &velocity = velocities[i];
    if (!acceleration.has_value() || !velocity.has_value())
      continue;

    velocity->x += acceleration->x * core.deltaTime;
    velocity->y += acceleration->y * core.deltaTime;
  }
}