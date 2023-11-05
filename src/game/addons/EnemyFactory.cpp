#include "Rtype/addons/EnemyFactory.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Collider.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/Attackable.hpp"
#include "RNGine/components/Damages.hpp"
#include "Rtype/addons/EnemyShoot.hpp"
#include "Rtype/addons/LootableEntity.hpp"
#include "Rtype/addons/MakeDamageBody.hpp"
#include "Rtype/addons/PatternMovement.hpp"
#include "Rtype/addons/PatternShoot.hpp"
#include "Rtype/addons/ShipController.hpp"
#include "Rtype/addons/WinConditionComponent.hpp"
#include "Rtype/addons/enemyInformation.hpp"
#include <iostream>

void Rtype::Addons::EnemyFactorySystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto entity = scene.GetEntity("enemy-factory");
  auto &factory = scene.GetComponents<EnemyFactory>()[entity];
  if (!factory.has_value())
    return;

  for (auto &request : factory->creationRequests) {
    auto ship = scene.CreateEntity(request.name);
    std::cout << "Enemy-" << std::to_string(factory->ships.size()) << std::endl;
    factory->ships.push_back(ship);

    auto info = request.enemyInfo.first;
    auto designInfo = request.enemyInfo.second;

    float positionY = std::get<float>(info["positionMob"]);

    scene.AddComponent<RNGine::Components::Transform>(
        ship,
        {request.x, (positionY == -1.0f ? request.y : positionY), 0,
         std::get<float>(info["width"]), std::get<float>(info["height"])});
    scene.AddComponent(
        ship, RNGine::Components::Hitbox({std::get<float>(info["hitboxWidth"]),
                                          std::get<float>(info["hitboxHeight"]),
                                          std::get<float>(info["originX"]),
                                          std::get<float>(info["originY"])}));

    std::pair<bool, RNGine::Addons::CollisionAction> colliderValue =
        std::get<std::pair<bool, RNGine::Addons::CollisionAction>>(
            info["collider"]);
    bool colliderBoolValue = colliderValue.first;
    RNGine::Addons::CollisionAction colliderActionValue = colliderValue.second;

    scene.AddComponent(ship, RNGine::Addons::Collider(
                                 {colliderBoolValue, colliderActionValue}));
    scene.AddComponent<RNGine::Addons::Velocity>(
        ship, {std::get<float>(info["velocityX"]),
               std::get<float>(info["velocityY"])});
    int attackableHealth =
        static_cast<int>(std::get<float>(info["attackableHealth"]));
    int attackableScore =
        static_cast<int>(std::get<float>(info["attackableScore"]));
    scene.AddComponent(
        ship, RNGine::Components::Attackable(
                  {attackableHealth, false, attackableScore, true, 150}));

    auto patternMovement = std::get<std::pair<
        int, std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                   std::pair<float, float>>>>>>(
        info["movementPattern"]);
    scene.AddComponent(
        ship, Rtype::Addons::PatternMovement({patternMovement.second.first,
                                              patternMovement.second.second,
                                              patternMovement.first}));
    auto patternShoot = std::get<std::pair<
        bool, std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>>(
        info["shootPattern"]);
    scene.AddComponent(ship, Rtype::Addons::PatternShoot(
                                 {patternShoot.first, patternShoot.second}));
    scene.AddComponent(ship, RNGine::Addons::destroyLimit({-100, 2020}));
    if (std::get<float>(info["winCondition"]) == 1.0f) {
      scene.AddComponent(ship, Rtype::Components::WinCondition({true}));
    }
    float damageBody = std::get<float>(info["makeDamages"]);
    if (damageBody > 0.0f) {
      scene.AddComponent(
          ship, RNGine::Components::MakeDamageBody({damageBody, false}));
    }

    // shoots
    RNGine::Core::Time enemyShootRate = static_cast<RNGine::Core::Time>(
        std::get<float>(info["enemyShootRate"]));
    auto velocityShootPair =
        std::get<std::pair<float, float>>(info["velocityShoot"]);
    auto destroyPositionShootPair =
        std::get<std::pair<float, float>>(info["destroyPositionShoot"]);
    auto offsetPositionShootPair =
        std::get<std::pair<float, float>>(info["offsetPositionShoot"]);
    auto scaleShootPair = std::get<std::pair<float, float>>(info["scaleShoot"]);
    auto hitboxFirstPair =
        std::get<std::pair<float, float>>(info["hitboxFirst"]);
    auto hitboxSecondPair =
        std::get<std::pair<float, float>>(info["hitboxSecond"]);
    std::string bulletSprite =
        std::get<std::string>(designInfo["bulletSpritePath"]);
    auto colliderShootPair =
        std::get<std::pair<bool, RNGine::Addons::CollisionAction>>(
            info["colliderShoot"]);
    auto shootSpriteRect =
        std::get<std::map<std::string, float>>(designInfo["spriteBulletRect"]);
    float shootRectX = shootSpriteRect["x"];
    float shootRectY = shootSpriteRect["y"];
    float shootRectWidth = shootSpriteRect["width"];
    float shootRectHeight = shootSpriteRect["height"];
    std::string bulletShootSound =
        std::get<std::string>(designInfo["bulletShootSound"]);
    float bulletShootSoundVolume =
        std::get<float>(designInfo["bulletShootSoundVolume"]);

    auto bulletAnimation = std::get<std::map<std::string, shootAnimationValue>>(
        designInfo["bulletAnimation"]);

    scene.AddComponent(
        ship,
        RNGine::Addons::EnemyShoot(
            {enemyShootRate,
             0,
             {velocityShootPair.first, velocityShootPair.second},
             {destroyPositionShootPair.first, destroyPositionShootPair.second},
             {offsetPositionShootPair.first, offsetPositionShootPair.second},
             {scaleShootPair.first, scaleShootPair.second},
             {hitboxFirstPair.first, hitboxFirstPair.second,
              hitboxSecondPair.first, hitboxSecondPair.second},
             bulletSprite,
             {colliderShootPair.first, colliderShootPair.second},
             {shootRectX, shootRectY},
             {shootRectWidth, shootRectHeight},
             bulletShootSound,
             bulletShootSoundVolume,
             bulletAnimation}));

    scene.AddComponent(
        ship, RNGine::Components::Damages({std::get<float>(info["damages"])}));
    scene.AddComponent(ship, Rtype::Components::LootableEntity());
    scene.AddComponent(
        ship, Rtype::Components::enemyInformation({request.enemyInfo.second}));
  }

  factory->creationRequests.clear();
}

Rtype::Addons::EnemyCreationRequest
Rtype::Addons::EnemyCreationRequest::createShipCreationRequest(
    int id, float x, float y,
    std::pair<std::map<std::string, ValueFirstMap>,
              std::map<std::string, Value>>
        enemyInfo,
    std::string name) {
  auto val = EnemyCreationRequest();
  val.id = id;
  val.x = x;
  val.y = y;
  val.enemyInfo = enemyInfo;
  val.name = name;
  return val;
}