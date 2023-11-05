/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_COLLISIONFACTORY_HPP_
#define _RTYPE_GAME_COMPONENTS_COLLISIONFACTORY_HPP_

#include "RNGine/Core.hpp"
#include "RNGine/RNGine.hpp"
#include "RNGine/Scene.hpp"
#include <variant>
#include <vector>

using ValueFirstMapCollision =
    std::variant<float, std::pair<bool, RNGine::Addons::CollisionAction>>;

using spriteAnimationValueCollision = std::variant<bool, int>;

using ValueCollision =
    std::variant<std::string, int, std::map<std::string, float>,
                 std::map<std::string, spriteAnimationValueCollision>>;

const std::pair<std::map<std::string, ValueFirstMapCollision>,
                std::map<std::string, ValueCollision>>
    COLLISION_TYPE_1 = {
        {
            {"width", 2.5f},
            {"height", 2.5f},
            {"velocityX", -400.0f},
            {"velocityY", 0.0f},
            {"positionCollision", -1.0f},
            {"hitboxWidth", 42.0f * 2.5f},
            {"hitboxHeight", 42.0f * 2.5f},
            {"originX", 0.0f},
            {"originY", 0.0f},
            {"collider",
             std::pair<bool, RNGine::Addons::CollisionAction>(
                 true, RNGine::Addons::CollisionAction::PushingForce)},
        }, // DESIGN
        {
            {"collisionSpritePath", "./assets/asteroid.png"},
            {"zIndex", 1},
            {"spriteRect", std::map<std::string, float>{{"x", 9.0f},
                                                        {"y", 11.0f},
                                                        {"width", 42.0f},
                                                        {"height", 42.0f}}},
        }};

const std::pair<std::map<std::string, ValueFirstMapCollision>,
                std::map<std::string, ValueCollision>>
    COLLISION_TYPE_2 = {
        {
            {"width", 3.5f},
            {"height", 3.5f},
            {"velocityX", -400.0f},
            {"velocityY", 0.0f},
            {"positionCollision", -1.0f},
            {"hitboxWidth", 49.0f * 3.5f},
            {"hitboxHeight", 44.0f * 3.5f},
            {"originX", 0.0f},
            {"originY", 0.0f},
            {"collider",
             std::pair<bool, RNGine::Addons::CollisionAction>(
                 true, RNGine::Addons::CollisionAction::PushingForce)},
        }, // DESIGN
        {
            {"collisionSpritePath", "./assets/asteroid.png"},
            {"zIndex", 1},
            {"spriteRect", std::map<std::string, float>{{"x", 320.0f},
                                                        {"y", 382.0f},
                                                        {"width", 49.0f},
                                                        {"height", 44.0f}}},
        }};

namespace Rtype {
namespace Addons {

struct CollisionCreationRequest {
  int id;
  float x;
  float y;
  std::pair<std::map<std::string, ValueFirstMapCollision>,
            std::map<std::string, ValueCollision>>
      collisionInfo;

  std::function<void(RNGine::Core &core, RNGine::Scene::Entity &collision,
                     std::map<std::string, ValueCollision> &collisionInfo)>
      onCreation;

  static CollisionCreationRequest createCollisionCreationRequest(
      int id, float x, float y,
      std::pair<std::map<std::string, ValueFirstMapCollision>,
                std::map<std::string, ValueCollision>>
          collisionInfo,
      std::function<void(RNGine::Core &core, RNGine::Scene::Entity &collision,
                         std::map<std::string, ValueCollision> &collisionInfo)>
          onCreation);
};

struct CollisionFactory {
  std::vector<CollisionCreationRequest> creationRequests;
  std::vector<RNGine::Scene::Entity> collisions;
  bool createdWave = false;
};

void CollisionFactorySystem(RNGine::Core &core);

std::pair<std::map<std::string, ValueFirstMapCollision>,
          std::map<std::string, ValueCollision>>
getCollisionTypeByString(std::string enemy);

std::string
getCollisionTypeString(std::pair<std::map<std::string, ValueFirstMapCollision>,
                                 std::map<std::string, ValueCollision>>
                           collision);

}; // namespace Addons
} // namespace Rtype

#endif