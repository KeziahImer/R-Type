#include "addons/CollisionWaveSpawn.hpp"
#include "RNGine/Scene.hpp"
#include "Rtype/addons/CollisionFactory.hpp"
#include "scenes/Game.hpp"
#include <iostream>
#include <random>

void Client::Components::CollisionWaveSpawnSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &spawns = scene.GetComponents<Client::Components::CollisionWaveSpawn>();
  auto name = core.GetActualSceneName();
  auto &factory =
      scene.GetComponents<Rtype::Addons::CollisionFactory>()[scene.GetEntity(
          "collision-factory")];
  if (!factory.has_value())
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
    factory->creationRequests.push_back(
        Rtype::Addons::CollisionCreationRequest::createCollisionCreationRequest(
            i, 1920, rand() % 1080 + 1, collisionType,
            [&core](RNGine::Core &c, RNGine::Scene::Entity &collision,
                    std::map<std::string, ValueCollision> &collisionInfo) {
              Client::Scenes::Game::ApplyCollisionTexture(c, collision, collisionInfo);
            }));
  }
}
