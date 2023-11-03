#include "RNGine/addons/EnemyShoot.hpp"
#include "RNGine/Scene.hpp"
#include "RNGine/addons/destroyLimit.hpp"
#include "RNGine/components/Damages.hpp"
#include "RNGine/components/MakeDamage.hpp"
#include <iostream>

void RNGine::Addons::EnemyShootSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &spawns = scene.GetComponents<RNGine::Addons::EnemyShoot>();
  auto &transforms = scene.GetComponents<RNGine::Components::Transform>();
  auto &damages = scene.GetComponents<RNGine::Components::Damages>();
  auto name = core.GetActualSceneName();
  if (name == "home" || name == "lobby" || name == "victory" ||
      name == "gameOver" || name == "LevelSelect")
    return;
  auto max = spawns.size();
  for (size_t i = 0; i < max; i++) {
    auto &spawn = spawns[i];
    auto &transform = transforms[i];
    auto currentTime = core.deltaTime;
    if (!spawn.has_value() || !transform.has_value() || !damages[i].has_value())
      continue;
    spawn->lastUpdate = spawn->lastUpdate + currentTime;
    if (spawn->lastUpdate < spawn->frequence / 1000)
      continue;
    spawn->lastUpdate = 0;
    auto entity = scene.CreateEntity();
    scene.AddComponent<RNGine::Components::Transform>(
        entity, {transform->x + spawn->offset.first,
                 transform->y + spawn->offset.second, 0, spawn->scale.first,
                 spawn->scale.second});
    scene.AddComponent(entity, RNGine::Components::Hitbox(spawn->hitbox));
    scene.AddComponent(entity,
                       RNGine::Addons::Collider({spawn->colliderShoot.first,
                                                 spawn->colliderShoot.second}));
    scene.AddComponent(entity, RNGine::Addons::Velocity(spawn->velocity));
    scene.AddComponent<RNGine::Components::MakeDamage>(
        entity, {damages[i]->damages, false, i, spawn->bulletSprite,
                 spawn->sourceFirst, spawn->sourceSecond, spawn->shootSound,
                 spawn->shootSoundVolume, spawn->shootAnimationValue});
    scene.AddComponent<RNGine::Addons::destroyLimit>(
        entity, {spawn->destroyPosition.first, spawn->destroyPosition.second});
  }
}
