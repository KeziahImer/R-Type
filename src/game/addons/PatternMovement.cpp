#include "Rtype/addons/PatternMovement.hpp"
#include <iostream>

void Rtype::Addons::PatternMovementSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &patterns = scene.GetComponents<Rtype::Addons::PatternMovement>();
  auto &velocities = scene.GetComponents<RNGine::Addons::Velocity>();
  auto deltaTime = core.deltaTime;

  auto max = patterns.size();
  for (size_t i = 0; i < max; i++) {
    auto &pattern = patterns[i];
    auto &velocity = velocities[i];
    if (!pattern.has_value() || !velocity.has_value())
      continue;
    if (pattern->end)
      continue;
    pattern->lastUpdate = pattern->lastUpdate + deltaTime;
    if (pattern->lastUpdate < pattern->pattern[pattern->index].first)
      continue;
    pattern->lastUpdate = 0;
    pattern->index += 1;
    if (pattern->index == pattern->pattern.size()) {
      if (!pattern->loop) {
        pattern->end = true;
        break;
      } else
        pattern->index = pattern->loopFrames;
    }
    velocity->x = pattern->pattern[pattern->index].second.first;
    velocity->y = pattern->pattern[pattern->index].second.second;
  }
}