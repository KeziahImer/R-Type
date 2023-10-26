#include "RNGine/RNGine.hpp"

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
  auto &hitboxes = scene.GetComponents<RNGine::Components::Hitbox>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();

  std::map<RNGine::Scene::Entity, CollisionData> collisionsData;

  auto max = colliders.size();
  for (size_t i = 0; i < max; i++) {
    auto collider = colliders[i];
    auto hitbox = hitboxes[i];
    auto transform = transforms[i];
    if (!collider.has_value() || !hitbox.has_value() || !transform.has_value())
      continue;

    collider->collisions.clear();

    for (auto collisionData : collisionsData) {
      auto collision = collisionData.second;
      if (checkCollision(hitbox.value(), transform.value(), collision.hitbox,
                         collision.transform)) {
        collider->collisions.push_back(collisionData.first);
        collisionData.second.collider.collisions.push_back(i);
      }
    }
  }
}
