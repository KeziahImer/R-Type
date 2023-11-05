#include "Rtype/addons/CollisionWaveSpawn.hpp"
#include "RNGine/Scene.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include <iostream>
#include <random>
#include <string>

void Client::Components::CollisionWaveSpawnSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &spawns = scene.GetComponents<Client::Components::CollisionWaveSpawn>();
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
  auto &sender =
      scene.GetComponents<Client::Components::SendPacket>()[scene.GetEntity(
          "sender")];
  auto &isNetwork =
      scene.GetComponents<Rtype::Components::IsNetwork>()[scene.GetEntity(
          "network")];
  auto name = core.GetActualSceneName();
  auto &factory =
      scene.GetComponents<Rtype::Addons::CollisionFactory>()[scene.GetEntity(
          "collision-factory")];
  if (!factory.has_value() || networkId.has_value())
    return;
  auto max = spawns.size();
  for (size_t i = 0; i < max; i++) {
    auto &spawn = spawns[i];
    auto currentTime = core.deltaTime;
    if (!spawn.has_value())
      continue;
    if (spawn->actualDuration > spawn->durationWave)
      continue;
    if (!spawn->started) {
      spawn->lastUpdate = spawn->lastUpdate + currentTime;
      if (spawn->lastUpdate > spawn->startSpawn)
        spawn->started = true;
    } else {
      spawn->lastUpdate = spawn->lastUpdate + currentTime;
      spawn->actualDuration = spawn->actualDuration + currentTime;
    }
    if (!spawn->started || spawn->lastUpdate < spawn->frequence / 1000)
      continue;
    spawn->lastUpdate = 0;
    auto collisionType = COLLISION_TYPE_1;
    if (spawn->collisionsType.size() > 0) {
      std::random_device rd;
      std::mt19937 rng(rd());
      std::uniform_int_distribution<int> distribution(
          0, spawn->collisionsType.size() - 1);
      int randomValue = distribution(rng);
      collisionType = spawn->collisionsType.at(randomValue);
    }
    float y = rand() % 1080 + 1;
    if (isNetwork.has_value() && sender.has_value()) {
      sender->packets.push_back(
          {"CREATE_COLLIDER",
           std::to_string(i) + ":" + std::to_string(1920) + ":" +
               std::to_string(y) + ":" +
               Rtype::Addons::getCollisionTypeString(collisionType)});
    }
    factory->creationRequests.push_back(
        Rtype::Addons::CollisionCreationRequest::createCollisionCreationRequest(
            i, 1920, y, collisionType,
            [&core](RNGine::Core &c, RNGine::Scene::Entity &collision,
                    std::map<std::string, ValueCollision> &collisionInfo) {}));
  }
}
