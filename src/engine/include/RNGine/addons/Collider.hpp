/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_ENGINE_ADDONS_COLLIDER_HPP_
#define _RTYPE_ENGINE_ADDONS_COLLIDER_HPP_

#include <vector>

#include "../Core.hpp"
#include "../Scene.hpp"

namespace RNGine {
namespace Addons {
struct Collider {
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