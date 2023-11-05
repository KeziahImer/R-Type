#include "scenes/Level6.hpp"
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
#include "scenes/Level5.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Client::Scenes::Level6::Level6(RNGine::Core &core) {
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
      {5, 500, 2500, {COLLISION_TYPE_1, COLLISION_TYPE_2}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"),
      {8, 90, 800, {ENEMY_TYPE_1, ENEMY_TYPE_2}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"), {1, 1, 1500, {BOSS_TYPE_2_HEAD}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"), {2, 10, 201, {BOSS_TYPE_2_BODY}});
  AddComponent<Client::Components::WinCondition>(CreateEntity("winCondition"),
                                                 {100, false});

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
