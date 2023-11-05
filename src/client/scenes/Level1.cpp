#include "scenes/Level1.hpp"
#include "RNGine/Core.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/SoundComponent.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/CollisionWaveSpawn.hpp"
#include "Rtype/addons/CreateShips.hpp"
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

Client::Scenes::Level1::Level1(RNGine::Core &core) {
  CreateShipFactory();
  CreateEnemyFactory();
  CreateCollisionFactory();
  CreateEntity("background1");
  CreateEntity("background2");
  CreateEntity("background3");
  CreateEntity("background4");
  CreateEntity("background5");
  CreateEntity("background6");
  CreateEntity("background7");
  CreateEntity("background8");
  CreateEntity("background9");
  CreateEntity("background10");
  CreateEntity("weaponSlot");
  AddComponent<Client::Components::CollisionWaveSpawn>(
      CreateEntity("collisionWaveSpawn"),
      {11, 500, 5000, {COLLISION_TYPE_1, COLLISION_TYPE_2}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"), {8, 22, 800, {ENEMY_TYPE_1}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"), {35, 20, 600, {ENEMY_TYPE_2}});
  AddComponent<Client::Components::WinCondition>(CreateEntity("winCondition"),
                                                 {60});

  AddComponent<Client::Components::SendPacket>(CreateEntity("sender"), {});
  core.AddSystem("create-ships", &Rtype::Addons::CreateShipsSystem);
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
  core.AddSystem("set-background-texture-level1",
                 &Client::Scenes::Level1::SetBackgroundTexture);
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
  core.AddSystem("texture-ally-system",
                 &Client::Scenes::Game::ApplyShipTexture);
  core.AddSystem("texture-collision-system",
                 &Client::Scenes::Game::ApplyCollisionTexture);
  core.AddSystem("texture-loot-system", &Client::Scenes::Game::SetLootTexture);
  AddComponent<Client::Components::SoundComponent>(
      CreateEntity("startSound"),
      {"./assets/sounds/start.wav", true, false, false});
  AddComponent<Client::Components::SoundComponent>(
      CreateEntity("musicSound"),
      {"./assets/sounds/music.mp3", true, true, false, 15});
}

void Client::Scenes::Level1::SetBackgroundTexture(RNGine::Core &core) {
  auto name = core.GetActualSceneName();
  if (name != "Level1" && name != "Level2" && name != "Level3" &&
      name != "Level4")
    return;
  auto &scene = core.GetActualScene();

  auto background1 = scene.GetEntity("background1");
  auto background2 = scene.GetEntity("background2");
  auto background3 = scene.GetEntity("background3");
  auto background4 = scene.GetEntity("background4");
  auto background5 = scene.GetEntity("background5");
  auto background6 = scene.GetEntity("background6");
  auto background7 = scene.GetEntity("background7");
  auto background8 = scene.GetEntity("background8");
  auto background9 = scene.GetEntity("background9");
  auto background10 = scene.GetEntity("background10");

  auto alreadyExist1 =
      scene.GetComponents<Client::Components::RenderTexture>()[background1];
  auto alreadyExist2 =
      scene.GetComponents<Client::Components::RenderTexture>()[background2];
  auto alreadyExist3 =
      scene.GetComponents<Client::Components::RenderTexture>()[background3];
  auto alreadyExist4 =
      scene.GetComponents<Client::Components::RenderTexture>()[background4];
  auto alreadyExist5 =
      scene.GetComponents<Client::Components::RenderTexture>()[background5];
  auto alreadyExist6 =
      scene.GetComponents<Client::Components::RenderTexture>()[background6];
  auto alreadyExist7 =
      scene.GetComponents<Client::Components::RenderTexture>()[background7];
  auto alreadyExist8 =
      scene.GetComponents<Client::Components::RenderTexture>()[background8];
  auto alreadyExist9 =
      scene.GetComponents<Client::Components::RenderTexture>()[background9];
  auto alreadyExist10 =
      scene.GetComponents<Client::Components::RenderTexture>()[background10];

  if (!alreadyExist1.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background1, {"./assets/levels/city/background/background_city1.png",
                      -5,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background1,
                                                      {0, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background1,
                                                     {{-1920, 1920}});
    scene.AddComponent(background1, RNGine::Addons::Velocity({-100, 0}));
  }

  if (!alreadyExist2.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background2, {"./assets/levels/city/background/background_city1.png",
                      -5,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background2,
                                                      {1920, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background2,
                                                     {{-1920, 1920}});
    scene.AddComponent(background2, RNGine::Addons::Velocity({-100, 0}));
  }

  if (!alreadyExist3.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background3, {"./assets/levels/city/background/background_city2.png",
                      -4,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background3,
                                                      {0, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background3,
                                                     {{-1920, 1920}});
    scene.AddComponent(background3, RNGine::Addons::Velocity({-500, 0}));
  }

  if (!alreadyExist4.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background4, {"./assets/levels/city/background/background_city2.png",
                      -4,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background4,
                                                      {1920, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background4,
                                                     {{-1920, 1920}});
    scene.AddComponent(background4, RNGine::Addons::Velocity({-500, 0}));
  }
  if (!alreadyExist5.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background5, {"./assets/levels/city/background/background_city3.png",
                      -3,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background5,
                                                      {0, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background5,
                                                     {{-1920, 1920}});
    scene.AddComponent(background5, RNGine::Addons::Velocity({-750, 0}));
  }

  if (!alreadyExist6.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background6, {"./assets/levels/city/background/background_city3.png",
                      -3,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background6,
                                                      {1920, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background6,
                                                     {{-1920, 1920}});
    scene.AddComponent(background6, RNGine::Addons::Velocity({-750, 0}));
  }
  if (!alreadyExist7.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background7, {"./assets/levels/city/background/background_city4.png",
                      -2,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background7,
                                                      {0, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background7,
                                                     {{-1920, 1920}});
    scene.AddComponent(background7, RNGine::Addons::Velocity({-1000, 0}));
  }

  if (!alreadyExist8.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background8, {"./assets/levels/city/background/background_city4.png",
                      -2,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background8,
                                                      {1920, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background8,
                                                     {{-1920, 1920}});
    scene.AddComponent(background8, RNGine::Addons::Velocity({-1000, 0}));
  }
  if (!alreadyExist9.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background9, {"./assets/levels/city/background/background_city5.png",
                      -1,
                      {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background9,
                                                      {0, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background9,
                                                     {{-1920, 1920}});
    scene.AddComponent(background9, RNGine::Addons::Velocity({-1250, 0}));
  }

  if (!alreadyExist10.has_value()) {
    scene.AddComponent<Client::Components::RenderTexture>(
        background10, {"./assets/levels/city/background/background_city5.png",
                       -1,
                       {0, 0, 576, 324}});
    scene.AddComponent<RNGine::Components::Transform>(background10,
                                                      {1920, 0, 0, 3.34, 3.34});
    scene.AddComponent<Client::Components::Parallax>(background10,
                                                     {{-1920, 1920}});
    scene.AddComponent(background10, RNGine::Addons::Velocity({-1250, 0}));
  }
}