#include "RNGine/addons/Collider.hpp"
#include "RNGine/RNGine.hpp"
#include <iostream>
#include <ostream>

bool checkCollision(const RNGine::Components::Hitbox &hitbox1,
                    const RNGine::Components::Transform &transform1,
                    const RNGine::Components::Hitbox &hitbox2,
                    const RNGine::Components::Transform &transform2) {
  auto x1 = transform1.x;
  auto y1 = transform1.y;
  auto x2 = transform2.x;
  auto y2 = transform2.y;
  auto w1 = hitbox1.width;
  auto h1 = hitbox1.height;
  auto w2 = hitbox2.width;
  auto h2 = hitbox2.height;

  if (x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2)
    return true;
  return false;
}

void RNGine::Addons::ColliderSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &colliders = scene.GetComponents<RNGine::Addons::Collider>();
  auto &Hitboxs = scene.GetComponents<RNGine::Components::Hitbox>();
  auto &Transforms = scene.GetComponents<RNGine::Components::Transform>();

  auto max = colliders.size();
  for (size_t i = 0; i < max; i++) {
    auto collision = colliders[i];
    if (!collision.has_value())
      continue;
    collision->collisions.clear();
  }

  for (size_t i = 0; i < max; i++) {
    for (size_t x = 0; x < max; x++) {
      auto &collision = colliders[i];
      auto &collision1 = colliders[x];
      if (!collision.has_value() || i == x || !collision1.has_value() ||
          !Hitboxs[i].has_value() || !Hitboxs[x].has_value() ||
          !Transforms[i].has_value() || !Transforms[x].has_value())
        continue;

      if (checkCollision(*Hitboxs[i], *Transforms[i], *Hitboxs[x],
                         *Transforms[x])) {
        collision->collisions.push_back(x);
        collision1->collisions.push_back(i);
      }
    }
  }
}
