
#include "RNGine/addons/destroyLimit.hpp"
#include <iostream>

void RNGine::Addons::checkLimitSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &limits = scene.GetComponents<RNGine::Addons::destroyLimit>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();

  auto max = limits.size();
  for (size_t i = 0; i < max; i++) {
    auto &limit = limits[i];
    auto &transform = transforms[i];
    if (!limit.has_value() || !transform.has_value())
      continue;
    if (transform->x < limit->minx || transform->x > limit->maxx) {
      scene.RemoveEntity(i);
    }
  }
}
