#include "scenes/Level5.hpp"
#include "RNGine/Core.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/SoundComponent.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/CollisionWaveSpawn.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include "Rtype/addons/EnemyInfiniteSpawn.hpp"
#include "Rtype/addons/EnemyShoot.hpp"
#include "Rtype/addons/EnemyWaveSpawn.hpp"
#include "Rtype/addons/IsLoot.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "Rtype/addons/PatternMovement.hpp"
#include "Rtype/addons/PatternShoot.hpp"
#include "Rtype/addons/winCondition.hpp"
#include "addons/ShipAnimation.hpp"
#include "addons/SpriteAnimation.hpp"
#include "components/Parallax.hpp"
#include "components/RenderTexture.hpp"
namespace r {
#include "raylib.h"
}
#include "Rtype/addons/SendPacket.hpp"
#include "Rtype/systems/CheckDamage.hpp"
#include "Rtype/systems/CheckHealth.hpp"
#include "Rtype/systems/CheckInvulnerability.hpp"
#include "Rtype/systems/CheckSolidCollider.hpp"
#include "scenes/Game.hpp"
#include "scenes/Home.hpp"
#include "scenes/Level1.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Client::Scenes::Level5::Level5(RNGine::Core &core) {
  CreateShipFactory();
  CreateEnemyFactory();
  CreateCollisionFactory();
  CreateEntity("background11");
  CreateEntity("background12");
  CreateEntity("background13");
  CreateEntity("background14");
  CreateEntity("background15");
  CreateEntity("background16");
  CreateEntity("powerupInventory");
  CreateEntity("weaponSlot");
  AddComponent<Client::Components::CollisionWaveSpawn>(
      CreateEntity("collisionWaveSpawn"),
      {11, 500, 5000, {COLLISION_TYPE_1, COLLISION_TYPE_2}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"),
      {8, 22, 800, {ENEMY_TYPE_1, ENEMY_TYPE_2}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"),
      {35, 20, 600, {ENEMY_TYPE_1, ENEMY_TYPE_2}});
  AddComponent<Client::Components::WinCondition>(CreateEntity("winCondition"),
                                                 {60});

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
  core.AddSystem("spawn-enemy-system",
                 &Client::Components::EnemyWaveSpawnSystem);
  core.AddSystem("spawn-collision-system",
                 &Client::Components::CollisionWaveSpawnSystem);
  core.AddSystem("check-limit-system", &RNGine::Addons::checkLimitSystem);
  core.AddSystem("shoot-enemy-system", &RNGine::Addons::EnemyShootSystem);
  core.AddSystem("loot-system", &Rtype::Addons::IsLootSystem);
  core.AddSystem("set-background-texture-level5",
                 &Client::Scenes::Level5::SetBackgroundTexture);
  core.AddSystem("set-weapon-Slot",
                 &Client::Scenes::Game::SetWeaponSlotTexture);
  core.AddSystem("ship-animation-system", &Client::Addons::ShipAnimationSystem);
  core.AddSystem("pattern-movement-system",
                 &Rtype::Addons::PatternMovementSystem);
  core.AddSystem("pattern-shoot-system", &Rtype::Addons::PatternShootSystem);
  core.AddSystem("winConditoon-system",
                 &Client::Components::WinConditionSystem);
  core.AddSystem("texture-enemy-system",
                 &Client::Scenes::Game::ApplyEnemyTexture);
  core.AddSystem("texture-collision-system",
                 &Client::Scenes::Game::ApplyCollisionTexture);
  core.AddSystem("texture-loot-system", &Client::Scenes::Game::SetLootTexture);
  AddComponent<Client::Components::SoundComponent>(
      CreateEntity("startSound"),
      {"./assets/sounds/start.wav", true, false, false});
  AddComponent<Client::Components::SoundComponent>(
      CreateEntity("musicSound"),
      {"./assets/sounds/joker-music.mp3", true, true, false, 80});
}

void Client::Scenes::Level5::SetBackgroundTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "Level5" && name != "Level6" && name != "Level7" &&
      name != "Level8")
    return;
  auto &scene = core.GetActualScene();

  auto background11 = scene.GetEntity("background11");
  auto background12 = scene.GetEntity("background12");
  auto background13 = scene.GetEntity("background13");
  auto background14 = scene.GetEntity("background14");
  auto background15 = scene.GetEntity("background15");
  auto background16 = scene.GetEntity("background16");
  auto background17 = scene.GetEntity("background17");
  auto background18 = scene.GetEntity("background18");
  auto background19 = scene.GetEntity("background19");
  auto background20 = scene.GetEntity("background20");

  auto alreadyExist11 =
      scene.GetComponents<Client::Components::RenderTexture>()[background11];
  auto alreadyExist12 =
      scene.GetComponents<Client::Components::RenderTexture>()[background12];
  auto alreadyExist13 =
      scene.GetComponents<Client::Components::RenderTexture>()[background13];
  auto alreadyExist14 =
      scene.GetComponents<Client::Components::RenderTexture>()[background14];
  auto alreadyExist15 =
      scene.GetComponents<Client::Components::RenderTexture>()[background15];
  auto alreadyExist16 =
      scene.GetComponents<Client::Components::RenderTexture>()[background16];
  auto alreadyExist17 =
      scene.GetComponents<Client::Components::RenderTexture>()[background17];
  auto alreadyExist18 =
      scene.GetComponents<Client::Components::RenderTexture>()[background18];
  auto alreadyExist19 =
      scene.GetComponents<Client::Components::RenderTexture>()[background19];
  auto alreadyExist20 =
      scene.GetComponents<Client::Components::RenderTexture>()[background20];

  auto fileName = "./assets/levels/red-space/nebulosa_red.png";

  if (name == "Level7" || name == "Level8")
    fileName = "./assets/levels/red-space/nebulosa_aqua_pink.png";
  if (!alreadyExist11.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background11, {fileName, -5, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background11,
                                                      {0, 0, 0, 1.001, 1.001});
    scene.AddComponent<Client::Components::Parallax>(background11,
                                                     {{-1920, 1920}});
    scene.AddComponent(background11, RNGine::Addons::Velocity({-100, 0}));
  }

  if (!alreadyExist12.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background12, {fileName, -5, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background12,
                                                      {1920, 0, 0, 1.001, 1.001});
    scene.AddComponent<Client::Components::Parallax>(background12,
                                                     {{-1920, 1920}});
    scene.AddComponent(background12, RNGine::Addons::Velocity({-100, 0}));
  }

  if (!alreadyExist13.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background13, {"./assets/levels/red-space/stars_small_1.png",
                       -4,
                       {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background13,
                                                      {0, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background13,
                                                     {{-1920, 1920}});
    scene.AddComponent(background13, RNGine::Addons::Velocity({-150, 0}));
  }

  if (!alreadyExist14.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background14, {"./assets/levels/red-space/stars_small_1.png",
                       -4,
                       {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background14,
                                                      {1920, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background14,
                                                     {{-1920, 1920}});
    scene.AddComponent(background14, RNGine::Addons::Velocity({-150, 0}));
  }

  if (!alreadyExist15.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background15, {"./assets/levels/red-space/stars_small_2.png",
                       -3,
                       {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background15,
                                                      {0, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background15,
                                                     {{-1920, 1920}});
    scene.AddComponent(background15, RNGine::Addons::Velocity({-200, 0}));
  }

  if (!alreadyExist16.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background16, {"./assets/levels/red-space/stars_small_2.png",
                       -3,
                       {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background16,
                                                      {1920, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background16,
                                                     {{-1920, 1920}});
    scene.AddComponent(background16, RNGine::Addons::Velocity({-200, 0}));
  }

  if (!alreadyExist17.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background17,
        {"./assets/levels/red-space/stars_big_1.png", -2, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background17,
                                                      {0, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background17,
                                                     {{-1920, 1920}});
    scene.AddComponent(background17, RNGine::Addons::Velocity({-250, 0}));
  }

  if (!alreadyExist18.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background18,
        {"./assets/levels/red-space/stars_big_1.png", -2, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background18,
                                                      {1920, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background18,
                                                     {{-1920, 1920}});
    scene.AddComponent(background18, RNGine::Addons::Velocity({-250, 0}));
  }

  if (!alreadyExist17.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background17,
        {"./assets/levels/red-space/stars_big_1.png", -2, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background17,
                                                      {0, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background17,
                                                     {{-1920, 1920}});
    scene.AddComponent(background17, RNGine::Addons::Velocity({-250, 0}));
  }

  if (!alreadyExist18.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background18,
        {"./assets/levels/red-space/stars_big_1.png", -2, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background18,
                                                      {1920, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background18,
                                                     {{-1920, 1920}});
    scene.AddComponent(background18, RNGine::Addons::Velocity({-250, 0}));
  }

  if (!alreadyExist19.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background19,
        {"./assets/levels/red-space/stars_big_2.png", -2, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background19,
                                                      {0, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background19,
                                                     {{-1920, 1920}});
    scene.AddComponent(background19, RNGine::Addons::Velocity({-250, 0}));
  }

  if (!alreadyExist20.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background20,
        {"./assets/levels/red-space/stars_big_2.png", -2, {0, 0, 1920, 1080}});
    scene.AddComponent<RNGine::Components::Transform>(background20,
                                                      {1920, 0, 0, 1.01, 1.01});
    scene.AddComponent<Client::Components::Parallax>(background20,
                                                     {{-1920, 1920}});
    scene.AddComponent(background20, RNGine::Addons::Velocity({-250, 0}));
  }
}