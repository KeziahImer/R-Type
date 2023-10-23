#include "RNGine/RNGine.hpp"
#include <iostream>

void RNGine::Addons::VelocitySystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();

  auto max = velocities.size();
  for (size_t i = 0; i < max; i++) {
    auto velocity = velocities[i];
    auto &transform = transforms[i];
    if (!velocity.has_value() || !transform.has_value())
      continue;

    transform->x += velocity->x * core.deltaTime;
    transform->y += velocity->y * core.deltaTime;
  }
}