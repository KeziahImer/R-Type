#ifndef _RTYPE_ENGINE_ADDONS_COLLIDER_HPP_
#define _RTYPE_ENGINE_ADDONS_COLLIDER_HPP_

#include <vector>

#include "../Core.hpp"
#include "../Scene.hpp"
#include "RNGine/components/Hitbox.hpp"
#include "RNGine/components/Transform.hpp"

namespace RNGine {
namespace Addons {

enum class CollisionAction { None, PushingForce, Explosion };

struct Collider {
  bool solidCollider = false;
  CollisionAction action = CollisionAction::None;
  std::vector<RNGine::Scene::Entity> collisions;
};

struct CollisionData {
  Collider collider;
  RNGine::Components::Hitbox hitbox;
  RNGine::Components::Transform transform;
};

void ColliderSystem(RNGine::Core &core);

}; // namespace Addons
} // namespace RNGine

#endif
