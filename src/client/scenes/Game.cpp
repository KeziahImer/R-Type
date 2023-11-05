#include "scenes/Game.hpp"
#include "RNGine/Core.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/SoundComponent.hpp"
#include "RNGine/components/Transform.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/CollisionWaveSpawn.hpp"
#include "Rtype/addons/CreateShips.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include "Rtype/addons/EnemyInfiniteSpawn.hpp"
#include "Rtype/addons/EnemyShoot.hpp"
#include "Rtype/addons/EnemyWaveSpawn.hpp"
#include "Rtype/addons/IsLoot.hpp"
#include "Rtype/addons/LootableEntity.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/PatternMovement.hpp"
#include "Rtype/addons/PatternShoot.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include "Rtype/addons/collisionInformation.hpp"
#include "Rtype/addons/enemyInformation.hpp"
#include "addons/ShipAnimation.hpp"
#include "addons/SpriteAnimation.hpp"
#include "components/Parallax.hpp"
#include "components/RenderTexture.hpp"
#include <string>
namespace r {
#include "raylib.h"
}
#include "Rtype/systems/CheckDamage.hpp"
#include "Rtype/systems/CheckHealth.hpp"
#include "Rtype/systems/CheckInvulnerability.hpp"
#include "Rtype/systems/CheckSolidCollider.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Client::Scenes::Game::Game(RNGine::Core &core) {

  CreateShipFactory();
  CreateEnemyFactory();
  CreateCollisionFactory();
  CreateEntity("background1");
  CreateEntity("background2");
  CreateEntity("background3");
  CreateEntity("background4");
  CreateEntity("weaponSlot");
  CreateEntity("powerupInventory");

  AddComponent<Client::Components::CollisionWaveSpawn>(
      CreateEntity("collisionWaveSpawn"),
      {11, 500, 5000, {COLLISION_TYPE_1, COLLISION_TYPE_2}});

  AddComponent<Client::Components::EnemySpawn>(
      CreateEntity("enemySpawn"),
      {1000, {ENEMY_TYPE_1, ENEMY_TYPE_2, ENEMY_TYPE_3, ENEMY_TYPE_4}});
  AddComponent<Client::Components::SendPacket>(CreateEntity("sender"), {});
  core.AddSystem("create-ship-factory", &Rtype::Addons::ShipFactorySystem);
  core.AddSystem("create-enemy-factory", &Rtype::Addons::EnemyFactorySystem);
  core.AddSystem("create-collision-factory",
                 &Rtype::Addons::CollisionFactorySystem);
  core.AddSystem("ship-controller", &Rtype::Addons::ShipControllerSystem);
  core.AddSystem("acceleration", &RNGine::Addons::AccelerationSystem);
  core.AddSystem("velocity", &RNGine::Addons::VelocitySystem);
  core.AddSystem("limits", &RNGine::Addons::LimitsSystem);
  core.AddSystem("collider", &RNGine::Addons::ColliderSystem);
  core.AddSystem("create-main-ship", &Client::Scenes::Game::CreateMainShip);
  core.AddSystem("move-ship", &Client::Scenes::Game::MoveShip);
  core.AddSystem("set-bullets-texture",
                 &Client::Scenes::Game::SetBulletsTexture);
  core.AddSystem("leave-scene", &Client::Scenes::Game::LeaveScene);
  core.AddSystem("parallax-system", &Client::Components::ParallaxSystem);
  core.AddSystem("check-damage", Client::Systems::CheckCollisionsDamage);
  core.AddSystem("check-solid-collider", Client::Systems::CheckSolidCollider);
  core.AddSystem("check-health", Client::Systems::CheckHealth);
  core.AddSystem("check-invulnerability",
                 Client::Systems::CheckInvulnerability);
  core.AddSystem("spawn-enemy-system-infinite",
                 &Client::Components::EnemySpawnSystem);
  core.AddSystem("spawn-collision-system",
                 &Client::Components::CollisionWaveSpawnSystem);
  core.AddSystem("check-limit-system", &RNGine::Addons::checkLimitSystem);
  core.AddSystem("shoot-enemy-system", &RNGine::Addons::EnemyShootSystem);
  core.AddSystem("loot-system", &Rtype::Addons::IsLootSystem);
  core.AddSystem("set-background-texture",
                 &Client::Scenes::Game::SetBackgroundTexture);
  core.AddSystem("set-weapon-Slot",
                 &Client::Scenes::Game::SetWeaponSlotTexture);
  core.AddSystem("set-powerup-inventory",
                 &Client::Scenes::Game::SetPowerupInventoryTexture);
  core.AddSystem("ship-animation-system", &Client::Addons::ShipAnimationSystem);
  core.AddSystem("pattern-movement-system",
                 &Rtype::Addons::PatternMovementSystem);
  core.AddSystem("pattern-shoot-system", &Rtype::Addons::PatternShootSystem);
  core.AddSystem("texture-enemy-system",
                 &Client::Scenes::Game::ApplyEnemyTexture);
  core.AddSystem("texture-ally-system",
                 &Client::Scenes::Game::ApplyShipTexture);
  core.AddSystem("texture-collision-system",
                 &Client::Scenes::Game::ApplyCollisionTexture);
  core.AddSystem("texture-loot-system", &Client::Scenes::Game::SetLootTexture);
  AddComponent<Client::Components::SoundComponent>(
      CreateEntity("musicSound"),
      {"./assets/sounds/music.mp3", true, true, false, 15});
}

void Client::Scenes::Game::CreateMainShip(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
  auto &factory =
      scene.GetComponents<Rtype::Addons::ShipFactory>()[scene.GetEntity(
          "ship-factory")];
  if (!factory.has_value())
    return;
  if (factory->ships.size() > 0)
    return;
  if (networkId.has_value())
    return;
  factory->creationRequests.push_back(
      Rtype::Addons::ShipCreationRequest::createShipCreationRequest(1, 100.0f,
                                                                    100.0f));
}

void Client::Scenes::Game::CreateEnemySystem(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &factory =
      scene.GetComponents<Rtype::Addons::EnemyFactory>()[scene.GetEntity(
          "enemy-factory")];
  if (!factory.has_value())
    return;
  if (factory->createdWave)
    return;
  for (int i = 0; i < 30; i++) {
    factory->creationRequests.push_back(
        Rtype::Addons::EnemyCreationRequest::createShipCreationRequest(
            i, 1920 + ((rand() % 1000 + 1) * i), rand() % 1000 + 1,
            ENEMY_TYPE_1, "enemy-test"));
  }
  factory->createdWave = true;
}

void Client::Scenes::Game::ApplyShipTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &shipFactory =
      scene.GetComponents<Rtype::Addons::ShipFactory>()[scene.GetEntity(
          "ship-factory")];
  if (!shipFactory.has_value())
    return;
  for (size_t i = 0; i < shipFactory->ships.size(); i++) {
    auto e = scene.GetEntity("ship-" + std::to_string(i + 1));
    auto alreadyExist =
        scene.GetComponents<Client::Components::RenderTexture>()[e];
    if (alreadyExist.has_value())
      continue;
    std::cout << "APPLY TEXTURE" << std::endl;
    float height = i * 17;
    scene.AddComponent<Client::Components::RenderTexture>(
        e, {"assets/players.gif", 10, {2 * 33, height, 33, 17}});
    scene.AddComponent<Client::Addons::ShipAnimation>(
        e, {Client::Addons::ShipAnimation::None});
  }
}

void Client::Scenes::Game::ApplyEnemyTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &enemyInfos = scene.GetComponents<Rtype::Components::enemyInformation>();
  for (int i = 0; i < enemyInfos.size(); i++) {
    auto &enemyInfo = enemyInfos[i];
    if (!enemyInfo.has_value())
      continue;
    std::string spritePath =
        std::get<std::string>(enemyInfo->informations["enemySpritePath"]);
    int zIndex = std::get<int>(enemyInfo->informations["zIndex"]);

    auto spriteRect = std::get<std::map<std::string, float>>(
        enemyInfo->informations["spriteRect"]);
    float x = spriteRect["x"];
    float y = spriteRect["y"];
    float width = spriteRect["width"];
    float height = spriteRect["height"];

    auto spriteAnimation =
        std::get<std::map<std::string, spriteAnimationValue>>(
            enemyInfo->informations["spriteAnimation"]);
    bool reverse = std::get<bool>(spriteAnimation["reverse"]);
    bool looping = std::get<bool>(spriteAnimation["looping"]);
    bool multiple = std::get<bool>(spriteAnimation["multiple"]);
    int startFrame = std::get<int>(spriteAnimation["startFrame"]);
    int endFrame = std::get<int>(spriteAnimation["endFrame"]);
    int stopFrame = std::get<int>(spriteAnimation["stopFrame"]);
    int frequence = std::get<int>(spriteAnimation["frequence"]);
    int lastUpdate = std::get<int>(spriteAnimation["lastUpdate"]);

    RNGine::Core::Time frequenceTime =
        static_cast<RNGine::Core::Time>(frequence);

    scene.AddComponent<Client::Components::RenderTexture>(
        i, {spritePath, zIndex, {x, y, width, height}});
    scene.AddComponent<Client::Components::SpriteAnimation>(i, {reverse,
                                                                looping,
                                                                multiple,
                                                                false,
                                                                {startFrame, 0},
                                                                {endFrame, 0},
                                                                {stopFrame, 0},
                                                                frequenceTime});
    scene.RemoveComponent<Rtype::Components::enemyInformation>(i);
  }
}

void Client::Scenes::Game::ApplyCollisionTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &factory =
      scene.GetComponents<Rtype::Addons::CollisionFactory>()[scene.GetEntity(
          "collision-factory")];
  if (!factory.has_value())
    return;
  auto &collisionInfos =
      scene.GetComponents<Rtype::Components::collisionInformation>();
  for (int i = 0; i < collisionInfos.size(); i++) {
    auto &collisionInfo = collisionInfos[i];
    if (!collisionInfo.has_value())
      continue;

    std::string spritePath = std::get<std::string>(
        collisionInfo->informations["collisionSpritePath"]);
    int zIndex = std::get<int>(collisionInfo->informations["zIndex"]);

    auto spriteRect = std::get<std::map<std::string, float>>(
        collisionInfo->informations["spriteRect"]);
    float x = spriteRect["x"];
    float y = spriteRect["y"];
    float width = spriteRect["width"];
    float height = spriteRect["height"];

    scene.AddComponent<Client::Components::RenderTexture>(
        i, {spritePath, zIndex, {x, y, width, height}});
    scene.RemoveComponent<Rtype::Components::collisionInformation>(i);
  }
}

void Client::Scenes::Game::MoveShip(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();
  auto &weaponSlot =
      scene.GetComponents<Client::Components::RenderTexture>()[scene.GetEntity(
          "weaponSlot")];
  auto &sender =
      scene.GetComponents<Client::Components::SendPacket>()[scene.GetEntity(
          "sender")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
  if (networkId.has_value()) {
    auto &ship =
        scene.GetComponents<Rtype::Addons::ShipController>()[scene.GetEntity(
            "ship-" + std::to_string(networkId->id))];
    auto &transform =
        scene.GetComponents<RNGine::Components::Transform>()[scene.GetEntity(
            "ship-" + std::to_string(networkId->id))];
    if (!ship.has_value())
      return;
    if (r::IsKeyPressed(r::KEY_UP)) {
      if (ship->movingUp == false && sender.has_value() &&
          networkId.has_value() && transform.has_value()) {
        sender->packets.push_back(
            {"MOVE_UP", std::to_string(networkId->id) +
                            ":TRUE:" + std::to_string(transform->x) + ":" +
                            std::to_string(transform->y)});
      }
      ship->movingUp = true;
    }
    if (r::IsKeyReleased(r::KEY_UP)) {
      if (ship->movingUp == true && sender.has_value() &&
          networkId.has_value()) {
        sender->packets.push_back(
            {"MOVE_UP", std::to_string(networkId->id) +
                            ":FALSE:" + std::to_string(transform->x) + ":" +
                            std::to_string(transform->y)});
      }
      ship->movingUp = false;
    }
    if (r::IsKeyPressed(r::KEY_DOWN)) {
      if (ship->movingDown == false && sender.has_value() &&
          networkId.has_value()) {
        sender->packets.push_back(
            {"MOVE_DOWN", std::to_string(networkId->id) +
                              ":TRUE:" + std::to_string(transform->x) + ":" +
                              std::to_string(transform->y)});
      }
      ship->movingDown = true;
    }
    if (r::IsKeyReleased(r::KEY_DOWN)) {
      if (ship->movingDown == true && sender.has_value() &&
          networkId.has_value()) {
        sender->packets.push_back(
            {"MOVE_DOWN", std::to_string(networkId->id) +
                              ":FALSE:" + std::to_string(transform->x) + ":" +
                              std::to_string(transform->y)});
      }
      ship->movingDown = false;
    }
    if (r::IsKeyPressed(r::KEY_LEFT)) {
      if (ship->movingLeft == false && sender.has_value() &&
          networkId.has_value()) {
        sender->packets.push_back(
            {"MOVE_LEFT", std::to_string(networkId->id) +
                              ":TRUE:" + std::to_string(transform->x) + ":" +
                              std::to_string(transform->y)});
      }
      ship->movingLeft = true;
    }
    if (r::IsKeyReleased(r::KEY_LEFT)) {
      if (ship->movingLeft == true && sender.has_value() &&
          networkId.has_value()) {
        sender->packets.push_back(
            {"MOVE_LEFT", std::to_string(networkId->id) +
                              ":FALSE:" + std::to_string(transform->x) + ":" +
                              std::to_string(transform->y)});
      }
      ship->movingLeft = false;
    }
    if (r::IsKeyPressed(r::KEY_RIGHT)) {
      if (ship->movingRight == false && sender.has_value() &&
          networkId.has_value()) {
        sender->packets.push_back(
            {"MOVE_RIGHT", std::to_string(networkId->id) +
                               ":TRUE:" + std::to_string(transform->x) + ":" +
                               std::to_string(transform->y)});
      }
      ship->movingRight = true;
    }
    if (r::IsKeyReleased(r::KEY_RIGHT)) {
      if (ship->movingRight == true && sender.has_value() &&
          networkId.has_value()) {
        sender->packets.push_back(
            {"MOVE_RIGHT", std::to_string(networkId->id) +
                               ":FALSE:" + std::to_string(transform->x) + ":" +
                               std::to_string(transform->y)});
      }
      ship->movingRight = false;
    }
    if (r::IsKeyPressed(r::KEY_SPACE)) {
      ship->shooting = true;
    }
    if (r::IsKeyReleased(r::KEY_SPACE)) {
      ship->shooting = false;
    }
    if (r::IsKeyPressed(r::KEY_R)) {
      ship->chargedAttack = true;
    }
    if (r::IsKeyReleased(r::KEY_R)) {
      ship->chargedAttack = false;
    }
    if (r::IsKeyPressed(r::KEY_F)) {
      int position = (static_cast<int>(ship->weapon) + 1) % 2;

      ship->weapon = static_cast<Rtype::Addons::WeaponType>(position);
      weaponSlot->source.x = static_cast<float>(position * 124);
    }
  } else {
    auto &ship =
        scene.GetComponents<Rtype::Addons::ShipController>()[scene.GetEntity(
            "ship-1")];
    if (!ship.has_value())
      return;
    if (r::IsKeyPressed(r::KEY_UP)) {
      ship->movingUp = true;
    }
    if (r::IsKeyReleased(r::KEY_UP)) {
      ship->movingUp = false;
    }
    if (r::IsKeyPressed(r::KEY_DOWN)) {
      ship->movingDown = true;
    }
    if (r::IsKeyReleased(r::KEY_DOWN)) {
      ship->movingDown = false;
    }
    if (r::IsKeyPressed(r::KEY_LEFT)) {
      ship->movingLeft = true;
    }
    if (r::IsKeyReleased(r::KEY_LEFT)) {
      ship->movingLeft = false;
    }
    if (r::IsKeyPressed(r::KEY_RIGHT)) {
      ship->movingRight = true;
    }
    if (r::IsKeyReleased(r::KEY_RIGHT)) {
      ship->movingRight = false;
    }
    if (r::IsKeyPressed(r::KEY_SPACE)) {
      ship->shooting = true;
    }
    if (r::IsKeyReleased(r::KEY_SPACE)) {
      ship->shooting = false;
    }
    if (r::IsKeyPressed(r::KEY_R)) {
      ship->chargedAttack = true;
    }
    if (r::IsKeyReleased(r::KEY_R)) {
      ship->chargedAttack = false;
    }
    if (r::IsKeyPressed(r::KEY_F)) {
      int position = (static_cast<int>(ship->weapon) + 1) % 2;

      ship->weapon = static_cast<Rtype::Addons::WeaponType>(position);
      weaponSlot->source.x = static_cast<float>(position * 124);
    }
  }
}

void Client::Scenes::Game::SetBackgroundTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "game")
    return;
  auto &scene = core.GetActualScene();

  auto background1 = scene.GetEntity("background1");
  auto background2 = scene.GetEntity("background2");
  auto background3 = scene.GetEntity("background3");
  auto background4 = scene.GetEntity("background4");

  auto alreadyExist1 =
      scene.GetComponents<Client::Components::RenderTexture>()[background1];
  auto alreadyExist2 =
      scene.GetComponents<Client::Components::RenderTexture>()[background2];
  auto alreadyExist3 =
      scene.GetComponents<Client::Components::RenderTexture>()[background3];
  auto alreadyExist4 =
      scene.GetComponents<Client::Components::RenderTexture>()[background4];

  if (!alreadyExist1.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background1, {"./assets/parallax100.png", -3, {0, 0, 514, 360}});
    scene.AddComponent<RNGine::Components::Transform>(background1,
                                                      {0, 0, 0, 3.73, 3});
    scene.AddComponent<Client::Components::Parallax>(background1,
                                                     {{-1920, 1920}});
    scene.AddComponent(background1, RNGine::Addons::Velocity({-100, 0}));
  }

  if (!alreadyExist2.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background2, {"./assets/parallax100.png", -3, {0, 0, 514, 360}});
    scene.AddComponent<RNGine::Components::Transform>(background2,
                                                      {1920, 0, 0, 3.73, 3});
    scene.AddComponent<Client::Components::Parallax>(background2,
                                                     {{-1920, 1920}});
    scene.AddComponent(background2, RNGine::Addons::Velocity({-100, 0}));
  }

  if (!alreadyExist3.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background3, {"./assets/parallax80.png", -2, {0, 0, 500, 500}});
    scene.AddComponent<RNGine::Components::Transform>(background3,
                                                      {0, 0, 0, 3.84, 2.16});
    scene.AddComponent<Client::Components::Parallax>(background3,
                                                     {{-1920, 1920}});
    scene.AddComponent(background3, RNGine::Addons::Velocity({-500, 0}));
  }

  if (!alreadyExist4.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background4, {"./assets/parallax80.png", -2, {0, 0, 500, 500}});
    scene.AddComponent<RNGine::Components::Transform>(background4,
                                                      {1920, 0, 0, 3.84, 2.16});
    scene.AddComponent<Client::Components::Parallax>(background4,
                                                     {{-1920, 1920}});
    scene.AddComponent(background4, RNGine::Addons::Velocity({-500, 0}));
  }
}

void Client::Scenes::Game::SetWeaponSlotTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();

  auto weaponSlot = scene.GetEntity("weaponSlot");

  auto alreadyExist =
      scene.GetComponents<Client::Components::RenderTexture>()[weaponSlot];

  if (!alreadyExist.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        weaponSlot, {"./assets/weaponSlots.png", 20, {0, 0, 124, 133}});
    scene.AddComponent<RNGine::Components::Transform>(
        weaponSlot, {0, 1080 - (133 * 0.8), 0, 0.8, 0.8});
  }
}

void Client::Scenes::Game::SetPowerupInventoryTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();

  auto weaponSlot = scene.GetEntity("powerupInventory");

  auto alreadyExist =
      scene.GetComponents<Client::Components::RenderTexture>()[weaponSlot];

  if (!alreadyExist.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        weaponSlot, {"./assets/powerupInventory.png", 20, {0, 0, 124, 123}});
    scene.AddComponent<RNGine::Components::Transform>(
        weaponSlot, {124 + 2, 1080 - (123 * 0.8), 0, 0.8, 0.8});
  }
}

void Client::Scenes::Game::SetBulletsTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto &scene = core.GetActualScene();

  auto &textures = scene.GetComponents<RNGine::Components::MakeDamage>();

  for (int i = 0; i < textures.size(); i++) {
    auto &texture = textures[i];
    if (!texture.has_value() || texture->printed)
      continue;
    scene.AddComponent<Client::Components::RenderTexture>(
        i, {texture->bulletSprite,
            1,
            {texture->sourceFirst.first, texture->sourceFirst.second,
             texture->sourceSecond.first, texture->sourceSecond.second}});

    // animation
    std::map<std::string, shootAnimationValue> animationValues =
        texture->shootAnimationValue;
    bool reverse = std::get<bool>(animationValues["reverse"]);
    bool loop = std::get<bool>(animationValues["loop"]);
    bool multiple = std::get<bool>(animationValues["multiple"]);
    bool finish = std::get<bool>(animationValues["finish"]);
    std::pair<int, int> start =
        std::get<std::pair<int, int>>(animationValues["start"]);
    std::pair<int, int> end =
        std::get<std::pair<int, int>>(animationValues["end"]);
    std::pair<int, int> lastFrame =
        std::get<std::pair<int, int>>(animationValues["lastFrame"]);
    RNGine::Core::Time frequence =
        std::get<RNGine::Core::Time>(animationValues["frequence"]);

    scene.AddComponent<Client::Components::SpriteAnimation>(
        i, {reverse, loop, multiple, finish, start, end, lastFrame, frequence});
    //
    texture->printed = true;
    if (texture->ally)
      scene.AddComponent<Client::Components::SoundComponent>(
          i,
          {texture->shootSound, true, false, false, texture->shootSoundVolume});
  }
}

void Client::Scenes::Game::LeaveScene(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;

  if (r::IsKeyReleased(r::KEY_BACKSPACE)) {
    core.AddScene("game", Client::Scenes::Game(core));
    core.SetActualScene("home");
  }
}

void Client::Scenes::Game::SetLootTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  auto &scene = core.GetActualScene();
  auto &loots = scene.GetComponents<Rtype::Addons::IsLoot>();
  for (int i = 0; i < loots.size(); i++) {
    if (!loots[i].has_value())
      continue;
    auto alreadyExist =
        scene.GetComponents<Client::Components::RenderTexture>()[i];
    if (alreadyExist.has_value())
      continue;
    if (loots[i]->type == Rtype::Components::ATTACKUP) {
      scene.AddComponent<Client::Components::RenderTexture>(
          i, {"./assets/level_up.png", 1, {0, 0, 480, 145}});
      scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, true, false, std::make_pair<int, int>(0, 0),
              std::make_pair<int, int>(2, 0), std::make_pair<int, int>(2, 0),
              200});
    }
    if (loots[i]->type == Rtype::Components::HEAL) {
      scene.AddComponent<Client::Components::RenderTexture>(
          i, {"./assets/healthLoot.png", 1, {0, 0, 16, 15}});
      scene.AddComponent<Client::Components::SpriteAnimation>(
          i, {false, false, true, false, std::make_pair<int, int>(0, 0),
              std::make_pair<int, int>(4, 0), std::make_pair<int, int>(4, 0),
              200});
    }
  }
}