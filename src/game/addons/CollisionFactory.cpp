#include "Rtype/addons/CollisionFactory.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Collider.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/Attackable.hpp"
#include "RNGine/components/Damages.hpp"
#include "Rtype/addons/EnemyShoot.hpp"
#include "Rtype/addons/LootableEntity.hpp"
#include "Rtype/addons/PatternMovement.hpp"
#include "Rtype/addons/PatternShoot.hpp"
#include "Rtype/addons/ShipController.hpp"
#include "Rtype/addons/collisionInformation.hpp"

#include <iostream>

void Rtype::Addons::CollisionFactorySystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto entity = scene.GetEntity("collision-factory");
  auto &factory = scene.GetComponents<CollisionFactory>()[entity];
  if (!factory.has_value())
    return;

  for (auto &request : factory->creationRequests) {
    auto collision =
        scene.CreateEntity("collision-" + std::to_string(request.id));
    factory->collisions.push_back(collision);

    auto info = request.collisionInfo.first;
    auto designInfo = request.collisionInfo.second;

    float positionY = std::get<float>(info["positionCollision"]);

    scene.AddComponent<RNGine::Components::Transform>(
        collision,
        {request.x, (positionY == -1.0f ? request.y : positionY), 0,
         std::get<float>(info["width"]), std::get<float>(info["height"])});
    scene.AddComponent(collision, RNGine::Components::Hitbox(
                                      {std::get<float>(info["hitboxWidth"]),
                                       std::get<float>(info["hitboxHeight"]),
                                       std::get<float>(info["originX"]),
                                       std::get<float>(info["originY"])}));
    std::pair<bool, RNGine::Addons::CollisionAction> colliderValue =
        std::get<std::pair<bool, RNGine::Addons::CollisionAction>>(
            info["collider"]);
    bool colliderBoolValue = colliderValue.first;
    RNGine::Addons::CollisionAction colliderActionValue = colliderValue.second;

    scene.AddComponent(
        collision,
        RNGine::Addons::Collider({colliderBoolValue, colliderActionValue}));
    scene.AddComponent<RNGine::Addons::Velocity>(
        collision, {std::get<float>(info["velocityX"]),
                    std::get<float>(info["velocityY"])});
    scene.AddComponent(collision, RNGine::Addons::destroyLimit({-200, 2020}));
    scene.AddComponent(collision, Rtype::Components::collisionInformation(
                                      {request.collisionInfo.second}));
  }

  factory->creationRequests.clear();
}

std::pair<std::map<std::string, ValueFirstMapCollision>,
          std::map<std::string, ValueCollision>>
Rtype::Addons::getCollisionTypeByString(std::string enemy) {
  if (enemy == "collsion_1")
    return COLLISION_TYPE_1;
  if (enemy == "collision_2")
    return COLLISION_TYPE_2;
  return COLLISION_TYPE_1;
}

std::string Rtype::Addons::getCollisionTypeString(
    std::pair<std::map<std::string, ValueFirstMapCollision>,
              std::map<std::string, ValueCollision>>
        collision) {
  if (collision == COLLISION_TYPE_1)
    return "collision_1";
  if (collision == COLLISION_TYPE_1)
    return "collision_2";
  return "collision_1";
}

Rtype::Addons::CollisionCreationRequest
Rtype::Addons::CollisionCreationRequest::createCollisionCreationRequest(
    int id, float x, float y,
    std::pair<std::map<std::string, ValueFirstMapCollision>,
              std::map<std::string, ValueCollision>>
        collisionInfo,
    std::function<void(RNGine::Core &core, RNGine::Scene::Entity &collision,
                       std::map<std::string, ValueCollision> &collisionInfo)>
        onCreation) {
  auto val = CollisionCreationRequest();
  val.id = id;
  val.x = x;
  val.y = y;
  val.collisionInfo = collisionInfo;
  val.onCreation = onCreation;
  return val;
}