#include "Rtype/addons/PatternShoot.hpp"
#include <iostream>

void Rtype::Addons::PatternShootSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &patterns = scene.GetComponents<Rtype::Addons::PatternShoot>();
  auto &bullets = scene.GetComponents<RNGine::Addons::EnemyShoot>();
  auto deltaTime = core.deltaTime;

  auto max = patterns.size();
  for (size_t i = 0; i < max; i++) {
    auto &pattern = patterns[i];
    auto &bullet = bullets[i];
    if (!pattern.has_value() || !bullet.has_value())
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
        pattern->index = 0;
    }
    bullet->frequence = pattern->pattern[pattern->index].second.first;
    bullet->velocity.x = pattern->pattern[pattern->index].second.second.first;
    bullet->velocity.y = pattern->pattern[pattern->index].second.second.second;
  }
}