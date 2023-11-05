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
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/MakeDamage.hpp"
#include "Rtype/addons/PatternMovement.hpp"
#include "Rtype/addons/PatternShoot.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include "Rtype/addons/winCondition.hpp"
#include "Rtype/systems/CheckDamage.hpp"
#include "Rtype/systems/CheckHealth.hpp"
#include "Rtype/systems/CheckInvulnerability.hpp"
#include "Rtype/systems/CheckSolidCollider.hpp"
#include "scenes/Game.hpp"
#include "scenes/Level1.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Server::Scenes::Level1::Level1(RNGine::Core &core) {
  CreateShipFactory();
  CreateEnemyFactory();
  CreateCollisionFactory();
  AddComponent<Client::Components::SendPacket>(CreateEntity("sender"), {});
  AddComponent<Rtype::Components::IsNetwork>(CreateEntity("network"), {true});
  AddComponent<Client::Components::CollisionWaveSpawn>(
      CreateEntity("collisionWaveSpawn"),
      {11, 500, 5000, {COLLISION_TYPE_1, COLLISION_TYPE_2}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn"), {8, 22, 800, {ENEMY_TYPE_1}});
  AddComponent<Client::Components::EnemyWaveSpawn>(
      CreateEntity("enemyWaveSpawn1"), {35, 20, 600, {ENEMY_TYPE_2}});
  AddComponent<Client::Components::WinCondition>(CreateEntity("winCondition"),
                                                 {60});
  AddComponent<Rtype::Addons::CreateShips>(CreateEntity("createShips"), {0});
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
  core.AddSystem("pattern-movement-system",
                 &Rtype::Addons::PatternMovementSystem);
  core.AddSystem("pattern-shoot-system", &Rtype::Addons::PatternShootSystem);
  core.AddSystem("winConditoon-system",
                 &Client::Components::WinConditionSystem);
}