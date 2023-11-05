#include "Rtype/addons/EnemyWaveSpawn.hpp"
#include "RNGine/Scene.hpp"
#include "Rtype/addons/EnemyFactory.hpp"
#include "Rtype/addons/IsNetwork.hpp"
#include "Rtype/addons/NetworkId.hpp"
#include "Rtype/addons/SendPacket.hpp"
#include <iostream>
#include <random>

void Client::Components::EnemyWaveSpawnSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &spawns = scene.GetComponents<Client::Components::EnemyWaveSpawn>();
  auto name = core.GetActualSceneName();
  auto &factory =
      scene.GetComponents<Rtype::Addons::EnemyFactory>()[scene.GetEntity(
          "enemy-factory")];
  auto &isNetwork =
      scene.GetComponents<Rtype::Components::IsNetwork>()[scene.GetEntity(
          "network")];
  auto &sender =
      scene.GetComponents<Client::Components::SendPacket>()[scene.GetEntity(
          "sender")];
  auto &networkId =
      scene.GetComponents<Rtype::Components::networkId>()[scene.GetEntity(
          "networkId")];
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
    auto enemyType = ENEMY_TYPE_1;
    if (spawn->enemiesType.size() > 0) {
      std::random_device rd;
      std::mt19937 rng(rd());
      std::uniform_int_distribution<int> distribution(
          0, spawn->enemiesType.size() - 1);
      int randomValue = distribution(rng);
      enemyType = spawn->enemiesType.at(randomValue);
    }
    float y = rand() % 1080 + 1;
    std::string name = "enemy-" + std::to_string(factory->ships.size());
    if (isNetwork.has_value() && sender.has_value()) {
      std::cout << "CREATE_ENEMY: " + name + ":" + std::to_string(1920) + ":" +
                       std::to_string(y) + ":" + std::to_string(0)
                << std::endl;
      sender->packets.push_back(
          {"CREATE_ENEMY", name + ":" + std::to_string(1920) + ":" +
                               std::to_string(y) + ":" +
                               Rtype::Addons::getEntityTypeString(enemyType)});
    }
    factory->creationRequests.push_back(
        Rtype::Addons::EnemyCreationRequest::createShipCreationRequest(
            i, 1920, y, enemyType, name));
  }
}
