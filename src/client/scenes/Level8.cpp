#include "scenes/Level8.hpp"
#include "RNGine/Core.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/EnemyShoot.hpp"
#include "RNGine/addons/Velocity.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/MakeDamage.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include "Rtype/addons/IsLoot.hpp"
#include "Rtype/addons/PatternMovement.hpp"
#include "Rtype/addons/PatternShoot.hpp"
#include "addons/CollisionWaveSpawn.hpp"
#include "addons/EnemyInfiniteSpawn.hpp"
#include "addons/EnemyWaveSpawn.hpp"
#include "addons/ShipAnimation.hpp"
#include "addons/SpriteAnimation.hpp"
#include "components/Parallax.hpp"
#include "components/RenderTexture.hpp"
#include "components/SoundComponent.hpp"
namespace r
{
#include "raylib.h"
}
#include "scenes/Game.hpp"
#include "scenes/Home.hpp"
#include "scenes/Level1.hpp"
#include "systems/CheckDamage.hpp"
#include "systems/CheckHealth.hpp"
#include "systems/CheckInvulnerability.hpp"
#include "systems/CheckSolidCollider.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Client::Scenes::Level8::Level8(RNGine::Core &core) {
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
      CreateEntity("enemyWaveSpawn"),
      {8, 22, 800, {ENEMY_TYPE_3, ENEMY_TYPE_4}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"),
      {35, 20, 600, {ENEMY_TYPE_3, ENEMY_TYPE_4}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"), {60, 1, 1500, {BOSS_TYPE_1}});

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
  AddComponent<Client::Components::SoundComponent>(
      CreateEntity("startSound"),
      {"./assets/sounds/start.wav", true, false, false});
  AddComponent<Client::Components::SoundComponent>(
      CreateEntity("musicSound"),
      {"./assets/sounds/music.mp3", true, true, false, 15});
}