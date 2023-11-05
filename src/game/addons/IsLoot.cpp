#include "Rtype/addons/IsLoot.hpp"
#include "RNGine/addons/Acceleration.hpp"
#include "RNGine/addons/Collider.hpp"
#include "RNGine/components/Attackable.hpp"
#include "RNGine/components/Damages.hpp"
#include "RNGine/components/Score.hpp"
#include "Rtype/addons/LootableEntity.hpp"
#include "Rtype/addons/ShipController.hpp"
#include "Rtype/addons/ShipFactory.hpp"

#include <iostream>

void Rtype::Addons::IsLootSystem(RNGine::Core &core) {
  auto &scene = core.GetActualScene();
  auto &loots = scene.GetComponents<Rtype::Addons::IsLoot>();
  auto &scores = scene.GetComponents<RNGine::Components::Score>();
  auto &colliders = scene.GetComponents<RNGine::Addons::Collider>();
  auto &attackables = scene.GetComponents<RNGine::Components::Attackable>();
  auto &damages = scene.GetComponents<RNGine::Components::Damages>();

  for (int i = 0; i < scores.size(); i++) {
    if (!scores[i].has_value() || !colliders[i].has_value())
      continue;
    for (int x = 0; x < loots.size(); x++) {
      if (!colliders[x].has_value() || !loots[x].has_value())
        continue;
      for (auto col : colliders[i]->collisions) {
        if (col == x) {
          if (!loots[x].has_value())
            continue;
          if (loots[x]->type == Components::HEAL) {
            if (!attackables[i].has_value())
              continue;
            attackables[i]->health = attackables[i]->health + loots[x]->value;
          }
          if (loots[x]->type == Components::ATTACKUP) {
            if (!damages[i].has_value() || !scores[i].has_value())
              continue;
            damages[i]->damages = damages[i]->damages + loots[x]->value;
            scores[i]->numberPowerUp += 1;
          }
          scene.RemoveEntity(x);
        }
      }
    }
  }
}